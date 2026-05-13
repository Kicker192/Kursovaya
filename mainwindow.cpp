#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QHeaderView>
#include <QDir>
#include <cmath>
#include <algorithm>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

//Конструктор главного окна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setColumnCount(50);

    //Подключение сигналов к слотам
    connect(ui->btnOpen, &QPushButton::clicked, this, &MainWindow::onLoadCsv);
    connect(ui->btnSave, &QPushButton::clicked, this, &MainWindow::onSaveData);
    connect(ui->btnSum, &QPushButton::clicked, this, &MainWindow::onCalculateSum);
    connect(ui->btnMean, &QPushButton::clicked, this, &MainWindow::onCalculateMean);
    connect(ui->btnSko, &QPushButton::clicked, this, &MainWindow::onCalculateSKO);
    connect(ui->btnMed, &QPushButton::clicked, this, &MainWindow::onCalculateMedian);
    connect(ui->btnQuantRun, &QPushButton::clicked, this, &MainWindow::onCalculateQuantile);
    connect(ui->btnUp, &QPushButton::clicked, this, &MainWindow::onTextToUpper);
    connect(ui->btnLow, &QPushButton::clicked, this, &MainWindow::onTextToLower);
    connect(ui->btnShowChart, &QPushButton::clicked, this, &MainWindow::onShowChart);
    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::onCellChanged);
    connect(ui->lineQuantile, &QLineEdit::textChanged, this, &MainWindow::onQuantileInputChanged);

    ui->lineQuantile->setText("0.5");
    ui->statusbar->showMessage("Приложение запущено", 3000);
}

//Деструктор
MainWindow::~MainWindow()
{
    delete ui;
}

//Вывод сообщения в статусбар
void MainWindow::logStatus(const QString &message) const
{
    ui->statusbar->showMessage(message, 3000);
}

//Проверка, есть ли данные в ячейке
bool MainWindow::hasValidData(int row, int column) const
{
    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    if (!item) return false;
    if (item->text().trimmed().isEmpty()) return false;
    return true;
}

//Преобразование строки в число (замена запятой на точку)
double MainWindow::stringToDouble(const QString &s, bool *ok) const
{
    QString temp = s;
    temp.replace(",", ".");
    return temp.toDouble(ok);
}

//Сбор всех чисел из выделенных ячеек
std::vector<double> MainWindow::getSelectedNumbers() const
{
    std::vector<double> result;
    auto selection = ui->tableWidget->selectedItems();

    for (auto item : selection) {
        bool ok;
        double val = stringToDouble(item->text(), &ok);
        if (ok) {
            result.push_back(val);
        }
    }
    return result;
}

//Открытие диалога выбора CSV файла
void MainWindow::onLoadCsv()
{
    logStatus("Загрузка файла...");
    QString filter = "CSV Files (*.csv);;Text Files (*.txt);;All Files (*.*)";
    QString path = QFileDialog::getOpenFileName(this, "Выбрать файл для импорта", "", filter);

    if (path.isEmpty()) {
        logStatus("Загрузка отменена");
        return;
    }
    loadCsvData(path);
}

//Загрузка и парсинг CSV файла
void MainWindow::loadCsvData(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Невозможно прочитать файл!");
        return;
    }

    logStatus("Файл открыт");
    ui->tableWidget->clearContents();

    QTextStream ts(&file);
    int tableRow = 0;

    while (!ts.atEnd()) {
        QString currentLine = ts.readLine();
        if (currentLine.isEmpty()) continue;

        QStringList columns = currentLine.split(",");

        //Автоматическое расширение таблицы
        if (tableRow >= ui->tableWidget->rowCount()) {
            ui->tableWidget->setRowCount(tableRow + 10);
        }

        for (int i = 0; i < columns.size(); i++) {
            if (i < ui->tableWidget->columnCount()) {
                QTableWidgetItem *item = new QTableWidgetItem(columns[i].trimmed());
                ui->tableWidget->setItem(tableRow, i, item);
            }
        }
        tableRow++;
    }

    file.close();
    logStatus("Загружено строк: " + QString::number(tableRow));
}

//Сохранение данных (выбор формата)
void MainWindow::onSaveData()
{
    logStatus("Экспорт данных...");

#ifdef HAS_AXCONTAINER
    QString filters = "CSV файл (*.csv);;Excel документ (*.xlsx)";
#else
    QString filters = "CSV файл (*.csv)";
#endif

    QString selectedFilter;
    QString path = QFileDialog::getSaveFileName(this, "Сохранить таблицу", "", filters, &selectedFilter);

    if (path.isEmpty()) return;

#ifdef HAS_AXCONTAINER
    if (selectedFilter.contains(".xlsx")) {
        executeSaveExcel(path);
    } else {
        executeSaveCsv(path);
    }
#else
    executeSaveCsv(path);
#endif
}

