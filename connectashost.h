#ifndef CONNECTASHOST_H
#define CONNECTASHOST_H

#include <QDialog>
#include <QTcpServer>
#include <QtNetwork>
#include <QTcpSocket>
//#include "milichess.h"
namespace Ui {
class ConnectAsHost;
}

class ConnectAsHost : public QDialog
{
    Q_OBJECT
friend class MiliChess;

public:
    explicit ConnectAsHost(QWidget *parent = nullptr);
    QTcpServer* server;
    QTcpSocket* socket;
    ~ConnectAsHost();

private slots:
    void on_pushButton_clicked();
public slots:

private:
    Ui::ConnectAsHost *ui;
};

#endif // CONNECTASHOST_H
