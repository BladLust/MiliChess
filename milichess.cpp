#include "milichess.h"

#include <QMessageBox>
#include <QTcpSocket>
#include <random>

#include "ui_milichess.h"
MiliChess::MiliChess(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MiliChess) {
    ui->setupUi(this);
#ifdef Q_OS_MACOS
    setFixedHeight(636);
#endif
    // Loading Pieces from now
    boardSlots[0][0] = qobject_cast<ChessPiece *>(ui->BannarB1);
    boardSlots[0][0]->side = BLUE, boardSlots[0][0]->thisType = BANNAR;
    boardSlots[0][1] = qobject_cast<ChessPiece *>(ui->BannarR1);
    boardSlots[0][1]->side = RED, boardSlots[0][1]->thisType = BANNAR;
    boardSlots[0][2] = qobject_cast<ChessPiece *>(ui->BombB1);
    boardSlots[0][2]->side = BLUE, boardSlots[0][2]->thisType = BOMB;
    boardSlots[0][3] = qobject_cast<ChessPiece *>(ui->BombB2);
    boardSlots[0][3]->side = BLUE, boardSlots[0][3]->thisType = BOMB;
    boardSlots[0][4] = qobject_cast<ChessPiece *>(ui->BombR1);
    boardSlots[0][4]->side = RED, boardSlots[0][4]->thisType = BOMB;
    boardSlots[1][0] = qobject_cast<ChessPiece *>(ui->BombR2);
    boardSlots[1][0]->side = RED, boardSlots[1][0]->thisType = BOMB;
    boardSlots[1][1] = qobject_cast<ChessPiece *>(ui->CommB1);
    boardSlots[1][1]->side = BLUE, boardSlots[1][1]->thisType = COMM;
    boardSlots[1][2] = qobject_cast<ChessPiece *>(ui->CommR1);
    boardSlots[1][2]->side = RED, boardSlots[1][2]->thisType = COMM;
    boardSlots[1][3] = qobject_cast<ChessPiece *>(ui->JunB1);
    boardSlots[1][3]->side = BLUE, boardSlots[1][3]->thisType = JUN;
    boardSlots[1][4] = qobject_cast<ChessPiece *>(ui->JunR1);
    boardSlots[1][4]->side = RED, boardSlots[1][4]->thisType = JUN;
    boardSlots[2][0] = qobject_cast<ChessPiece *>(ui->LianB1);
    boardSlots[2][0]->side = BLUE, boardSlots[2][0]->thisType = LIAN;
    boardSlots[2][1] = qobject_cast<ChessPiece *>(ui->LianB2);
    boardSlots[2][1]->side = BLUE, boardSlots[2][1]->thisType = LIAN;
    boardSlots[2][2] = qobject_cast<ChessPiece *>(ui->LianB3);
    boardSlots[2][2]->side = BLUE, boardSlots[2][2]->thisType = LIAN;
    boardSlots[2][3] = qobject_cast<ChessPiece *>(ui->LianR1);
    boardSlots[2][3]->side = RED, boardSlots[2][3]->thisType = LIAN;
    boardSlots[2][4] = qobject_cast<ChessPiece *>(ui->LianR2);
    boardSlots[2][4]->side = RED, boardSlots[2][4]->thisType = LIAN;
    boardSlots[3][0] = qobject_cast<ChessPiece *>(ui->LianR3);
    boardSlots[3][0]->side = RED, boardSlots[3][0]->thisType = LIAN;
    boardSlots[3][1] = qobject_cast<ChessPiece *>(ui->LvB1);
    boardSlots[3][1]->side = BLUE, boardSlots[3][1]->thisType = LV;
    boardSlots[3][2] = qobject_cast<ChessPiece *>(ui->LvB2);
    boardSlots[3][2]->side = BLUE, boardSlots[3][2]->thisType = LV;
    boardSlots[3][3] = qobject_cast<ChessPiece *>(ui->LvR1);
    boardSlots[3][3]->side = RED, boardSlots[3][3]->thisType = LV;
    boardSlots[3][4] = qobject_cast<ChessPiece *>(ui->LvR2);
    boardSlots[3][4]->side = RED, boardSlots[3][4]->thisType = LV;
    boardSlots[4][0] = qobject_cast<ChessPiece *>(ui->MineB1);
    boardSlots[4][0]->side = BLUE, boardSlots[4][0]->thisType = MINE;
    boardSlots[4][1] = qobject_cast<ChessPiece *>(ui->MineB2);
    boardSlots[4][1]->side = BLUE, boardSlots[4][1]->thisType = MINE;
    boardSlots[4][2] = qobject_cast<ChessPiece *>(ui->MineB3);
    boardSlots[4][2]->side = BLUE, boardSlots[4][2]->thisType = MINE;
    boardSlots[4][3] = qobject_cast<ChessPiece *>(ui->MineR1);
    boardSlots[4][3]->side = RED, boardSlots[4][3]->thisType = MINE;
    boardSlots[4][4] = qobject_cast<ChessPiece *>(ui->MineR2);
    boardSlots[4][4]->side = RED, boardSlots[4][4]->thisType = MINE;
    boardSlots[5][0] = qobject_cast<ChessPiece *>(ui->MineR3);
    boardSlots[5][0]->side = RED, boardSlots[5][0]->thisType = MINE;
    boardSlots[5][1] = qobject_cast<ChessPiece *>(ui->PaiB1);
    boardSlots[5][1]->side = BLUE, boardSlots[5][1]->thisType = PAI;
    boardSlots[5][2] = qobject_cast<ChessPiece *>(ui->PaiB2);
    boardSlots[5][2]->side = BLUE, boardSlots[5][2]->thisType = PAI;
    boardSlots[5][3] = qobject_cast<ChessPiece *>(ui->PaiB3);
    boardSlots[5][3]->side = BLUE, boardSlots[5][3]->thisType = PAI;
    boardSlots[5][4] = qobject_cast<ChessPiece *>(ui->PaiR1);
    boardSlots[5][4]->side = RED, boardSlots[5][4]->thisType = PAI;
    boardSlots[6][0] = qobject_cast<ChessPiece *>(ui->PaiR2);
    boardSlots[6][0]->side = RED, boardSlots[6][0]->thisType = PAI;
    boardSlots[6][1] = qobject_cast<ChessPiece *>(ui->PaiR3);
    boardSlots[6][1]->side = RED, boardSlots[6][1]->thisType = PAI;
    boardSlots[6][2] = qobject_cast<ChessPiece *>(ui->ShiB1);
    boardSlots[6][2]->side = BLUE, boardSlots[6][2]->thisType = SHI;
    boardSlots[6][3] = qobject_cast<ChessPiece *>(ui->ShiB2);
    boardSlots[6][3]->side = BLUE, boardSlots[6][3]->thisType = SHI;
    boardSlots[6][4] = qobject_cast<ChessPiece *>(ui->ShiR1);
    boardSlots[6][4]->side = RED, boardSlots[6][4]->thisType = SHI;
    boardSlots[7][0] = qobject_cast<ChessPiece *>(ui->ShiR2);
    boardSlots[7][0]->side = RED, boardSlots[7][0]->thisType = SHI;
    boardSlots[7][1] = qobject_cast<ChessPiece *>(ui->SoldierB1);
    boardSlots[7][1]->side = BLUE, boardSlots[7][1]->thisType = SOLDIER;
    boardSlots[7][2] = qobject_cast<ChessPiece *>(ui->SoldierB2);
    boardSlots[7][2]->side = BLUE, boardSlots[7][2]->thisType = SOLDIER;
    boardSlots[7][3] = qobject_cast<ChessPiece *>(ui->SoldierB3);
    boardSlots[7][3]->side = BLUE, boardSlots[7][3]->thisType = SOLDIER;
    boardSlots[7][4] = qobject_cast<ChessPiece *>(ui->SoldierR1);
    boardSlots[7][4]->side = RED, boardSlots[7][4]->thisType = SOLDIER;
    boardSlots[8][0] = qobject_cast<ChessPiece *>(ui->SoldierR2);
    boardSlots[8][0]->side = RED, boardSlots[8][0]->thisType = SOLDIER;
    boardSlots[8][1] = qobject_cast<ChessPiece *>(ui->SoldierR3);
    boardSlots[8][1]->side = RED, boardSlots[8][1]->thisType = SOLDIER;
    boardSlots[8][2] = qobject_cast<ChessPiece *>(ui->TuanB1);
    boardSlots[8][2]->side = BLUE, boardSlots[8][2]->thisType = TUAN;
    boardSlots[8][3] = qobject_cast<ChessPiece *>(ui->TuanB2);
    boardSlots[8][3]->side = BLUE, boardSlots[8][3]->thisType = TUAN;
    boardSlots[8][4] = qobject_cast<ChessPiece *>(ui->TuanR1);
    boardSlots[8][4]->side = RED, boardSlots[8][4]->thisType = TUAN;
    boardSlots[9][0] = qobject_cast<ChessPiece *>(ui->TuanR2);
    boardSlots[9][0]->side = RED, boardSlots[9][0]->thisType = TUAN;
    boardSlots[9][1] = qobject_cast<ChessPiece *>(ui->YingB1);
    boardSlots[9][1]->side = BLUE, boardSlots[9][1]->thisType = YING;
    boardSlots[9][2] = qobject_cast<ChessPiece *>(ui->YingB2);
    boardSlots[9][2]->side = BLUE, boardSlots[9][2]->thisType = YING;
    boardSlots[9][3] = qobject_cast<ChessPiece *>(ui->YingR1);
    boardSlots[9][3]->side = RED, boardSlots[9][3]->thisType = YING;
    boardSlots[9][4] = qobject_cast<ChessPiece *>(ui->YingR2);
    boardSlots[9][4]->side = RED, boardSlots[9][4]->thisType = YING;
    for (int i = 10; i < 12; ++i)
        for (int j = 0; j < 5; ++j) boardSlots[i][j] = nullptr;
    placeHolderCount = 0;
    for (int i = 0; i < 70; i++) {
        ChessPiece *newEmpty = new ChessPiece(this);
        placeHolderPieces[i] = newEmpty;
        newEmpty->thisType = EMPTY;
        newEmpty->setObjectName(QString::fromUtf8("newEmpty"));
        newEmpty->setEnabled(false);
        newEmpty->setGeometry(QRect(91, 7, 76, 38));
        newEmpty->setStyleSheet(QString::fromUtf8(""));
        newEmpty->setFlat(true);
        newEmpty->hide();
        placeHolderPieces[placeHolderCount++] = newEmpty;
        connect(newEmpty, &QPushButton::released, this, &MiliChess::gridPress);
    }
    for (int i = 0; i < 50; i++) {
        pieces[i] = boardSlots[i / 5][i % 5];  // Collecting all valid
                                               // chesspieces into the array
        connect(pieces[i], &QPushButton::released, this, &MiliChess::gridPress);
    }
    freezeBoard();
    connect(ui->actionStart, &QAction::triggered, this, &MiliChess::resetGame);
    ui->timerLabel->hide();
    timer=new TimerThread;
    connect(timer,&TimerThread::tick,this,&MiliChess::tickReceived);
    qDebug() << "Init Complete!";
}

