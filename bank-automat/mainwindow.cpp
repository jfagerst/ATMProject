#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "loginwindow2.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnAlkuruutuSulje, &QPushButton::clicked, this, &MainWindow::closeApplication);
    connect(ui->btnPankkiautomaatti1, &QPushButton::clicked, this, &MainWindow::openloginwindow);
    connect(ui->btnPankkiautomaatti2, &QPushButton::clicked, this, &MainWindow::openloginwindow2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeApplication()
{
    QApplication::quit();
}

void MainWindow::openloginwindow()
{
    loginwindow *loginDialog = new loginwindow(this);
    loginDialog->exec();
    delete loginDialog;
}

void MainWindow::openloginwindow2()
{
    loginwindow2 *loginDialog = new loginwindow2(this);
    loginDialog->exec();
    delete loginDialog;
}
