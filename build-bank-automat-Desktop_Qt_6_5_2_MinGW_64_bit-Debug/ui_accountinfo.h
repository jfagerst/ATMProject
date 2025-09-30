/********************************************************************************
** Form generated from reading UI file 'accountinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTINFO_H
#define UI_ACCOUNTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_accountInfo
{
public:
    QLabel *labelCardID;
    QPushButton *btnSaldo;
    QPushButton *btnNosto;
    QPushButton *btnKirjauduUlos;
    QPushButton *btnTapahtumat;

    void setupUi(QDialog *accountInfo)
    {
        if (accountInfo->objectName().isEmpty())
            accountInfo->setObjectName("accountInfo");
        accountInfo->resize(491, 524);
        labelCardID = new QLabel(accountInfo);
        labelCardID->setObjectName("labelCardID");
        labelCardID->setGeometry(QRect(50, 20, 201, 51));
        QFont font;
        font.setPointSize(12);
        labelCardID->setFont(font);
        btnSaldo = new QPushButton(accountInfo);
        btnSaldo->setObjectName("btnSaldo");
        btnSaldo->setGeometry(QRect(160, 120, 171, 71));
        btnSaldo->setFont(font);
        btnNosto = new QPushButton(accountInfo);
        btnNosto->setObjectName("btnNosto");
        btnNosto->setGeometry(QRect(160, 230, 171, 71));
        btnNosto->setFont(font);
        btnKirjauduUlos = new QPushButton(accountInfo);
        btnKirjauduUlos->setObjectName("btnKirjauduUlos");
        btnKirjauduUlos->setGeometry(QRect(200, 450, 80, 24));
        btnTapahtumat = new QPushButton(accountInfo);
        btnTapahtumat->setObjectName("btnTapahtumat");
        btnTapahtumat->setGeometry(QRect(160, 340, 171, 71));
        btnTapahtumat->setFont(font);

        retranslateUi(accountInfo);

        QMetaObject::connectSlotsByName(accountInfo);
    } // setupUi

    void retranslateUi(QDialog *accountInfo)
    {
        accountInfo->setWindowTitle(QCoreApplication::translate("accountInfo", "Dialog", nullptr));
        labelCardID->setText(QCoreApplication::translate("accountInfo", "TextLabel", nullptr));
        btnSaldo->setText(QCoreApplication::translate("accountInfo", "Saldo", nullptr));
        btnNosto->setText(QCoreApplication::translate("accountInfo", "Nosto", nullptr));
        btnKirjauduUlos->setText(QCoreApplication::translate("accountInfo", "Kirjaudu ulos", nullptr));
        btnTapahtumat->setText(QCoreApplication::translate("accountInfo", "Tilitapahtumat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountInfo: public Ui_accountInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTINFO_H
