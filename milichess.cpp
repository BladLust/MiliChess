#include "milichess.h"
#include "ui_milichess.h"
MiliChess::MiliChess(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiliChess)
{
    ui->setupUi(this);
#ifdef Q_OS_MACOS
    setFixedHeight(636);
#endif
// Loading Pieces from now
    boardSlots[0][0]= qobject_cast<ChessPiece*>(ui->BannarB1);
    boardSlots[0][0]->isBlue=true,boardSlots[0][0]->thisType=BANNAR;
    boardSlots[0][1]= qobject_cast<ChessPiece*>(ui->BannarR1);
    boardSlots[0][1]->isBlue=false,boardSlots[0][1]->thisType=BANNAR;
    boardSlots[0][2]= qobject_cast<ChessPiece*>(ui->BombB1);
    boardSlots[0][2]->isBlue=true,boardSlots[0][2]->thisType=BOMB;
    boardSlots[0][3]= qobject_cast<ChessPiece*>(ui->BombB2);
    boardSlots[0][3]->isBlue=true,boardSlots[0][3]->thisType=BOMB;
    boardSlots[0][4]= qobject_cast<ChessPiece*>(ui->BombR1);
    boardSlots[0][4]->isBlue=false,boardSlots[0][4]->thisType=BOMB;
    boardSlots[1][0]= qobject_cast<ChessPiece*>(ui->BombR2);
    boardSlots[1][0]->isBlue=false,boardSlots[1][0]->thisType=BOMB;
    boardSlots[1][1]= qobject_cast<ChessPiece*>(ui->CommB1);
    boardSlots[1][1]->isBlue=true,boardSlots[1][1]->thisType=COMM;
    boardSlots[1][2]= qobject_cast<ChessPiece*>(ui->CommR1);
    boardSlots[1][2]->isBlue=false,boardSlots[1][2]->thisType=COMM;
    boardSlots[1][3]= qobject_cast<ChessPiece*>(ui->JunB1);
    boardSlots[1][3]->isBlue=true,boardSlots[1][3]->thisType=JUN;
    boardSlots[1][4]= qobject_cast<ChessPiece*>(ui->JunR1);
    boardSlots[1][4]->isBlue=false,boardSlots[1][4]->thisType=JUN;
    boardSlots[2][0]= qobject_cast<ChessPiece*>(ui->LianB1);
    boardSlots[2][0]->isBlue=true,boardSlots[2][0]->thisType=LIAN;
    boardSlots[2][1]= qobject_cast<ChessPiece*>(ui->LianB2);
    boardSlots[2][1]->isBlue=true,boardSlots[2][1]->thisType=LIAN;
    boardSlots[2][2]= qobject_cast<ChessPiece*>(ui->LianB3);
    boardSlots[2][2]->isBlue=true,boardSlots[2][2]->thisType=LIAN;
    boardSlots[2][3]= qobject_cast<ChessPiece*>(ui->LianR1);
    boardSlots[2][3]->isBlue=false,boardSlots[2][3]->thisType=LIAN;
    boardSlots[2][4]= qobject_cast<ChessPiece*>(ui->LianR2);
    boardSlots[2][4]->isBlue=false,boardSlots[2][4]->thisType=LIAN;
    boardSlots[3][0]= qobject_cast<ChessPiece*>(ui->LianR3);
    boardSlots[3][0]->isBlue=false,boardSlots[3][0]->thisType=LIAN;
    boardSlots[3][1]= qobject_cast<ChessPiece*>(ui->LvB1);
    boardSlots[3][1]->isBlue=true,boardSlots[3][1]->thisType=LV;
    boardSlots[3][2]= qobject_cast<ChessPiece*>(ui->LvB2);
    boardSlots[3][2]->isBlue=true,boardSlots[3][2]->thisType=LV;
    boardSlots[3][3]= qobject_cast<ChessPiece*>(ui->LvR1);
    boardSlots[3][3]->isBlue=false,boardSlots[3][3]->thisType=LV;
    boardSlots[3][4]= qobject_cast<ChessPiece*>(ui->LvR2);
    boardSlots[3][4]->isBlue=false,boardSlots[3][4]->thisType=LV;
    boardSlots[4][0]= qobject_cast<ChessPiece*>(ui->MineB1);
    boardSlots[4][0]->isBlue=true,boardSlots[4][0]->thisType=MINE;
    boardSlots[4][1]= qobject_cast<ChessPiece*>(ui->MineB2);
    boardSlots[4][1]->isBlue=true,boardSlots[4][1]->thisType=MINE;
    boardSlots[4][2]= qobject_cast<ChessPiece*>(ui->MineB3);
    boardSlots[4][2]->isBlue=true,boardSlots[4][2]->thisType=MINE;
    boardSlots[4][3]= qobject_cast<ChessPiece*>(ui->MineR1);
    boardSlots[4][3]->isBlue=false,boardSlots[4][3]->thisType=MINE;
    boardSlots[4][4]= qobject_cast<ChessPiece*>(ui->MineR2);
    boardSlots[4][4]->isBlue=false,boardSlots[4][4]->thisType=MINE;
    boardSlots[5][0]= qobject_cast<ChessPiece*>(ui->MineR3);
    boardSlots[5][0]->isBlue=false,boardSlots[5][0]->thisType=MINE;
    boardSlots[5][1]= qobject_cast<ChessPiece*>(ui->PaiB1);
    boardSlots[5][1]->isBlue=true,boardSlots[5][1]->thisType=PAI;
    boardSlots[5][2]= qobject_cast<ChessPiece*>(ui->PaiB2);
    boardSlots[5][2]->isBlue=true,boardSlots[5][2]->thisType=PAI;
    boardSlots[5][3]= qobject_cast<ChessPiece*>(ui->PaiB3);
    boardSlots[5][3]->isBlue=true,boardSlots[5][3]->thisType=PAI;
    boardSlots[5][4]= qobject_cast<ChessPiece*>(ui->PaiR1);
    boardSlots[5][4]->isBlue=false,boardSlots[5][4]->thisType=PAI;
    boardSlots[6][0]= qobject_cast<ChessPiece*>(ui->PaiR2);
    boardSlots[6][0]->isBlue=false,boardSlots[6][0]->thisType=PAI;
    boardSlots[6][1]= qobject_cast<ChessPiece*>(ui->PaiR3);
    boardSlots[6][1]->isBlue=false,boardSlots[6][1]->thisType=PAI;
    boardSlots[6][2]= qobject_cast<ChessPiece*>(ui->ShiB1);
    boardSlots[6][2]->isBlue=true,boardSlots[6][2]->thisType=SHI;
    boardSlots[6][3]= qobject_cast<ChessPiece*>(ui->ShiB2);
    boardSlots[6][3]->isBlue=true,boardSlots[6][3]->thisType=SHI;
    boardSlots[6][4]= qobject_cast<ChessPiece*>(ui->ShiR1);
    boardSlots[6][4]->isBlue=false,boardSlots[6][4]->thisType=SHI;
    boardSlots[7][0]= qobject_cast<ChessPiece*>(ui->ShiR2);
    boardSlots[7][0]->isBlue=false,boardSlots[7][0]->thisType=SHI;
    boardSlots[7][1]= qobject_cast<ChessPiece*>(ui->SoldierB1);
    boardSlots[7][1]->isBlue=true,boardSlots[7][1]->thisType=SOLDIER;
    boardSlots[7][2]= qobject_cast<ChessPiece*>(ui->SoldierB2);
    boardSlots[7][2]->isBlue=true,boardSlots[7][2]->thisType=SOLDIER;
    boardSlots[7][3]= qobject_cast<ChessPiece*>(ui->SoldierB3);
    boardSlots[7][3]->isBlue=true,boardSlots[7][3]->thisType=SOLDIER;
    boardSlots[7][4]= qobject_cast<ChessPiece*>(ui->SoldierR1);
    boardSlots[7][4]->isBlue=false,boardSlots[7][4]->thisType=SOLDIER;
    boardSlots[8][0]= qobject_cast<ChessPiece*>(ui->SoldierR2);
    boardSlots[8][0]->isBlue=false,boardSlots[8][0]->thisType=SOLDIER;
    boardSlots[8][1]= qobject_cast<ChessPiece*>(ui->SoldierR3);
    boardSlots[8][1]->isBlue=false,boardSlots[8][1]->thisType=SOLDIER;
    boardSlots[8][2]= qobject_cast<ChessPiece*>(ui->TuanB1);
    boardSlots[8][2]->isBlue=true,boardSlots[8][2]->thisType=TUAN;
    boardSlots[8][3]= qobject_cast<ChessPiece*>(ui->TuanB2);
    boardSlots[8][3]->isBlue=true,boardSlots[8][3]->thisType=TUAN;
    boardSlots[8][4]= qobject_cast<ChessPiece*>(ui->TuanR1);
    boardSlots[8][4]->isBlue=false,boardSlots[8][4]->thisType=TUAN;
    boardSlots[9][0]= qobject_cast<ChessPiece*>(ui->TuanR2);
    boardSlots[9][0]->isBlue=false,boardSlots[9][0]->thisType=TUAN;
    boardSlots[9][1]= qobject_cast<ChessPiece*>(ui->YingB1);
    boardSlots[9][1]->isBlue=true,boardSlots[9][1]->thisType=YING;
    boardSlots[9][2]= qobject_cast<ChessPiece*>(ui->YingB2);
    boardSlots[9][2]->isBlue=true,boardSlots[9][2]->thisType=YING;
    boardSlots[9][3]= qobject_cast<ChessPiece*>(ui->YingR1);
    boardSlots[9][3]->isBlue=false,boardSlots[9][3]->thisType=YING;
    boardSlots[9][4]= qobject_cast<ChessPiece*>(ui->YingR2);
    boardSlots[9][4]->isBlue=false,boardSlots[9][4]->thisType=YING;
    ChessPiece ** slotPtr=&boardSlots[0][0];
    for(int i=0;i<50;i++){
        pieces[i]=boardSlots[i/5][i%5];// Collecting all valid chesspieces into the array
        connect(pieces[i],&QPushButton::released,this,&MiliChess::GridPressSlot);
    }
    qDebug()<<"Init Complete!";
}

