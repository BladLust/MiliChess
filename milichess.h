#ifndef MILICHESS_H
#define MILICHESS_H
#include <QDebug>
#include <QMainWindow>
#include "connectashost.h"
#include "connecttohost.h"
#include "chesspiece.h"

#include "MiliHeader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MiliChess;
}
QT_END_NAMESPACE
struct MiliSide {
    SIDE side = UNDETERMINED;
    SIDE lastFlipped=UNDETERMINED;
    int pieceCount[14] = {0};
    void reset();
};

class MiliChess : public QMainWindow {
    Q_OBJECT
signals:
    void connectToHostConnectionStart();
   private:
    Ui::MiliChess *ui;
    enum TURN_STATE { CHOOSE_PIECE=0, MOVE_PIECE=1 } turnState=CHOOSE_PIECE;
    enum PLAYERS { PLAYER1=0, PLAYER2=1,UNKNOWN_PLAYER=2};

    // Game state recorder
    bool sideDetermined = false;
    PLAYERS currentPlayer = PLAYER1;
    MiliSide players[2];

    bool isOnlineGame=false;
    bool isHost=false;
    PLAYERS thisPlayer=UNKNOWN_PLAYER;
    ConnectAsHost* host=nullptr;
    ConnectToHost* client=nullptr;
    unsigned long long boardSeed;

    ChessPiece *chosen=nullptr;
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
    void choosePiecePrep();
    bool beginsWith(QString,const char[]);
    void freezeBoard();


   public:
    MiliChess(QWidget *parent = nullptr);
    void playerAction(int x, int y);
    ~MiliChess();

   public slots:
    void gridPress();
    void resetGame();
    void serverConnected();
    void serverDisconnected();
    void messageReceivedAsClient();
    void messageReceivedAsHost();
private slots:
    void on_actionConnect_As_Host_triggered();
    void on_actionConnect_To_Host_triggered();
    void on_actionDisconnect_triggered();
};
#endif  // MILICHESS_H
