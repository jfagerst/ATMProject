#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QWidget *parent = nullptr);
    ~Nosto();

    void setIdkortti(const QString &newIdkortti);
    void setMyToken(const QByteArray &newMyToken);

private slots:
    void on_btnDebit_clicked();
    void on_btnCredit_clicked();
    void on_btnClear_clicked();
    void onNumberClicked();
    void on_btnKirjauduUlos_clicked();

    void on_pushButton_clicked();

private:
    Ui::Nosto *ui;
    QString idkortti;
    QByteArray myToken;

    bool isDebitAvailable();
    bool isCreditAvailable();
    bool hasEnoughFunds(double amount);
    void updateSaldo(double amount);
    void updateCredit(double amount);

};

#endif // NOSTO_H
