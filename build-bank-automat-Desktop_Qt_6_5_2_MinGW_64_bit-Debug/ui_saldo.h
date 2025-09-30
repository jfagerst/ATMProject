/********************************************************************************
** Form generated from reading UI file 'saldo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDO_H
#define UI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Saldo
{
public:
    QLabel *labelSaldoData;
    QPushButton *btnShowSaldo;
    QPushButton *btnKirjauduUlos;
    QPushButton *btntakaisin;
    QPushButton *btnShowCredit;

    void setupUi(QDialog *Saldo)
    {
        if (Saldo->objectName().isEmpty())
            Saldo->setObjectName("Saldo");
        Saldo->resize(400, 300);
        labelSaldoData = new QLabel(Saldo);
        labelSaldoData->setObjectName("labelSaldoData");
        labelSaldoData->setGeometry(QRect(90, 30, 221, 101));
        QFont font;
        font.setPointSize(12);
        labelSaldoData->setFont(font);
        btnShowSaldo = new QPushButton(Saldo);
        btnShowSaldo->setObjectName("btnShowSaldo");
        btnShowSaldo->setGeometry(QRect(40, 160, 131, 51));
        btnKirjauduUlos = new QPushButton(Saldo);
        btnKirjauduUlos->setObjectName("btnKirjauduUlos");
        btnKirjauduUlos->setGeometry(QRect(270, 250, 80, 24));
        btntakaisin = new QPushButton(Saldo);
        btntakaisin->setObjectName("btntakaisin");
        btntakaisin->setGeometry(QRect(40, 250, 80, 24));
        btnShowCredit = new QPushButton(Saldo);
        btnShowCredit->setObjectName("btnShowCredit");
        btnShowCredit->setGeometry(QRect(220, 160, 131, 51));

        retranslateUi(Saldo);

        QMetaObject::connectSlotsByName(Saldo);
    } // setupUi

    void retranslateUi(QDialog *Saldo)
    {
        Saldo->setWindowTitle(QCoreApplication::translate("Saldo", "Dialog", nullptr));
        labelSaldoData->setText(QString());
        btnShowSaldo->setText(QCoreApplication::translate("Saldo", "N\303\244yt\303\244 Saldo", nullptr));
        btnKirjauduUlos->setText(QCoreApplication::translate("Saldo", "Kirjaudu ulos", nullptr));
        btntakaisin->setText(QCoreApplication::translate("Saldo", "Palaa takaisin", nullptr));
        btnShowCredit->setText(QCoreApplication::translate("Saldo", "N\303\244yt\303\244 luottoraja", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Saldo: public Ui_Saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
