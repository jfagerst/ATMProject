/********************************************************************************
** Form generated from reading UI file 'loginwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW2_H
#define UI_LOGINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow2
{
public:
    QPushButton *btnEnter;
    QLineEdit *lineEditKortinNumero;
    QPushButton *btn4;
    QPushButton *btn9;
    QPushButton *btn3;
    QPushButton *btn8;
    QPushButton *btn0;
    QPushButton *btn6;
    QPushButton *btn2;
    QPushButton *btn5;
    QPushButton *btnClear;
    QPushButton *btn1;
    QPushButton *btn7;
    QTextEdit *textKortinNumero;
    QTextEdit *textPinkoodi;
    QLineEdit *lineEditPIN;
    QTextEdit *textKirjaudu;
    QLabel *labelInfo2;
    QPushButton *btnTakaisin;

    void setupUi(QWidget *loginwindow2)
    {
        if (loginwindow2->objectName().isEmpty())
            loginwindow2->setObjectName("loginwindow2");
        loginwindow2->resize(811, 594);
        btnEnter = new QPushButton(loginwindow2);
        btnEnter->setObjectName("btnEnter");
        btnEnter->setGeometry(QRect(381, 397, 80, 40));
        lineEditKortinNumero = new QLineEdit(loginwindow2);
        lineEditKortinNumero->setObjectName("lineEditKortinNumero");
        lineEditKortinNumero->setGeometry(QRect(220, 130, 231, 31));
        lineEditKortinNumero->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        lineEditKortinNumero->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        btn4 = new QPushButton(loginwindow2);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(211, 299, 80, 40));
        btn9 = new QPushButton(loginwindow2);
        btn9->setObjectName("btn9");
        btn9->setGeometry(QRect(381, 348, 80, 40));
        btn3 = new QPushButton(loginwindow2);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(381, 250, 80, 40));
        btn8 = new QPushButton(loginwindow2);
        btn8->setObjectName("btn8");
        btn8->setGeometry(QRect(296, 348, 80, 40));
        btn0 = new QPushButton(loginwindow2);
        btn0->setObjectName("btn0");
        btn0->setGeometry(QRect(296, 397, 80, 40));
        btn6 = new QPushButton(loginwindow2);
        btn6->setObjectName("btn6");
        btn6->setGeometry(QRect(381, 299, 80, 40));
        btn2 = new QPushButton(loginwindow2);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(296, 250, 80, 40));
        btn5 = new QPushButton(loginwindow2);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(296, 299, 80, 40));
        btnClear = new QPushButton(loginwindow2);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(211, 397, 80, 40));
        btn1 = new QPushButton(loginwindow2);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(211, 250, 80, 40));
        btn1->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        btn7 = new QPushButton(loginwindow2);
        btn7->setObjectName("btn7");
        btn7->setGeometry(QRect(211, 348, 80, 40));
        textKortinNumero = new QTextEdit(loginwindow2);
        textKortinNumero->setObjectName("textKortinNumero");
        textKortinNumero->setGeometry(QRect(90, 130, 121, 31));
        textKortinNumero->setReadOnly(true);
        textPinkoodi = new QTextEdit(loginwindow2);
        textPinkoodi->setObjectName("textPinkoodi");
        textPinkoodi->setGeometry(QRect(120, 170, 91, 31));
        textPinkoodi->setReadOnly(true);
        lineEditPIN = new QLineEdit(loginwindow2);
        lineEditPIN->setObjectName("lineEditPIN");
        lineEditPIN->setGeometry(QRect(220, 170, 231, 31));
        lineEditPIN->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        lineEditPIN->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        textKirjaudu = new QTextEdit(loginwindow2);
        textKirjaudu->setObjectName("textKirjaudu");
        textKirjaudu->setGeometry(QRect(90, 40, 191, 61));
        textKirjaudu->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        textKirjaudu->setReadOnly(true);
        labelInfo2 = new QLabel(loginwindow2);
        labelInfo2->setObjectName("labelInfo2");
        labelInfo2->setGeometry(QRect(220, 450, 351, 41));
        QFont font;
        font.setPointSize(12);
        labelInfo2->setFont(font);
        btnTakaisin = new QPushButton(loginwindow2);
        btnTakaisin->setObjectName("btnTakaisin");
        btnTakaisin->setGeometry(QRect(120, 470, 80, 24));

        retranslateUi(loginwindow2);

        QMetaObject::connectSlotsByName(loginwindow2);
    } // setupUi

    void retranslateUi(QWidget *loginwindow2)
    {
        loginwindow2->setWindowTitle(QCoreApplication::translate("loginwindow2", "Form", nullptr));
        btnEnter->setText(QCoreApplication::translate("loginwindow2", "Enter", nullptr));
        btn4->setText(QCoreApplication::translate("loginwindow2", "4", nullptr));
        btn9->setText(QCoreApplication::translate("loginwindow2", "9", nullptr));
        btn3->setText(QCoreApplication::translate("loginwindow2", "3", nullptr));
        btn8->setText(QCoreApplication::translate("loginwindow2", "8", nullptr));
        btn0->setText(QCoreApplication::translate("loginwindow2", "0", nullptr));
        btn6->setText(QCoreApplication::translate("loginwindow2", "6", nullptr));
        btn2->setText(QCoreApplication::translate("loginwindow2", "2", nullptr));
        btn5->setText(QCoreApplication::translate("loginwindow2", "5", nullptr));
        btnClear->setText(QCoreApplication::translate("loginwindow2", "C", nullptr));
        btn1->setText(QCoreApplication::translate("loginwindow2", "1", nullptr));
        btn7->setText(QCoreApplication::translate("loginwindow2", "7", nullptr));
        textKortinNumero->setHtml(QCoreApplication::translate("loginwindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Kortin numero:</span></p></body></html>", nullptr));
        textPinkoodi->setHtml(QCoreApplication::translate("loginwindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">PIN-koodi:</span></p></body></html>", nullptr));
        textKirjaudu->setHtml(QCoreApplication::translate("loginwindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Kirjaudu sis\303\244\303\244n</span></p></body></html>", nullptr));
        labelInfo2->setText(QString());
        btnTakaisin->setText(QCoreApplication::translate("loginwindow2", "Palaa takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow2: public Ui_loginwindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW2_H