//Экспорт в CSV
void MainWindow::executeSaveCsv(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Невозможно сохранить файл!");
        return;
    }

    QTextStream out(&file);
    out.setGenerateByteOrderMark(true);

    int exportRows = 0;
    for (int r = 0; r < ui->tableWidget->rowCount(); r++) {
        int lastColumnWithData = -1;
        for (int c = 0; c < ui->tableWidget->columnCount(); c++) {
            if (hasValidData(r, c)) lastColumnWithData = c;
        }

        if (lastColumnWithData == -1) continue;

        QStringList line;
        for (int c = 0; c <= lastColumnWithData; c++) {
            QString text = ui->tableWidget->item(r, c) ? ui->tableWidget->item(r, c)->text() : "";
            //Экранирование кавычек и запятых
            if (text.contains(",") || text.contains("\"") || text.contains("\n")) {
                text = "\"" + text.replace("\"", "\"\"") + "\"";
            }
            line << text;
        }

        out << line.join(",") << "\n";
        exportRows++;
    }
    file.close();
    logStatus("Сохранено строк: " + QString::number(exportRows));
}

//Вычисление суммы выделенных чисел
void MainWindow::onCalculateSum()
{
    logStatus("Расчет суммы...");
    auto numbers = getSelectedNumbers();

    if (numbers.empty()) {
        QMessageBox::warning(this, "Нет данных", "Выделите ячейки с числами");
        return;
    }

    double total = 0;
    for (double v : numbers) total += v;

    QMessageBox::information(this, "Сумма",
                             "Сумма: " + QString::number(total) +
                                 "\nЯчеек: " + QString::number(numbers.size()));
}

//Вычисление среднего арифметического
void MainWindow::onCalculateMean()
{
    logStatus("Расчет среднего...");
    auto numbers = getSelectedNumbers();

    if (numbers.empty()) {
        QMessageBox::warning(this, "Нет данных", "Выделите ячейки с числами");
        return;
    }

    double sum = 0;
    for (double v : numbers) sum += v;

    QMessageBox::information(this, "Среднее",
                             "Среднее: " + QString::number(sum / numbers.size()));
}

//Вычисление среднеквадратического отклонения
void MainWindow::onCalculateSKO()
{
    logStatus("Расчет СКО...");
    auto numbers = getSelectedNumbers();

    if (numbers.size() < 2) {
        QMessageBox::warning(this, "Мало данных", "Нужно минимум 2 числа");
        return;
    }

    double sum = 0;
    for (double x : numbers) sum += x;
    double mean = sum / numbers.size();

    double varSum = 0;
    for (double x : numbers) varSum += pow(x - mean, 2);

    double sko = sqrt(varSum / numbers.size());
    QMessageBox::information(this, "СКО",
                             "СКО: " + QString::number(sko));
}

//Вычисление медианы
void MainWindow::onCalculateMedian()
{
    logStatus("Расчет медианы...");
    auto numbers = getSelectedNumbers();

    if (numbers.empty()) {
        QMessageBox::warning(this, "Нет данных", "Выделите ячейки с числами");
        return;
    }

    std::sort(numbers.begin(), numbers.end());

    double median;
    size_t sz = numbers.size();
    if (sz % 2 == 0) {
        median = (numbers[sz/2 - 1] + numbers[sz/2]) / 2.0;
    } else {
        median = numbers[sz/2];
    }

    QMessageBox::information(this, "Медиана",
                             "Медиана: " + QString::number(median));
}

//Вычисление квантиля
void MainWindow::onCalculateQuantile()
{
    logStatus("Расчет квантиля...");
    bool inputOk;
    double p = ui->lineQuantile->text().toDouble(&inputOk);

    if (!inputOk || p < 0 || p > 1) {
        QMessageBox::critical(this, "Ошибка", "Введите число от 0 до 1");
        return;
    }

    auto numbers = getSelectedNumbers();

    if (numbers.empty()) {
        QMessageBox::warning(this, "Нет данных", "Выделите ячейки с числами");
        return;
    }

    std::sort(numbers.begin(), numbers.end());

    int position = static_cast<int>(p * (numbers.size() - 1));
    QMessageBox::information(this, "Квантиль",
                             "Квантиль " + QString::number(p) +
                                 ": " + QString::number(numbers[position]));
}

