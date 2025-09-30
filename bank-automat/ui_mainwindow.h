/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textTervetuloa;
    QPushButton *btnPankkiautomaatti1;
    QPushButton *btnPankkiautomaatti2;
    QPushButton *btnAlkuruutuSulje;
    QMenuBar *menubar;
    QMenu *menuPankkiautomaatti;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textTervetuloa = new QTextEdit(centralwidget);
        textTervetuloa->setObjectName("textTervetuloa");
        textTervetuloa->setGeometry(QRect(260, 120, 251, 111));
        btnPankkiautomaatti1 = new QPushButton(centralwidget);
        btnPankkiautomaatti1->setObjectName("btnPankkiautomaatti1");
        btnPankkiautomaatti1->setGeometry(QRect(200, 320, 100, 50));
        QFont font;
        font.setPointSize(12);
        btnPankkiautomaatti1->setFont(font);
        btnPankkiautomaatti2 = new QPushButton(centralwidget);
        btnPankkiautomaatti2->setObjectName("btnPankkiautomaatti2");
        btnPankkiautomaatti2->setGeometry(QRect(480, 320, 100, 50));
        btnPankkiautomaatti2->setFont(font);
        btnAlkuruutuSulje = new QPushButton(centralwidget);
        btnAlkuruutuSulje->setObjectName("btnAlkuruutuSulje");
        btnAlkuruutuSulje->setGeometry(QRect(350, 460, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuPankkiautomaatti = new QMenu(menubar);
        menuPankkiautomaatti->setObjectName("menuPankkiautomaatti");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPankkiautomaatti->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textTervetuloa->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Tervetuloa!<br /><br />Valitse pankkiautomaatti</span></p></body></html>", nullptr));
        btnPankkiautomaatti1->setText(QCoreApplication::translate("MainWindow", "Automaatti 1", nullptr));
        btnPankkiautomaatti2->setText(QCoreApplication::translate("MainWindow", "Automaatti 2", nullptr));
        btnAlkuruutuSulje->setText(QCoreApplication::translate("MainWindow", "Sulje", nullptr));
        menuPankkiautomaatti->setTitle(QCoreApplication::translate("MainWindow", "Pankkiautomaatti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
