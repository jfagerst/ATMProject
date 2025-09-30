#include "accountinfo.h"
#include "environment.h"
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>

loginwindow::loginwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginwindow)
{
    ui->setupUi(this);

    ui->btn1->setFocusPolicy(Qt::NoFocus);
    ui->btn2->setFocusPolicy(Qt::NoFocus);
    ui->btn3->setFocusPolicy(Qt::NoFocus);
    ui->btn4->setFocusPolicy(Qt::NoFocus);
    ui->btn5->setFocusPolicy(Qt::NoFocus);
    ui->btn6->setFocusPolicy(Qt::NoFocus);
    ui->btn7->setFocusPolicy(Qt::NoFocus);
    ui->btn8->setFocusPolicy(Qt::NoFocus);
    ui->btn9->setFocusPolicy(Qt::NoFocus);
    ui->btn0->setFocusPolicy(Qt::NoFocus);
    ui->lineEditKortinNumero->setFocusPolicy(Qt::StrongFocus);
    ui->lineEditPIN->setFocusPolicy(Qt::StrongFocus);
    ui->lineEditPIN->setEchoMode(QLineEdit::Password);

    connect(ui->btn1, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn2, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn3, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn4, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn5, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn6, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn7, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn8, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn9, &QPushButton::clicked, this, &loginwindow::onButtonClicked);
    connect(ui->btn0, &QPushButton::clicked, this, &loginwindow::onButtonClicked);

    connect(ui->btnClear, &QPushButton::clicked, this, &loginwindow::onClearClicked);
    connect(ui->btnEnter, &QPushButton::clicked, this, &loginwindow::onEnterClicked);

    timer = new QTimer(this);
    connect(timer, QTimer::timeout,this, &loginwindow::onTimeout);
    timer->start (10000);
}

loginwindow::~loginwindow()
{
    delete ui;
    delete timer;
}

void loginwindow::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonText = button->text();

    if (ui->lineEditKortinNumero->hasFocus()) {
        ui->lineEditKortinNumero->insert(buttonText);
    }
    else if (ui->lineEditPIN->hasFocus()) {
        ui->lineEditPIN->insert(buttonText);
    }
}

void loginwindow::onClearClicked()
{
    ui->lineEditKortinNumero->clear();
    ui->lineEditPIN->clear();
}

void loginwindow::onEnterClicked()
{
    timer->stop();
    QJsonObject jsonObj;

    jsonObj.insert("idkortti",ui->lineEditKortinNumero->text());
    jsonObj.insert("pin",ui->lineEditPIN->text());

    QString site_url=Environment::base_url()+"/login";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager,SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void loginwindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    if(response_data.length()<2){
        ui->labelInfo->setText("Palvelin ei vastaa!");
        qDebug()<<"Palvelin ei vastaa";
    }
    else {
        if(response_data=="-11"){
            ui->labelInfo->setText("Tietokanta virhe!");
        }
        else {
            if(response_data=="false") {
                failedAttempts++;
                ui->labelInfo->setText("Väärä id/pin. Yritä uudelleen. Yritykset: " + QString::number(failedAttempts) + "/3");

                if (failedAttempts >= 3) {
                    lockCard();
                }
            }
            else if(response_data.length() > 20) {
                ui->labelInfo->setText("Kirjautuminen OK");
                QByteArray myToken="Bearer "+response_data;
                accountInfo *objaccountInfo=new accountInfo(this);
                objaccountInfo->setIdkortti(ui->lineEditKortinNumero->text());
                objaccountInfo->setMyToken(myToken);
                objaccountInfo->open();
                failedAttempts = 0;
            }
        }
        qDebug()<<response_data;
    }

    ui->lineEditKortinNumero->clear();
    ui->lineEditPIN->clear();
    reply->deleteLater();
    loginManager->deleteLater();
}

void loginwindow::on_btntakaisin2_clicked()
{
    this->close();
}

void loginwindow::onTimeout()
{
    QMessageBox::information(this, "Aikakatkaisu", "Aikakatkaisu! Palaa aloitusruutuun");
    this->close();
}

void loginwindow::lockCard()
{
    QJsonObject jsonObj;
    jsonObj.insert("idkortti", ui->lineEditKortinNumero->text());

    QString lock_url = Environment::base_url() + "/login/lock";
    QNetworkRequest request(lock_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *lockManager = new QNetworkAccessManager(this);
    connect(lockManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(lockSlot(QNetworkReply*)));

    lockManager->post(request, QJsonDocument(jsonObj).toJson());
}

void loginwindow::lockSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    if (response_data == "Card is locked") {
        ui->labelInfo->setText("Kortti on lukittu kolmen väärän PIN-yrityksen jälkeen.");
    } else {
        ui->labelInfo->setText("Virhe kortin lukituksessa.");
    }
    reply->deleteLater();
}
