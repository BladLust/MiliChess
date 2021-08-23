#ifndef MILICHESS_H
#define MILICHESS_H
#include <QDebug>
#include <QMainWindow>
#include <QtWidgets/QLabel>
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
    int overTimeCount=0;
    void reset();
};

class TimerThread:public QThread{
    Q_OBJECT
signals:
    void tick();
public:
    void run(){
        while(1){
            QThread::usleep(1000000);
            emit tick();
        }
    }
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
    int checkDeadCount=0;
    int unflippedCount=50;
    PLAYERS thisPlayer=UNKNOWN_PLAYER;
    ConnectAsHost* host=nullptr;
    ConnectToHost* client=nullptr;
    unsigned long long boardSeed;

    TimerThread* timer=nullptr;
    bool timerRunning=false;
    int timerTime=20;
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
    void timerSetup();
    void checkDead(PLAYERS);


   public:
    MiliChess(QWidget *parent = nullptr);
    void playerAction(int x, int y);
    ~MiliChess();

   public slots:
    void gridPress();
    void resetGame();
    void serverConnected();
    void gameDisconnected();
    void messageReceivedAsClient();
    void messageReceivedAsHost();
    void tickReceived();
private slots:
    void on_actionConnect_As_Host_triggered();
    void on_actionConnect_To_Host_triggered();
    void on_actionDisconnect_triggered();
    void on_actionForfeit_triggered();
};
#endif  // MILICHESS_H
