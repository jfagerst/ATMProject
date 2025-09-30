#include "accountinfo.h"
#include "saldo.h"
#include "nosto.h"
#include "ui_accountinfo.h"
#include "mainwindow.h"
#include "tapahtumat.h"

accountInfo::accountInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountInfo)
{
    ui->setupUi(this);

    connect(ui->btnKirjauduUlos, &QPushButton::clicked, this, &accountInfo::on_btnKirjauduUlos_clicked);
}

accountInfo::~accountInfo()
{
    delete ui;
}

void accountInfo::setIdkortti(const QString &newIdkortti)
{
    idkortti = newIdkortti;
    ui->labelCardID->setText("Tervetuloa " + idkortti);
}

void accountInfo::setMyToken(const QByteArray &newMyToken)
{
    myToken = newMyToken;
    qDebug()<<"accountInfo";
    qDebug()<<myToken;
}



void accountInfo::on_btnSaldo_clicked()
{
    Saldo *objSaldo=new Saldo(this);
    objSaldo->setIdkortti(idkortti);
    objSaldo->setMyToken(myToken);
    objSaldo->open();
}

void accountInfo::on_btnNosto_clicked()
{
    Nosto *objNosto = new Nosto(this);
    objNosto->setIdkortti(idkortti);
    objNosto->setMyToken(myToken);
    objNosto->open();
}

void accountInfo::on_btnKirjauduUlos_clicked()
{
    idkortti.clear();
    myToken.clear();


    QWidget *mainWindow = nullptr;
    for (QWidget *widget : QApplication::topLevelWidgets()) {
        if (widget->inherits("MainWindow")) {
            mainWindow = widget;
        } else if (widget != this && widget->isVisible()) {
            widget->close();
        }
    }

    this->close();

    if (mainWindow) {
        mainWindow->show();
    }
}

void accountInfo::on_btnTapahtumat_clicked()
{
    Tapahtumat *objTapahtumat=new Tapahtumat(this);
    objTapahtumat->setIdkortti(idkortti);
    objTapahtumat->setMyToken(myToken);
    objTapahtumat->open();
}

