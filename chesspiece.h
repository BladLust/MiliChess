#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QPushButton>
#include <QString>

#include "MiliHeader.h"

class ChessPiece : public QPushButton {
    Q_OBJECT
   public:
    SIDE side = UNDETERMINED;
    bool isFlipped = true;
    bool isPressed = false;
    PIECE_TYPE thisType = EMPTY;

    ChessPiece(QWidget *father);
    void unFlip();
    void flip();
    void press();
    void release();
    void reStyle();
};

#endif  // CHESSPIECE_H
