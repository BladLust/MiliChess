#include "connecttohost.h"

#include <QHostAddress>
#include <QMessageBox>
#include <QRegularExpression>

#include "ui_connecttohost.h"
ConnectToHost::ConnectToHost(QWidget *parent)
    : QDialog(parent), ui(new Ui::ConnectToHost) {
    ui->setupUi(this);
    setWindowTitle("连接到其他主机的对战");
    socket = new QTcpSocket(this);
}

ConnectToHost::~ConnectToHost() { delete ui; }

void ConnectToHost::on_connectToGame_released() {
    QRegularExpression regExp(
        "^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|["
        "01]?[0-9][0-9]?)$");
    QRegularExpressionMatch match = regExp.match(ui->ipInput->text());
    bool hasMatch = match.hasMatch();
    if (!hasMatch) {
        QMessageBox::critical(
            NULL, "Error: Incorrect IP adress",
            "The IP address you entered is invalid, please check.",
            QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    bool portCorrect;
    int portNum = ui->lineEdit->text().toInt(&portCorrect);
    if (!portCorrect || portNum > 65535 || portNum < 10000) {
        QMessageBox::critical(
            NULL, "Error: Incorrect port number",
            "The port number you entered is invalid, please check.",
            QMessageBox::Ok, QMessageBox::Ok);
    }
    connect(socket, &QTcpSocket::connected, this, &ConnectToHost::close);
    socket->connectToHost(QHostAddress(ui->ipInput->text()), portNum);
    setWindowTitle(QString::fromUtf8("请等待连接成功..."));
}