MiliChess::~MiliChess() {
    if(timer)
        timer->exit();
    delete ui; }

// Width:   434 px

void MiliChess::gridPress() {
    int x, y;
    hprPointToGrid(x, y, qobject_cast<ChessPiece *>(sender())->pos());
    if (isOnlineGame && currentPlayer != thisPlayer) return;
    playerAction(x, y);
    if (isOnlineGame) {
        if (isHost) {
            host->socket->write((QString::fromUtf8("gridh:") +
                                 QString::number(x) + QString(',') +
                                 QString::number(y))
                                    .toUtf8());
        } else {
            client->socket->write((QString::fromUtf8("gridc:") +
                                   QString::number(x) + QString(',') +
                                   QString::number(y))
                                      .toUtf8());
        }
    }
}
void MiliChess::playerAction(int x, int y) {
    ChessPiece *thisPiece = boardSlots[x][y];
    qDebug() << "Received Press on grid location " << x << "," << y;
    if (x == -1 || y == -1) qDebug() << "Received Press on unorthodox button";

    if (turnState == CHOOSE_PIECE) {
        if (thisPiece->thisType == EMPTY) return;
        if (thisPiece->isFlipped == false) {
            thisPiece->isFlipped = true;
            thisPiece->reStyle();
            if (!sideDetermined) {
                if (players[currentPlayer].lastFlipped == thisPiece->side) {
                    players[currentPlayer].side = thisPiece->side;
                    players[!currentPlayer].side =
                        thisPiece->side == BLUE ? RED : BLUE;
                    sideDetermined = true;
                } else {
                    players[currentPlayer].lastFlipped = thisPiece->side;
                }
            }
            currentPlayer = (PLAYERS)(!(int)currentPlayer);  // Switch side
            timerTime=21;
            ui->timerLabel->setText(QString::fromUtf8("剩余时间：20s"));
            printGameInfo();
            return;
        }
        if (thisPiece->isFlipped == true && sideDetermined == false) {
            return;
        }
        if (thisPiece->isFlipped == true &&
            thisPiece->side != players[currentPlayer].side)
            return;
        switch (thisPiece->thisType) {
            case BANNAR:
            case UNPROTECTED_BANNAR:
            case MINE:
            case EMPTY:
                qDebug() << "Illegal piece choose";
                return;
            default:
                chosen = thisPiece;
                makeMovableMap();
                turnState = MOVE_PIECE;
                resetCursor();
                printGameInfo();
        }
    } else {
        if (thisPiece->pos() == chosen->pos()) {
            turnState = CHOOSE_PIECE;
            resetCursor();
            printGameInfo();
            return;
        }
        if (movableMap[x][y] == true) {
            // Hide and disable whichever piece got eaten
            boardSlots[x][y]->hide();
            boardSlots[x][y]->setEnabled(false);
            // Letting the empty button show at where chosen was
            int chosenX, chosenY;
            hprPointToGrid(chosenX, chosenY, chosen->pos());
            boardSlots[chosenX][chosenY] =
                placeHolderPieces[chosenX * 5 + chosenY];
            boardSlots[chosenX][chosenY]->move(HOR_ANCHOR[chosenY],
                                               VER_ANCHOR[chosenX]);
            boardSlots[chosenX][chosenY]->show();
            boardSlots[chosenX][chosenY]->setEnabled(true);
            // If the eaten button wasn't a placeholder, decrease its count
            if (boardSlots[x][y]->thisType != EMPTY) {
                players[!currentPlayer]
                    .pieceCount[boardSlots[x][y]->thisType]--;
            }
            if (WIN_CHART[chosen->thisType][boardSlots[x][y]->thisType] ==
                WIN) {
                // If it's a eat, move chosen
                chosen->move(HOR_ANCHOR[y], VER_ANCHOR[x]);
                if (boardSlots[x][y]->thisType == MINE &&
                    players[!currentPlayer].pieceCount[MINE] == 0) {
                    (players[currentPlayer].side == RED ? ui->BannarB1
                                                        : ui->BannarR1)
                        ->thisType = UNPROTECTED_BANNAR;
                }
                if (boardSlots[x][y]->thisType == UNPROTECTED_BANNAR) {
                    win(currentPlayer);
                    return;
                }
                boardSlots[x][y] = chosen;
            } else {
                // If it's suicide attack, generate a new empty button
                chosen->hide();
                chosen->setEnabled(false);
                players[currentPlayer].pieceCount[chosen->thisType]--;
                boardSlots[x][y] = placeHolderPieces[x * 5 + y];
                boardSlots[x][y]->setEnabled(true);
                boardSlots[x][y]->move(HOR_ANCHOR[y], VER_ANCHOR[x]);
                boardSlots[x][y]->show();
            }
            turnState = CHOOSE_PIECE;
            currentPlayer = (PLAYERS)!currentPlayer;
            ui->timerLabel->setText(QString::fromUtf8("剩余时间：20s"));
            timerTime=21;
            resetCursor();
        } else {
            qDebug() << "Nope, you can't go there with this one.";
        }
        printGameInfo();
    }
    return;
}
void MiliChess::resetGame() {
    // Resetting BANNARs from potential UNPROTECTED_BANNARs
    ui->BannarB1->thisType = BANNAR;
    ui->BannarR1->thisType = BANNAR;
    players[0].reset();
    players[1].reset();
    sideDetermined = false;
    turnState = CHOOSE_PIECE;
    // Unfreeze the game from last game
    for (int i = 0; i < 50; i++) pieces[i]->setEnabled(true), pieces[i]->show();
    for (int i = 0; i < 70; i++) {
        placeHolderPieces[i]->setEnabled(false);
        placeHolderPieces[i]->hide();
    }
    ui->mainInfo->setAlignment(Qt::Alignment(Qt::AlignmentFlag::AlignLeft |
                                             Qt::AlignmentFlag::AlignVCenter));
    if (isOnlineGame == false || isHost == true)
        boardSeed = std::chrono::system_clock::now().time_since_epoch().count();
    currentPlayer = (PLAYERS)(boardSeed % 2);
    for (int i = 0; i < 50;
         i++) {  // Put all pieces on the top 50 grids on the board, face down
        boardSlots[i / 5][i % 5] = pieces[i];
        pieces[i]->unFlip();
    }
    //    while (
    //        placeHolderCount--) {  // Delete empty placeholders from previous
    //        games placeHolderPieces[placeHolderCount-1].resetEmpty();
    //    }
    std::mt19937 mtr(boardSeed);
    std::shuffle((ChessPiece **)boardSlots, (ChessPiece **)boardSlots + 50,
                 mtr);  // Shuffle the order of first 50 pieces on board
    for (int i = 0; i < 10; i++) {
        boardSlots[10 + i / 5][i % 5] =
            boardSlots[XINGYING[i][0]]
                      [XINGYING[i][1]];  // Exchange pieces on XINGYINGs and the
                                         // bottom 10 grids
        // From now on is adding new empty chesspieces on the XINGYINGs
        ChessPiece *newEmpty = boardSlots[XINGYING[i][0]][XINGYING[i][1]] =
            placeHolderPieces[XINGYING[i][0] * 5 + XINGYING[i][1]];
        newEmpty->setEnabled(true);
        newEmpty->show();
    }
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 5; ++j) {
            boardSlots[i][j]->move(HOR_ANCHOR[j], VER_ANCHOR[i]);
            boardSlots[i][j]->reStyle();
        }
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            movableMap[i][j] = true;
        }
    }
    resetCursor();
    printGameInfo();
    timerRunning=true;
    timer->exit();
    QThread::usleep(10);
    timer->start();
    timerTime=21;
    ui->timerLabel->show();
}
void MiliSide::reset() {
    lastFlipped = UNDETERMINED;
    side = UNDETERMINED;
    pieceCount[BANNAR] = pieceCount[UNPROTECTED_BANNAR] = pieceCount[COMM] =
        pieceCount[JUN] = 1;
    pieceCount[SHI] = pieceCount[LV] = pieceCount[TUAN] = pieceCount[YING] =
        pieceCount[BOMB] = 2;
    pieceCount[LIAN] = pieceCount[PAI] = pieceCount[SOLDIER] =
        pieceCount[MINE] = 3;
    overTimeCount=0;
    return;
}
void MiliChess::hprPointToGrid(int &y, int &x, const QPoint &pt) {
    x = y = -1;
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
            qDebug() << "ERROR! Undefined chess grid location!";
    }
    switch (pt.y()) {
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
            qDebug() << "ERROR! Undefined chess grid location!";
    }
    return;
}
/* A direction map, from upwards and moves clockwisely */

