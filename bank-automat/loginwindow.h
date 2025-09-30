#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>

namespace Ui {
class loginwindow;
}

class loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

private slots:
    void onButtonClicked();
    void onClearClicked();
    void onEnterClicked();
    void loginSlot (QNetworkReply *reply);
    void lockSlot(QNetworkReply *reply);

    void on_btntakaisin2_clicked();
    void onTimeout();

private:
    Ui::loginwindow *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QTimer *timer;
    int failedAttempts = 0;

    void lockCard();
};

#endif // LOGINWINDOW_H