MiliChess::~MiliChess()
{
    delete ui;
}

// Width:   434 px

void MiliSide::reset(){
    pieceCount[BANNAR]=pieceCount[COMM]=pieceCount[JUN]=1;
    pieceCount[SHI]=pieceCount[LV]=pieceCount[TUAN]=pieceCount[YING]=pieceCount[BOMB]=2;
    pieceCount[LIAN]=pieceCount[PAI]=pieceCount[SOLDIER]=pieceCount[MINE]=3;
    return;
}
void MiliChess::hprPointToGrid(int &x, int &y,const QPoint& pt){
    x=y=-1;
    switch (pt.x()) {
    case 354:
        ++x;
    case 267:
        ++x;
    case 179:
        ++x;
    case 91:
        ++x;
    case 4:
        ++x;
        break;
    default:
        qDebug()<<"ERROR! Undefined chess grid location!";
    }
    switch (pt.y()){
    case 566:
        ++y;
    case 523:
        ++y;
    case 481:
        ++y;
    case 438:
        ++y;
    case 395:
        ++y;
    case 354:
        ++y;
    case 218:
        ++y;
    case 175:
        ++y;
    case 133:
        ++y;
    case 91:
        ++y;
    case 48:
        ++y;
    case 7:
        ++y;
        break;
    default:
        qDebug()<<"ERROR! Undefined chess grid location!";
    }
    return;
}
void MiliChess::GridPressSlot(){
    int x,y;
    hprPointToGrid(x,y,qobject_cast<ChessPiece*>(sender())->pos());
    qDebug()<<"Received Press on grid location "<<x<<","<<y;
    return;
}
