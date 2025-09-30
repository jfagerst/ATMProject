#include "environment.h"
#include "saldo.h"
#include "ui_saldo.h"

Saldo::Saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saldo)
{
    ui->setupUi(this);
}

Saldo::~Saldo()
{
    delete ui;
}

void Saldo::setIdkortti(const QString &newIdkortti)
{
    idkortti = newIdkortti;
}

void Saldo::setMyToken(const QByteArray &newMyToken)
{
    myToken = newMyToken;

}

void Saldo::on_btnShowSaldo_clicked()
{
    qDebug()<<"show data button";
    QString site_url=Environment::base_url()+"/tili/saldo/kortti/"+idkortti;
    QNetworkRequest request(site_url);
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    dataManager = new QNetworkAccessManager(this);

    connect(dataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(showDataSlot(QNetworkReply*)));

    reply = dataManager->get(request);
}

void Saldo::on_btnShowCredit_clicked()
{
    qDebug()<<"show credit button";
    QString site_url=Environment::base_url()+"/tili/credit/kortti/"+idkortti;
    QNetworkRequest request(site_url);


    request.setRawHeader(QByteArray("Authorization"), (myToken));

    dataManager = new QNetworkAccessManager(this);

    connect(dataManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(showCreditSlot(QNetworkReply*)));

    reply = dataManager->get(request);
}


void Saldo::showDataSlot(QNetworkReply *reply)
{
    qDebug() << "show data SLOT";
    response_data = reply->readAll();
    qDebug() << "Response data:" << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    QString saldoStr = json_obj["saldo"].toString();
    double saldo = saldoStr.toDouble();

    ui->labelSaldoData->setText(QString("Tilillä on %1 euroa").arg(saldo));

    reply->deleteLater();
    dataManager->deleteLater();
}

void Saldo::showCreditSlot(QNetworkReply *reply)
{
    qDebug() << "show credit SLOT";
    response_data = reply->readAll();
    qDebug() << "Response data:" << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    QString creditStr = json_obj["luottoraja"].toString();
    double credit = creditStr.toDouble();

    ui->labelSaldoData->setText(QString("Tilillä on %1 euroa luottoa").arg(credit));

    reply->deleteLater();
    dataManager->deleteLater();
}

void Saldo::on_btnKirjauduUlos_clicked()
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

void Saldo::on_btntakaisin_clicked()
{
    this->close();
}

