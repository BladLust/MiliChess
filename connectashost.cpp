#include "connectashost.h"

#include <QMessageBox>
#include <random>

#include "ui_connectashost.h"

ConnectAsHost::ConnectAsHost(QWidget *parent)
    : QDialog(parent), ui(new Ui::ConnectAsHost) {
    ui->setupUi(this);
    setWindowTitle("作为主机进行联机");
    server = new QTcpServer(this);
    std::mt19937 mtr(
        std::chrono::system_clock::now().time_since_epoch().count());
    unsigned short portNum = mtr() % 50000 + 10000;
    QString ip;
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    int nIter = 0;
    for (; nIter < list.count(); nIter++)

    {
        if (!list[nIter].isLoopback())
            if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol) break;
    }
    if (nIter == 0) {
        QMessageBox::critical(
            NULL, "Error: You have no network connection.",
            "You have no network connection, please check your network.",
            QMessageBox::Ok, QMessageBox::Ok);
        close();
    }
    server->listen(QHostAddress::Any, portNum);
    ui->IPNum->setText(list[nIter].toString());
    ui->portNum->setText(QString::number(server->serverPort()));
}

ConnectAsHost::~ConnectAsHost() { delete ui; }

void ConnectAsHost::on_pushButton_clicked() {
    server->close();
    delete server;
    server = nullptr;
    close();
}