//Перевод текста в верхний регистр
void MainWindow::onTextToUpper()
{
    logStatus("Верхний регистр");
    auto selection = ui->tableWidget->selectedItems();
    for (auto item : selection) {
        item->setText(item->text().toUpper());
    }
}

//Перевод текста в нижний регистр
void MainWindow::onTextToLower()
{
    logStatus("Нижний регистр");
    auto selection = ui->tableWidget->selectedItems();
    for (auto item : selection) {
        item->setText(item->text().toLower());
    }
}

//Построение графика по выделенным данным
void MainWindow::onShowChart()
{
    logStatus("Построение графика...");
    auto ranges = ui->tableWidget->selectedRanges();
    if (ranges.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выделите область данных");
        return;
    }

    //Выбор ориентации: по строкам или по столбцам
    QMessageBox dialog(this);
    dialog.setWindowTitle("Опции");
    dialog.setText("Ориентация данных:");

    dialog.addButton("По столбцам", QMessageBox::ActionRole);
    dialog.addButton("По строкам", QMessageBox::ActionRole);
    dialog.addButton("Отмена", QMessageBox::RejectRole);
    dialog.exec();

    QAbstractButton *clickedButton = dialog.clickedButton();
    if (clickedButton == nullptr || dialog.result() == QMessageBox::Rejected) return;

    bool isByRows = (clickedButton->text() == "По строкам");

    QChart *chartObj = new QChart();
    chartObj->setTitle("График данных");
    chartObj->setTheme(QChart::ChartThemeDark);
    chartObj->setAnimationOptions(QChart::SeriesAnimations);

    QTableWidgetSelectionRange range = ranges.first();
    bool hasData = false;

    //Построение по строкам
    if (isByRows) {
        for (int r = range.topRow(); r <= range.bottomRow(); r++) {
            QLineSeries *series = new QLineSeries();
            series->setName("Строка " + QString::number(r + 1));
            for (int c = range.leftColumn(); c <= range.rightColumn(); c++) {
                if (hasValidData(r, c)) {
                    bool ok;
                    double val = stringToDouble(ui->tableWidget->item(r, c)->text(), &ok);
                    if (ok) {
                        series->append(c - range.leftColumn() + 1, val);
                        hasData = true;
                    }
                }
            }
            if (series->count() > 0) chartObj->addSeries(series);
            else delete series;
        }
    }
    //Построение по столбцам
    else {
        for (int c = range.leftColumn(); c <= range.rightColumn(); c++) {
            QLineSeries *series = new QLineSeries();
            QString label = ui->tableWidget->horizontalHeaderItem(c)
                                ? ui->tableWidget->horizontalHeaderItem(c)->text()
                                : "Кол. " + QString::number(c + 1);
            series->setName(label);
            for (int r = range.topRow(); r <= range.bottomRow(); r++) {
                if (hasValidData(r, c)) {
                    bool ok;
                    double val = stringToDouble(ui->tableWidget->item(r, c)->text(), &ok);
                    if (ok) {
                        series->append(r - range.topRow() + 1, val);
                        hasData = true;
                    }
                }
            }
            if (series->count() > 0) chartObj->addSeries(series);
            else delete series;
        }
    }

    if (!hasData) {
        QMessageBox::warning(this, "Ошибка", "Нет числовых данных!");
        delete chartObj;
        return;
    }

    chartObj->createDefaultAxes();
    QChartView *chartViewWindow = new QChartView(chartObj);
    chartViewWindow->setRenderHint(QPainter::Antialiasing);
    chartViewWindow->setWindowTitle("График");
    chartViewWindow->resize(1100, 700);
    chartViewWindow->setAttribute(Qt::WA_DeleteOnClose);
    chartViewWindow->show();
    logStatus("График построен");
}

//Автоматическое расширение таблицы при редактировании
void MainWindow::onCellChanged(int row, int column)
{
    if (row >= ui->tableWidget->rowCount() - 3) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 10);
    }
    if (column >= ui->tableWidget->columnCount() - 2) {
        ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() + 5);
    }
}

//Валидация ввода квантиля (подсветка при ошибке)
void MainWindow::onQuantileInputChanged(const QString &text)
{
    bool ok;
    double val = text.toDouble(&ok);
    if (ok && val >= 0 && val <= 1) {
        ui->lineQuantile->setStyleSheet("");
    } else {
        ui->lineQuantile->setStyleSheet("QLineEdit { background-color: #ffcccc; }");
    }
}