#ifndef MILICHESS_H
#define MILICHESS_H
#include <QDebug>
#include <QMainWindow>

#include "MiliHeader.h"
#include "chesspiece.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MiliChess;
}
QT_END_NAMESPACE
struct MiliSide {
    SIDE side = UNDETERMINED;
    SIDE lastFlipped=UNDETERMINED;
    int pieceCount[12] = {0};
    void reset();
};

class MiliChess : public QMainWindow {
    Q_OBJECT
   private:
    Ui::MiliChess *ui;
    enum TURN_STATE { CHOOSE_PIECE, MOVE_PIECE } turnState=CHOOSE_PIECE;
    enum PLAYERS { PLAYER1, PLAYER2 };

    // Game state recorder
    bool sideDetermined = false;
    PLAYERS currentPlayer = PLAYER1;
    MiliSide players[2];

    ChessPiece *chosen;
    ChessPiece *boardSlots[12][5];
    ChessPiece *pieces[50];
    ChessPiece *placeHolderPieces[70];
    bool movableMap[12][5];
    int placeHolderCount = 0;
    void hprPointToGrid(int &x, int &y, const QPoint &pt);
    void printGameInfo();
    bool isXingYing(int,int);
    void checkVRailway(int v,int h);
    void checkHRailway(int v,int h);
    void makeMovableMap();
    void resetCursor();
    void win(PLAYERS);


   public:
    MiliChess(QWidget *parent = nullptr);
    ~MiliChess();

   public slots:
    void gridPress();
    void resetGame();
};
#endif  // MILICHESS_H
