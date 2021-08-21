#ifndef CONNECTTOHOST_H
#define CONNECTTOHOST_H
#include <QTcpSocket>

#include <QDialog>

namespace Ui {
class ConnectToHost;
}

class ConnectToHost : public QDialog
{
    Q_OBJECT
friend class MiliChess;
public:
    explicit ConnectToHost(QWidget *parent = nullptr);
    QTcpSocket* socket;
    ~ConnectToHost();

private slots:
    void on_connectToGame_released();

private:
    Ui::ConnectToHost *ui;
};

#endif // CONNECTTOHOST_H
