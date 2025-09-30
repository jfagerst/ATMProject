#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <QDialog>

namespace Ui {
class accountInfo;
}

class accountInfo : public QDialog
{
    Q_OBJECT

public:
    explicit accountInfo(QWidget *parent = nullptr);
    ~accountInfo();

    void setCardID(const QString &newCardID);

    void setIdkortti(const QString &newIdkortti);

    void setMyToken(const QByteArray &newMyToken);

private slots:
    void on_btnSaldo_clicked();
    void on_btnNosto_clicked();
    void on_btnKirjauduUlos_clicked();
    void on_btnTapahtumat_clicked();

private:
    Ui::accountInfo *ui;
    QString idkortti;
    QByteArray myToken;

};

#endif // ACCOUNTINFO_H
