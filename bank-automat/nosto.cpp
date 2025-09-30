#include "Nosto.h"
#include "ui_nosto.h"
#include "environment.h"

Nosto::Nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nosto)
{
    ui->setupUi(this);
    ui->labelNosto->setVisible(false);


    QList<QPushButton*> numberButtons = {ui->btn0, ui->btn1, ui->btn2, ui->btn3, ui->btn4,
                                          ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9};
    for (QPushButton *button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &Nosto::onNumberClicked);
    }


    connect(ui->btnClear, &QPushButton::clicked, this, &Nosto::on_btnClear_clicked);
}

Nosto::~Nosto()
{
    delete ui;
}

void Nosto::setIdkortti(const QString &newIdkortti)
{
    idkortti = newIdkortti;
}

void Nosto::setMyToken(const QByteArray &newMyToken)
{
    myToken = newMyToken;
}


void Nosto::onNumberClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString currentText = ui->lineEditNostettavaSumma->text();
    ui->lineEditNostettavaSumma->setText(currentText + button->text());
}


void Nosto::on_btnClear_clicked()
{
    ui->lineEditNostettavaSumma->clear();
}


void Nosto::on_btnDebit_clicked()
{
    QString amountText = ui->lineEditNostettavaSumma->text();
    double amount = amountText.toDouble();

    if (amount <= 0) {
        ui->labelNosto->setText("Syötä kelvollinen summa.");
        ui->labelNosto->setVisible(true);
        return;
    }

    if (!isDebitAvailable()) {
        ui->labelNosto->setText("Debit ei saatavilla tälle kortille.");
        ui->labelNosto->setVisible(true);
        return;
    }

    if (!hasEnoughFunds(amount)) {
        ui->labelNosto->setText("Ei tarpeeksi saldoa.");
        ui->labelNosto->setVisible(true);
        return;
    }

    updateSaldo(amount);
}


void Nosto::on_btnCredit_clicked()
{
    QString amountText = ui->lineEditNostettavaSumma->text();
    double amount = amountText.toDouble();

    if (amount <= 0) {
        ui->labelNosto->setText("Syötä kelvollinen summa.");
        ui->labelNosto->setVisible(true);
        return;
    }

    if (!isCreditAvailable()) {
        ui->labelNosto->setText("Credit ei saatavilla tälle kortille.");
        ui->labelNosto->setVisible(true);
        return;
    }

    if (!hasEnoughFunds(amount)) {
        ui->labelNosto->setText("Ei tarpeeksi luottoa.");
        ui->labelNosto->setVisible(true);
        return;
    }

    updateCredit(amount);
}


bool Nosto::hasEnoughFunds(double amount)
{
    QString site_url = Environment::base_url() + "/tili/saldo/kortti/" + idkortti;
    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"), myToken);

    QNetworkAccessManager *checkManager = new QNetworkAccessManager(this);
    QNetworkReply *checkReply = checkManager->get(request);

    QEventLoop eventLoop;
    connect(checkReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    QByteArray checkResponse = checkReply->readAll();

    QJsonDocument checkJsonDoc = QJsonDocument::fromJson(checkResponse);
    QJsonObject checkJsonObj = checkJsonDoc.object();

    QString saldoString = checkJsonObj["saldo"].toString();
    double availableFunds = saldoString.toDouble();

    checkReply->deleteLater();
    checkManager->deleteLater();

    return amount <= availableFunds;
}


bool Nosto::isDebitAvailable()
{
    QString site_url = Environment::base_url() + "/tili/nosto/debit/check/" + idkortti;
    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"), myToken);

    QNetworkAccessManager *checkManager = new QNetworkAccessManager(this);
    QNetworkReply *checkReply = checkManager->get(request);

    QEventLoop eventLoop;
    connect(checkReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    QByteArray checkResponse = checkReply->readAll();
    QJsonDocument checkJsonDoc = QJsonDocument::fromJson(checkResponse);
    QJsonObject checkJsonObj = checkJsonDoc.object();

    bool debitAvailable = checkJsonObj["debitAvailable"].toBool();

    checkReply->deleteLater();
    checkManager->deleteLater();

    return debitAvailable;
}

bool Nosto::isCreditAvailable()
{
    QString site_url = Environment::base_url() + "/tili/nosto/credit/check/" + idkortti;
    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"), myToken);

    QNetworkAccessManager *checkManager = new QNetworkAccessManager(this);
    QNetworkReply *checkReply = checkManager->get(request);

    QEventLoop eventLoop;
    connect(checkReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    QByteArray checkResponse = checkReply->readAll();
    QJsonDocument checkJsonDoc = QJsonDocument::fromJson(checkResponse);
    QJsonObject checkJsonObj = checkJsonDoc.object();

    bool creditAvailable = checkJsonObj["creditAvailable"].toBool();
    checkReply->deleteLater();
    checkManager->deleteLater();

    return creditAvailable;
}

void Nosto::updateSaldo(double amount)
{
    QString site_url = Environment::base_url() + "/tili/saldo/kortti/" + idkortti;
    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"), myToken);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["nostosumma"] = amount;
    QJsonDocument json_doc(json);

    QNetworkAccessManager *saldoUpdateManager = new QNetworkAccessManager(this);
    QNetworkReply *checkReply = saldoUpdateManager->post(request, json_doc.toJson());
    connect(checkReply, &QNetworkReply::finished, this, [=]() {
        if (checkReply->error() == QNetworkReply::NoError) {
            ui->labelNosto->setText("Nosto onnistui!");
        } else {
            ui->labelNosto->setText("Nosto epäonnistui: " + checkReply->errorString());
        }
        ui->labelNosto->setVisible(true);
        checkReply->deleteLater();
        saldoUpdateManager->deleteLater();
    });
}

void Nosto::updateCredit(double amount)
{
    QString site_url = Environment::base_url() + "/tili/luottoraja/kortti/" + idkortti;
    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"), myToken);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["nostosumma"] = amount;
    QJsonDocument json_doc(json);

    QNetworkAccessManager *creditUpdateManager = new QNetworkAccessManager(this);
    QNetworkReply *checkReply = creditUpdateManager->post(request, json_doc.toJson());
    connect(checkReply, &QNetworkReply::finished, this, [=]() {
        if (checkReply->error() == QNetworkReply::NoError) {
            ui->labelNosto->setText("Nosto onnistui!");
        } else {
            ui->labelNosto->setText("Nosto epäonnistui: " + checkReply->errorString());
        }
        ui->labelNosto->setVisible(true);
        checkReply->deleteLater();
        creditUpdateManager->deleteLater();
    });
}

void Nosto::on_btnKirjauduUlos_clicked()
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

void Nosto::on_pushButton_clicked()
{
    this->close();
}

