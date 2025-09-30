#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();

    void setIdkortti(const QString &newIdkortti);

    void setMyToken(const QByteArray &newMyToken);

private slots:
    void on_btnShowSaldo_clicked();
    void on_btnShowCredit_clicked();
    void showDataSlot(QNetworkReply *reply);
    void showCreditSlot(QNetworkReply *reply);
    void on_btnKirjauduUlos_clicked();

    void on_btntakaisin_clicked();

private:
    Ui::Saldo *ui;
    QString idkortti;
    QByteArray myToken;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // SALDO_H
