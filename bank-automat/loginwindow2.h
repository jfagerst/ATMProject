#ifndef LOGINWINDOW2_H
#define LOGINWINDOW2_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>

namespace Ui {
class loginwindow2;
}

class loginwindow2 : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow2(QWidget *parent = nullptr);
    ~loginwindow2();

private slots:
    void onButtonClicked();
    void onClearClicked();
    void onEnterClicked();
    void loginSlot (QNetworkReply *reply);
    void lockSlot(QNetworkReply *reply);

    void on_btnTakaisin_clicked();
    void onTimeout();

private:
    Ui::loginwindow2 *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QTimer *timer;
    int failedAttempts = 0;

    void lockCard();
};

#endif // LOGINWINDOW2_H
