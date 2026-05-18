#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    //Файловые операции
    void onLoadCsv();
    void onSaveData();

    //Статистика
    void onCalculateSum();
    void onCalculateMean();
    void onCalculateSKO();
    void onCalculateMedian();
    void onCalculateQuantile();

    //Текст
    void onTextToUpper();
    void onTextToLower();

    //График
    void onShowChart();

    void onCellChanged(int row, int column);
    void onQuantileInputChanged(const QString &text);

private:
    Ui::MainWindow *ui;

    bool hasValidData(int row, int column) const;
    double stringToDouble(const QString &s, bool *ok) const;  //Замена запятой на точку
    void loadCsvData(const QString &path);
    void executeSaveCsv(const QString &path);
    void logStatus(const QString &message) const;
    std::vector<double> getSelectedNumbers() const;  //Сбор чисел из выделенных ячеек
};

#endif // MAINWINDOW_H