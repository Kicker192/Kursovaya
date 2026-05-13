/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QFrame *line_1;
    QPushButton *btnSum;
    QPushButton *btnMean;
    QPushButton *btnSko;
    QPushButton *btnMed;
    QFrame *line_2;
    QLabel *labelQuantile;
    QLineEdit *lineQuantile;
    QPushButton *btnQuantRun;
    QFrame *line_3;
    QPushButton *btnUp;
    QPushButton *btnLow;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnShowChart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow { background-color: #1a1c1e; }\n"
"    QTableWidget {\n"
"        background-color: #212327;\n"
"        border: 1px solid #32363c;\n"
"        gridline-color: #2d3137;\n"
"        selection-background-color: #3498db;\n"
"        selection-color: white;\n"
"        outline: none;\n"
"        font-family: 'Segoe UI', sans-serif;\n"
"        font-size: 13px;\n"
"        color: #cfd8dc;\n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: #2d3137;\n"
"        color: #90a4ae;\n"
"        padding: 6px;\n"
"        border: 1px solid #1a1c1e;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #2d3137;\n"
"        border: 1px solid #42464d;\n"
"        border-radius: 4px;\n"
"        color: #eceff1;\n"
"        padding: 6px 12px;\n"
"        font-family: 'Segoe UI', sans-serif;\n"
"        font-size: 12px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #3d424a;\n"
"        border-color: #3498db;\n"
"    }\n"
"    QPus"
                        "hButton:pressed {\n"
"        background-color: #1a1c1e;\n"
"    }\n"
"    QPushButton#btnShowChart {\n"
"        background-color: #2e7d32;\n"
"        border-color: #388e3c;\n"
"        color: white;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton#btnShowChart:hover {\n"
"        background-color: #388e3c;\n"
"    }\n"
"    QLabel {\n"
"        color: #cfd8dc;\n"
"        font-family: 'Segoe UI', sans-serif;\n"
"        font-size: 12px;\n"
"    }\n"
"    QLineEdit {\n"
"        background-color: #212327;\n"
"        border: 1px solid #42464d;\n"
"        border-radius: 3px;\n"
"        padding: 4px;\n"
"        color: #cfd8dc;\n"
"        font-family: 'Segoe UI', sans-serif;\n"
"        font-size: 12px;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border-color: #3498db;\n"
"    }\n"
"    QStatusBar {\n"
"        color: #90a4ae;\n"
"        background-color: #1a1c1e;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setRowCount(100);
        tableWidget->setColumnCount(50);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        btnOpen = new QPushButton(centralwidget);
        btnOpen->setObjectName("btnOpen");

        horizontalLayout->addWidget(btnOpen);

        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        line_1 = new QFrame(centralwidget);
        line_1->setObjectName("line_1");
        line_1->setFrameShape(QFrame::Shape::VLine);
        line_1->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line_1);

        btnSum = new QPushButton(centralwidget);
        btnSum->setObjectName("btnSum");

        horizontalLayout->addWidget(btnSum);

        btnMean = new QPushButton(centralwidget);
        btnMean->setObjectName("btnMean");

        horizontalLayout->addWidget(btnMean);

        btnSko = new QPushButton(centralwidget);
        btnSko->setObjectName("btnSko");

        horizontalLayout->addWidget(btnSko);

        btnMed = new QPushButton(centralwidget);
        btnMed->setObjectName("btnMed");

        horizontalLayout->addWidget(btnMed);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line_2);

        labelQuantile = new QLabel(centralwidget);
        labelQuantile->setObjectName("labelQuantile");

        horizontalLayout->addWidget(labelQuantile);

        lineQuantile = new QLineEdit(centralwidget);
        lineQuantile->setObjectName("lineQuantile");
        lineQuantile->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(lineQuantile);

        btnQuantRun = new QPushButton(centralwidget);
        btnQuantRun->setObjectName("btnQuantRun");

        horizontalLayout->addWidget(btnQuantRun);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line_3);

        btnUp = new QPushButton(centralwidget);
        btnUp->setObjectName("btnUp");

        horizontalLayout->addWidget(btnUp);

        btnLow = new QPushButton(centralwidget);
        btnLow->setObjectName("btnLow");

        horizontalLayout->addWidget(btnLow);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnShowChart = new QPushButton(centralwidget);
        btnShowChart->setObjectName("btnShowChart");

        horizontalLayout->addWidget(btnShowChart);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CSV \320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\321\211\320\270\320\272", nullptr));
        btnOpen->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202 \320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        btnOpen->setToolTip(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 CSV \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSave->setText(QCoreApplication::translate("MainWindow", "\360\237\222\276 \320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        btnSave->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 CSV \320\270\320\273\320\270 Excel", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSum->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
#if QT_CONFIG(tooltip)
        btnSum->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\321\205 \321\207\320\270\321\201\320\265\320\273", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMean->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
#if QT_CONFIG(tooltip)
        btnMean->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\260\321\200\320\270\321\204\320\274\320\265\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSko->setText(QCoreApplication::translate("MainWindow", "\320\241\320\232\320\236", nullptr));
#if QT_CONFIG(tooltip)
        btnSko->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\276\321\202\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMed->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\264\320\270\320\260\320\275\320\260", nullptr));
#if QT_CONFIG(tooltip)
        btnMed->setToolTip(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\264\320\270\320\260\320\275\320\260 \320\262\321\213\320\261\320\276\321\200\320\272\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        labelQuantile->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\275\321\202\320\270\320\273\321\214:", nullptr));
        lineQuantile->setText(QCoreApplication::translate("MainWindow", "0.5", nullptr));
#if QT_CONFIG(tooltip)
        lineQuantile->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\276\321\202 0 \320\264\320\276 1", nullptr));
#endif // QT_CONFIG(tooltip)
        btnQuantRun->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\265\321\202", nullptr));
#if QT_CONFIG(tooltip)
        btnQuantRun->setToolTip(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\272\320\262\320\260\320\275\321\202\320\270\320\273\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        btnUp->setText(QCoreApplication::translate("MainWindow", "Aa \342\206\221", nullptr));
#if QT_CONFIG(tooltip)
        btnUp->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\262 \320\262\320\265\321\200\321\205\320\275\320\270\320\271 \321\200\320\265\320\263\320\270\321\201\321\202\321\200", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLow->setText(QCoreApplication::translate("MainWindow", "aa \342\206\223", nullptr));
#if QT_CONFIG(tooltip)
        btnLow->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\262 \320\275\320\270\320\266\320\275\320\270\320\271 \321\200\320\265\320\263\320\270\321\201\321\202\321\200", nullptr));
#endif // QT_CONFIG(tooltip)
        btnShowChart->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
#if QT_CONFIG(tooltip)
        btnShowChart->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 \320\277\320\276 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\274 \320\264\320\260\320\275\320\275\321\213\320\274", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
