/********************************************************************************
** Form generated from reading UI file 'tapahtumat.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAPAHTUMAT_H
#define UI_TAPAHTUMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Tapahtumat
{
public:
    QLabel *labelTapahtumat;
    QPushButton *btnTapahtumat;
    QTextEdit *textEditTapahtumat;
    QPushButton *btntakaisin;
    QPushButton *btnseuraava;
    QPushButton *btnedellinen;

    void setupUi(QDialog *Tapahtumat)
    {
        if (Tapahtumat->objectName().isEmpty())
            Tapahtumat->setObjectName("Tapahtumat");
        Tapahtumat->resize(610, 454);
        labelTapahtumat = new QLabel(Tapahtumat);
        labelTapahtumat->setObjectName("labelTapahtumat");
        labelTapahtumat->setGeometry(QRect(30, 20, 161, 31));
        btnTapahtumat = new QPushButton(Tapahtumat);
        btnTapahtumat->setObjectName("btnTapahtumat");
        btnTapahtumat->setGeometry(QRect(210, 30, 161, 51));
        textEditTapahtumat = new QTextEdit(Tapahtumat);
        textEditTapahtumat->setObjectName("textEditTapahtumat");
        textEditTapahtumat->setGeometry(QRect(30, 120, 541, 311));
        btntakaisin = new QPushButton(Tapahtumat);
        btntakaisin->setObjectName("btntakaisin");
        btntakaisin->setGeometry(QRect(420, 60, 80, 24));
        btnseuraava = new QPushButton(Tapahtumat);
        btnseuraava->setObjectName("btnseuraava");
        btnseuraava->setGeometry(QRect(420, 30, 80, 24));
        btnedellinen = new QPushButton(Tapahtumat);
        btnedellinen->setObjectName("btnedellinen");
        btnedellinen->setGeometry(QRect(100, 30, 80, 24));

        retranslateUi(Tapahtumat);

        QMetaObject::connectSlotsByName(Tapahtumat);
    } // setupUi

    void retranslateUi(QDialog *Tapahtumat)
    {
        Tapahtumat->setWindowTitle(QCoreApplication::translate("Tapahtumat", "Dialog", nullptr));
        labelTapahtumat->setText(QString());
        btnTapahtumat->setText(QCoreApplication::translate("Tapahtumat", "N\303\244yt\303\244 tapahtumat", nullptr));
        btntakaisin->setText(QCoreApplication::translate("Tapahtumat", "Palaa takaisin", nullptr));
        btnseuraava->setText(QCoreApplication::translate("Tapahtumat", "Seuraava sivu", nullptr));
        btnedellinen->setText(QCoreApplication::translate("Tapahtumat", "Edellinen sivu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tapahtumat: public Ui_Tapahtumat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAPAHTUMAT_H
