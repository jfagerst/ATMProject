#include "environment.h"
#include "tapahtumat.h"
#include "ui_tapahtumat.h"

Tapahtumat::Tapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tapahtumat),
    currentPage(1),
    totalPages(1)
{
    ui->setupUi(this);
}

Tapahtumat::~Tapahtumat()
{
    delete ui;
}

void Tapahtumat::setIdkortti(const QString &newIdkortti)
{
    idkortti = newIdkortti;
}

void Tapahtumat::setMyToken(const QByteArray &newMyToken)
{
    myToken = newMyToken;
}

void Tapahtumat::on_btnTapahtumat_clicked()
{
    QString site_url = Environment::base_url() + "/tapahtuma/kortti/" + idkortti + "?page=" + QString::number(currentPage);
    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    tapahtumaManager = new QNetworkAccessManager(this);
    //connect(tapahtumaManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(showTapahtumatSlot(QNetworkReply*)));
    connect(tapahtumaManager, &QNetworkAccessManager::finished, this, &Tapahtumat::showTapahtumatSlot);

    reply = tapahtumaManager->get(request);
}

void Tapahtumat::showTapahtumatSlot(QNetworkReply *reply)
{
    qDebug() << "show data SLOT";
    response_data = reply->readAll();
    qDebug() << "Response data:" << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QJsonArray json_array = json_obj["tapahtumat"].toArray();
    totalPages = json_obj["totalPages"].toInt();

    QString tapahtuma;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject tapahtumaObj = value.toObject();
    int idtapahtuma = tapahtumaObj["idtapahtuma"].toInt();
    QString paivamaara = tapahtumaObj["paivamaara"].toString();
    int nostonmaara = tapahtumaObj["nostonmaara"].toInt();

    paivamaara = paivamaara.split("T").first();

    tapahtuma += QString("Tapahtuma #%1 - Päivämäärä: %2 - Nosto summa: %3\n")
    .arg(idtapahtuma)
    .arg(paivamaara)
    .arg(nostonmaara);
    }

    ui->textEditTapahtumat->setText(tapahtuma);

    if (currentPage < totalPages) {
        ui->btnseuraava->setEnabled(true);
    } else {
        ui->btnseuraava->setEnabled(false);
    }

    reply->deleteLater();
    tapahtumaManager->deleteLater();
}

void Tapahtumat::on_btntakaisin_clicked()
{
    this->close();
}


void Tapahtumat::on_btnseuraava_clicked()
{
    if (currentPage < totalPages) {
        currentPage++;
        on_btnTapahtumat_clicked();
    }
}


void Tapahtumat::on_btnedellinen_clicked()
{
    if (currentPage > 1) {
        currentPage--;
        on_btnTapahtumat_clicked();
    }
}

