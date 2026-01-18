/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *inputPlate;
    QLabel *label_3;
    QComboBox *comboType;
    QPushButton *btnIn;
    QPushButton *btnOut;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(961, 563);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(510, 20, 211, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 60, 81, 20));
        inputPlate = new QLineEdit(centralwidget);
        inputPlate->setObjectName("inputPlate");
        inputPlate->setGeometry(QRect(530, 60, 113, 26));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 100, 63, 20));
        comboType = new QComboBox(centralwidget);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");
        comboType->setGeometry(QRect(530, 100, 81, 26));
        btnIn = new QPushButton(centralwidget);
        btnIn->setObjectName("btnIn");
        btnIn->setGeometry(QRect(430, 140, 93, 29));
        btnOut = new QPushButton(centralwidget);
        btnOut->setObjectName("btnOut");
        btnOut->setGeometry(QRect(550, 140, 171, 31));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(430, 210, 301, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 961, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "QU\341\272\242N L\303\235 B\303\203I XE TH\303\224NG MINH", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Bi\341\273\203n s\341\273\221 xe:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Lo\341\272\241i xe:", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("MainWindow", "Xe M\303\241y", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("MainWindow", "\303\224 T\303\264", nullptr));

        btnIn->setText(QCoreApplication::translate("MainWindow", "Cho xe v\303\240o", nullptr));
        btnOut->setText(QCoreApplication::translate("MainWindow", "Cho xe ra & T\303\255nh ti\341\273\201n", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "STT", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Bi\341\273\203n s\341\273\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Lo\341\272\241i xe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