void MiliChess::printGameInfo() {
    QString text;
    if (!sideDetermined) {
        text += QString::fromUtf8(
            "双方轮流翻开棋子，首个连续翻出两枚同色棋子的玩家定为该色\n");
        if (isOnlineGame)
            text += QString::fromUtf8(currentPlayer == thisPlayer ? "您的回合"
                                                                  : "对方回合");
        else
            text += QString::fromUtf8(currentPlayer ? "玩家2的回合"
                                                    : "玩家1的回合");
    } else {
        if (isOnlineGame)
            text += QString::fromUtf8(currentPlayer == thisPlayer ? "您的回合"
                                                                  : "对方回合");
        else
            text += QString::fromUtf8(currentPlayer ? "玩家2的回合"
                                                    : "玩家1的回合");
        text += QString::fromUtf8(players[currentPlayer].side ? "\t蓝色方\n"
                                                              : "\t红色方\n");
        if (isOnlineGame && (currentPlayer != thisPlayer)) {
            if (turnState)
                text += QString::fromUtf8("当前选中：") +
                        QString::fromUtf8(TYPE_NAME_CHN[chosen->thisType]);
            text += QString::fromUtf8(turnState ? "，正在选择移动位置"
                                                : "正在选择棋子");
        } else {
            if (turnState)
                text += QString::fromUtf8("当前选中：") +
                        QString::fromUtf8(TYPE_NAME_CHN[chosen->thisType]);
            text += QString::fromUtf8(turnState ? "，请选择移动位置"
                                                : "请选择棋子");
        }
    }
    ui->mainInfo->setText(text);
    // UNDER CONSTRUCTION
    return;
}
bool MiliChess::isXingYing(int v, int h) {
    for (int i = 0; i < 10; i++)
        if (v == XINGYING[i][0] && h == XINGYING[i][1]) return true;
    return false;
}
void MiliChess::checkVRailway(int v, int h) {
    if (v == 0 || v == 11) return;
    if (h != 0 && h != 4) return;
    PIECE_CLASH_RESULT clashResult;
    for (int i = v + 1; i < 11; ++i) {
        if (movableMap[i][h] == true)
            return;  // To end recursion in case of railway loop
        if (boardSlots[i][h]->isFlipped == false) break;
        if (boardSlots[i][h]->side == chosen->side) break;
        clashResult = WIN_CHART[chosen->thisType][boardSlots[i][h]->thisType];
        if (clashResult != WIN && clashResult != BOTH_DIE) break;
        movableMap[i][h] = true;
        if ((i == 10 || i == 5 || i == 6) &&
            chosen->thisType ==
                SOLDIER) {  // Enabling the soldier piece to do its turing thing
            checkHRailway(i, h);
        }
    }
    for (int i = v - 1; i > 0; --i) {
        if (movableMap[i][h] == true)
            return;  // To end recursion in case of railway loop
        if (boardSlots[i][h]->isFlipped == false) break;
        if (boardSlots[i][h]->side == chosen->side) break;
        clashResult = WIN_CHART[chosen->thisType][boardSlots[i][h]->thisType];
        if (clashResult != WIN && clashResult != BOTH_DIE) break;
        movableMap[i][h] = true;
        if ((i == 1 || i == 5 || i == 6) &&
            chosen->thisType ==
                SOLDIER) {  // Enabling the soldier piece to do its turing thing
            checkHRailway(i, h);
        }
    }
}
void MiliChess::checkHRailway(int v, int h) {
    if (v != 1 && v != 5 && v != 6 && v != 10) return;
    PIECE_CLASH_RESULT clashResult;
    for (int i = h + 1; i < 5; ++i) {
        if (movableMap[v][i] == true)
            return;  // To end recursion in case of railway loop
        if (boardSlots[v][i]->isFlipped == false) break;
        if (boardSlots[v][i]->side == chosen->side) break;
        clashResult = WIN_CHART[chosen->thisType][boardSlots[v][i]->thisType];
        if (clashResult != WIN && clashResult != BOTH_DIE) break;
        movableMap[v][i] = true;
        if (chosen->thisType == SOLDIER) {
            if (i == 4) checkVRailway(v, i);
            if (i == 2) {
                clashResult =
                    WIN_CHART[chosen->thisType][boardSlots[6][2]->thisType];
                if (v == 5 && movableMap[6][2] == false &&
                    boardSlots[6][2]->isFlipped == true &&
                    boardSlots[6][2]->side != chosen->side &&
                    (clashResult == WIN || clashResult == BOTH_DIE)) {
                    movableMap[6][2] = true;
                    checkHRailway(6, 2);
                }
                clashResult =
                    WIN_CHART[chosen->thisType][boardSlots[5][2]->thisType];
                if (v == 6 && movableMap[5][2] == false &&
                    boardSlots[5][2]->isFlipped == true &&
                    boardSlots[5][2]->side != chosen->side &&
                    (clashResult == WIN || clashResult == BOTH_DIE)) {
                    movableMap[5][2] = true;
                    checkHRailway(5, 2);
                }
            }
        }
    }
    for (int i = h - 1; i >= 0; --i) {
        if (movableMap[v][i] == true)
            return;  // To end recursion in case of railway loop
        if (boardSlots[v][i]->isFlipped == false) break;
        if (boardSlots[v][i]->side == chosen->side) break;
        clashResult = WIN_CHART[chosen->thisType][boardSlots[v][i]->thisType];
        if (clashResult != WIN && clashResult != BOTH_DIE) break;
        movableMap[v][i] = true;
        if (chosen->thisType == SOLDIER) {
            if (i == 0) checkVRailway(v, i);
            if (i == 2) {
                clashResult =
                    WIN_CHART[chosen->thisType][boardSlots[6][2]->thisType];
                if (v == 5 && movableMap[6][2] == false &&
                    boardSlots[6][2]->isFlipped == true &&
                    boardSlots[6][2]->side != chosen->side &&
                    (clashResult == WIN || clashResult == BOTH_DIE)) {
                    movableMap[6][2] = true;
                    checkHRailway(6, 2);
                }
                clashResult =
                    WIN_CHART[chosen->thisType][boardSlots[5][2]->thisType];
                if (v == 6 && movableMap[5][2] == false &&
                    boardSlots[5][2]->isFlipped == true &&
                    boardSlots[5][2]->side != chosen->side &&
                    (clashResult == WIN || clashResult == BOTH_DIE)) {
                    movableMap[5][2] = true;
                    checkHRailway(5, 2);
                }
            }
        }
    }
}
static const int DIRECTION_MAP[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                        {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
void MiliChess::makeMovableMap() {
    for (int i = 0; i < 12; ++i)  // Resetting the map
        for (int j = 0; j < 5; ++j) movableMap[i][j] = false;
    int chosenX, chosenY, probeX, probeY;
    PIECE_CLASH_RESULT clashResult;
    hprPointToGrid(chosenX, chosenY, chosen->pos());
    movableMap[chosenX][chosenY] =
        true;  // Set self to true to allow un-selection
    // First we deal with the situations with railways since they are more
    // complicated
    checkHRailway(chosenX, chosenY);
    checkVRailway(chosenX, chosenY);
    // Secondly, we consider the cases where the chess pieces that diagonally
    if (isXingYing(chosenX, chosenY)) {
        for (int i = 0; i < 4; ++i) {
            probeX = chosenX + DIRECTION_MAP[i * 2 + 1][0];
            probeY = chosenY + DIRECTION_MAP[i * 2 + 1][1];
            if (probeX < 0 || probeX > 11 || probeY < 0 || probeY > 4) continue;
            if (boardSlots[probeX][probeY]->isFlipped == false) continue;
            if (boardSlots[probeX][probeY]->side == chosen->side) continue;
            clashResult = WIN_CHART[chosen->thisType]
                                   [boardSlots[probeX][probeY]->thisType];
            if ((clashResult == WIN || clashResult == BOTH_DIE) &&
                (!isXingYing(probeX, probeY) ||
                 boardSlots[probeX][probeY]->thisType == EMPTY))
                movableMap[probeX][probeY] = true;
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            probeX = chosenX + DIRECTION_MAP[i * 2 + 1][0];
            probeY = chosenY + DIRECTION_MAP[i * 2 + 1][1];
            if (probeX < 0 || probeX > 11 || probeY < 0 || probeY > 4) continue;
            if (!isXingYing(probeX, probeY)) continue;
            if (boardSlots[probeX][probeY]->thisType != EMPTY) continue;
            if (boardSlots[probeX][probeY]->isFlipped == false) continue;
            if (boardSlots[probeX][probeY]->side == chosen->side) continue;
            movableMap[probeX][probeY] = true;
        }
    }
    // Thirdly, the horizontal and vertical ones.
    for (int i = 0; i < 4; i++) {
        probeX = chosenX + DIRECTION_MAP[i * 2][0];
        probeY = chosenY + DIRECTION_MAP[i * 2][1];
        if (probeX < 0 || probeX > 11 || probeY < 0 || probeY > 4) continue;
        // The following two are determining whether the piece is trying to
        // cross the river
        if (i == 0 && probeX == 5 && (probeY == 1 || probeY == 3)) continue;
        if (i == 2 && probeX == 6 && (probeY == 1 || probeY == 3)) continue;
        if (boardSlots[probeX][probeY]->isFlipped == false) continue;
        if (boardSlots[probeX][probeY]->side == chosen->side) continue;
        if (isXingYing(probeX, probeY) &&
            boardSlots[probeX][probeY]->thisType != EMPTY)
            continue;
        clashResult =
            WIN_CHART[chosen->thisType][boardSlots[probeX][probeY]->thisType];
        if (clashResult == WIN || clashResult == BOTH_DIE)
            movableMap[probeX][probeY] = true;
    }
}
void MiliChess::resetCursor() {
    if (turnState == CHOOSE_PIECE) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 5; j++) {
                if (boardSlots[i][j]->thisType == EMPTY ||
                    (boardSlots[i][j]->isFlipped == true &&
                     boardSlots[i][j]->side != players[currentPlayer].side))
                    boardSlots[i][j]->setCursor(Qt::ForbiddenCursor);
                else
                    boardSlots[i][j]->setCursor(Qt::ArrowCursor);
            }
        }
    } else {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 5; j++) {
                if (movableMap[i][j] == true)
                    boardSlots[i][j]->setCursor(Qt::ArrowCursor);
                else
                    boardSlots[i][j]->setCursor(Qt::ForbiddenCursor);
            }
        }
    }
}
void MiliChess::win(PLAYERS wonPlayer) {
    QString text;
    if (!isOnlineGame)
        text =
            wonPlayer ? QString::fromUtf8("玩家2") : QString::fromUtf8("玩家1");
    else
        text = wonPlayer == thisPlayer ? QString::fromUtf8("您")
                                       : QString::fromUtf8("对方");
    text += players[wonPlayer].side == RED
                ? QString::fromUtf8("以红色方获胜！")
                : QString::fromUtf8("以蓝色方获胜！");
    text += QString::fromUtf8("\n请使用主菜单重新开始游戏！");
    QMessageBox::information(NULL, "胜负已决！", text, QMessageBox::Ok,
                             QMessageBox::Ok);
    // Freeze the game
    if(timer){
        timer->exit();
    }
    ui->timerLabel->hide();
    freezeBoard();
}
void MiliChess::freezeBoard() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            if (boardSlots[i][j]) boardSlots[i][j]->setEnabled(false);
        }
    }
    if (chosen) chosen->setEnabled(false);
}
void MiliChess::on_actionConnect_As_Host_triggered() {
    isOnlineGame = false;
    if (host) delete host;
    host = new ConnectAsHost(this);
    host->show();
    connect(host->server, &QTcpServer::newConnection, this,
            &MiliChess::serverConnected);
}
void MiliChess::serverConnected() {
    host->socket = host->server->nextPendingConnection();
    resetGame();
    thisPlayer = PLAYER1;
    host->socket->write(
        (QString::fromUtf8("reset:") + QString::number(boardSeed)).toUtf8());
    isOnlineGame = true;
    isHost = true;
    printGameInfo();
    connect(host->socket, &QTcpSocket::readyRead, this,
            &MiliChess::messageReceivedAsHost);
    connect(host->socket, &QTcpSocket::disconnected, this,
            &MiliChess::gameDisconnected);
    host->close();
    return;
}
void MiliChess::gameDisconnected() {
    isOnlineGame = false;
    isHost = false;
    if (isHost) {
        if (host && host->server) {
            host->server->close();
        }
    } else {
        if (client && client->socket) {
            client->socket->close();
        }
        freezeBoard();
        QMessageBox::information(
            NULL, "断开连接",
            "连接已经断开，对局已丢失，请重新连接或开始本地对局",
            QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
}
void MiliChess::on_actionConnect_To_Host_triggered() {
    isOnlineGame = false;
    if (client) delete client;
    client = new ConnectToHost(this);
    client->show();
    client->setModal(true);
    connect(client->socket, &QTcpSocket::readyRead, this,
            &MiliChess::messageReceivedAsClient);
    connect(client, &ConnectToHost::socketDisconnected, this,
            &MiliChess::gameDisconnected);
}
void MiliChess::messageReceivedAsClient() {
    if (isHost) return;
    QString receivedMessage = QString(client->socket->readAll());
    if (beginsWith(receivedMessage, "reset:")) {
        isOnlineGame = true;
        isHost = false;
        boardSeed = receivedMessage.section(':', 1).toULongLong();
        thisPlayer = PLAYER2;
        resetGame();
    }
    if (beginsWith(receivedMessage, "gridh:")) {
        if (currentPlayer == thisPlayer) {
            return;
        }
        QString actedGrid = receivedMessage.section(':', 1);
        playerAction(actedGrid.section(',', 0, 0).toInt(),
                     actedGrid.section(',', 1, 1).toInt());
    }
    if (beginsWith(receivedMessage, "FFh:")) {
        freezeBoard();
        QMessageBox::information(NULL, "对方已投降",
                                 "恭喜您！对方投降，您已获胜！",
                                 QMessageBox::Ok, QMessageBox::Ok);
        win(thisPlayer);
    }
}
void MiliChess::messageReceivedAsHost() {
    if (!isHost) {
        return;
    }
    QString receivedMessage = QString(host->socket->readAll());
    if (beginsWith(receivedMessage, "gridc:")) {
        if (currentPlayer == thisPlayer) {
            return;
        }
        QString actedGrid = receivedMessage.section(':', 1);
        playerAction(actedGrid.section(',', 0, 0).toInt(),
                     actedGrid.section(',', 1, 1).toInt());
    }
    if (beginsWith(receivedMessage, "FFc:")) {
        freezeBoard();
        QMessageBox::information(NULL, "对方已投降",
                                 "恭喜您！对方投降，您已获胜！",
                                 QMessageBox::Ok, QMessageBox::Ok);
        win(thisPlayer);
    }
}
bool MiliChess::beginsWith(QString Target, const char *key) {
    int i = 0;
    while (key[i] != '\0') {
        if (Target[i] != key[i]) return false;
        ++i;
    }
    return true;
}
void MiliChess::on_actionDisconnect_triggered() {
    if (isOnlineGame == false) return;
    if (isHost && host) {
        if (host->server) host->server->close();
        delete host;
        host = nullptr;
    }
    if (!isHost && client) {
        if (client->socket) client->socket->disconnectFromHost();
        delete client;
        client = nullptr;
    }
    isOnlineGame = false;
    isHost = false;
    return;
}
void MiliChess::on_actionForfeit_triggered() {
    if (isOnlineGame && (thisPlayer != currentPlayer)) {
        QMessageBox::warning(this, "无法投降", "现在不是您的回合，无法投降",
                             QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    QMessageBox::StandardButtons chosenButton = QMessageBox::question(
        this, "是否确定认输", "您要认输吗？对手将获得胜利");
    if (chosenButton == QMessageBox::StandardButton::Yes) {
        if (isOnlineGame) {
            if (isHost) {
                if (host && host->socket)
                    host->socket->write(QString::fromUtf8("FFh:").toUtf8());
            } else {
                if (client && client->socket)
                    client->socket->write(QString::fromUtf8("FFc:").toUtf8());
            }
        }
        win((PLAYERS)!currentPlayer);
    }
}
void MiliChess::tickReceived(){
    if(!timerRunning)
        return;
    ui->timerLabel->setText(QString::fromUtf8("剩余时间：")+QString::number(--timerTime)+QString::fromUtf8("s"));
    if(timerTime<6)
        ui->timerLabel->setStyleSheet("color:red;");
    else
        ui->timerLabel->setStyleSheet("color:white;");
    if(timerTime==0){
        players[currentPlayer].overTimeCount++;
        if(players[currentPlayer].overTimeCount==3)
            win((PLAYERS)!currentPlayer);
        currentPlayer=(PLAYERS)!currentPlayer;
        turnState=CHOOSE_PIECE;
        timerTime=21;
        resetCursor();
        printGameInfo();
    }

}
