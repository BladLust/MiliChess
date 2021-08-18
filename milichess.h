#ifndef MILICHESS_H
#define MILICHESS_H
#include <QMainWindow>
#include "MiliHeader.h"
#include "chesspiece.h"
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MiliChess; }
QT_END_NAMESPACE
struct MiliSide{
    int pieceCount[12]={0};
    void reset();
};

class MiliChess : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MiliChess *ui;
    ChessPiece* boardSlots[12][5];
    ChessPiece* pieces[50];
    ChessPiece* placeHolderPieces[70];
    int placeHolderCount=0;
    void hprPointToGrid(int&x, int&y,const QPoint& pt);

signals:
    void GridPressSig(const QPoint&);
public:
    MiliChess(QWidget *parent = nullptr);
    ~MiliChess();

public slots:
    void GridPressSlot(const QPoint&);
};
#endif // MILICHESS_H
