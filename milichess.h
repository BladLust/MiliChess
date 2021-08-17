#ifndef MILICHESS_H
#define MILICHESS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MiliChess; }
QT_END_NAMESPACE

class MiliChess : public QMainWindow
{
    Q_OBJECT

public:
    MiliChess(QWidget *parent = nullptr);
    ~MiliChess();

private:
    Ui::MiliChess *ui;
};
#endif // MILICHESS_H
