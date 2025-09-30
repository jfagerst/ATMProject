/********************************************************************************
** Form generated from reading UI file 'nosto.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTO_H
#define UI_NOSTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nosto
{
public:
    QPushButton *btnDebit;
    QPushButton *btnCredit;
    QLabel *labelNosto;
    QPushButton *btn4;
    QPushButton *btn7;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn8;
    QPushButton *btnClear;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn9;
    QPushButton *btn0;
    QPushButton *btn1;
    QPlainTextEdit *txtSyotaSumma;
    QLineEdit *lineEditNostettavaSumma;
    QPushButton *btnKirjauduUlos;
    QPushButton *pushButton;

    void setupUi(QWidget *Nosto)
    {
        if (Nosto->objectName().isEmpty())
            Nosto->setObjectName("Nosto");
        Nosto->resize(453, 518);
        btnDebit = new QPushButton(Nosto);
        btnDebit->setObjectName("btnDebit");
        btnDebit->setGeometry(QRect(90, 330, 111, 91));
        btnCredit = new QPushButton(Nosto);
        btnCredit->setObjectName("btnCredit");
        btnCredit->setGeometry(QRect(250, 330, 111, 91));
        labelNosto = new QLabel(Nosto);
        labelNosto->setObjectName("labelNosto");
        labelNosto->setGeometry(QRect(110, 420, 231, 71));
        btn4 = new QPushButton(Nosto);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(100, 169, 80, 40));
        btn7 = new QPushButton(Nosto);
        btn7->setObjectName("btn7");
        btn7->setGeometry(QRect(100, 218, 80, 40));
        btn2 = new QPushButton(Nosto);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(185, 120, 80, 40));
        btn3 = new QPushButton(Nosto);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(270, 120, 80, 40));
        btn8 = new QPushButton(Nosto);
        btn8->setObjectName("btn8");
        btn8->setGeometry(QRect(185, 218, 80, 40));
        btnClear = new QPushButton(Nosto);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(100, 267, 80, 40));
        btn5 = new QPushButton(Nosto);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(185, 169, 80, 40));
        btn6 = new QPushButton(Nosto);
        btn6->setObjectName("btn6");
        btn6->setGeometry(QRect(270, 169, 80, 40));
        btn9 = new QPushButton(Nosto);
        btn9->setObjectName("btn9");
        btn9->setGeometry(QRect(270, 218, 80, 40));
        btn0 = new QPushButton(Nosto);
        btn0->setObjectName("btn0");
        btn0->setGeometry(QRect(185, 267, 80, 40));
        btn1 = new QPushButton(Nosto);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(100, 120, 80, 40));
        btn1->setFocusPolicy(Qt::NoFocus);
        txtSyotaSumma = new QPlainTextEdit(Nosto);
        txtSyotaSumma->setObjectName("txtSyotaSumma");
        txtSyotaSumma->setGeometry(QRect(70, 30, 311, 31));
        lineEditNostettavaSumma = new QLineEdit(Nosto);
        lineEditNostettavaSumma->setObjectName("lineEditNostettavaSumma");
        lineEditNostettavaSumma->setGeometry(QRect(100, 70, 241, 31));
        lineEditNostettavaSumma->setFocusPolicy(Qt::NoFocus);
        lineEditNostettavaSumma->setInputMethodHints(Qt::ImhNone);
        btnKirjauduUlos = new QPushButton(Nosto);
        btnKirjauduUlos->setObjectName("btnKirjauduUlos");
        btnKirjauduUlos->setGeometry(QRect(350, 470, 80, 24));
        pushButton = new QPushButton(Nosto);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 470, 80, 24));

        retranslateUi(Nosto);

        QMetaObject::connectSlotsByName(Nosto);
    } // setupUi

    void retranslateUi(QWidget *Nosto)
    {
        Nosto->setWindowTitle(QCoreApplication::translate("Nosto", "Form", nullptr));
        btnDebit->setText(QCoreApplication::translate("Nosto", "Debit", nullptr));
        btnCredit->setText(QCoreApplication::translate("Nosto", "Credit", nullptr));
        labelNosto->setText(QCoreApplication::translate("Nosto", "TextLabel", nullptr));
        btn4->setText(QCoreApplication::translate("Nosto", "4", nullptr));
        btn7->setText(QCoreApplication::translate("Nosto", "7", nullptr));
        btn2->setText(QCoreApplication::translate("Nosto", "2", nullptr));
        btn3->setText(QCoreApplication::translate("Nosto", "3", nullptr));
        btn8->setText(QCoreApplication::translate("Nosto", "8", nullptr));
        btnClear->setText(QCoreApplication::translate("Nosto", "C", nullptr));
        btn5->setText(QCoreApplication::translate("Nosto", "5", nullptr));
        btn6->setText(QCoreApplication::translate("Nosto", "6", nullptr));
        btn9->setText(QCoreApplication::translate("Nosto", "9", nullptr));
        btn0->setText(QCoreApplication::translate("Nosto", "0", nullptr));
        btn1->setText(QCoreApplication::translate("Nosto", "1", nullptr));
        txtSyotaSumma->setPlainText(QCoreApplication::translate("Nosto", "Sy\303\266t\303\244 nostettava summa, ja valitse Debit tai Credit", nullptr));
        btnKirjauduUlos->setText(QCoreApplication::translate("Nosto", "Kirjaudu ulos", nullptr));
        pushButton->setText(QCoreApplication::translate("Nosto", "Palaa takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nosto: public Ui_Nosto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTO_H
