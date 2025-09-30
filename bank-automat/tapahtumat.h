#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Tapahtumat;
}

class Tapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tapahtumat(QWidget *parent = nullptr);
    ~Tapahtumat();

    void setIdkortti(const QString &newIdkortti);

    void setMyToken(const QByteArray &newMyToken);

private slots:
    void on_btnTapahtumat_clicked();
    void showTapahtumatSlot(QNetworkReply *reply);

    void on_btntakaisin_clicked();

    void on_btnseuraava_clicked();

    void on_btnedellinen_clicked();

private:
    Ui::Tapahtumat *ui;
    QString idkortti;
    QByteArray myToken;
    int currentPage;
    int totalPages;

    QNetworkAccessManager *tapahtumaManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TAPAHTUMAT_H
