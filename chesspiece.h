#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QPushButton>
#include "MiliHeader.h"
#include <QString>

class ChessPiece: public QPushButton
{
    Q_OBJECT
public:
    bool isBlue;
    bool isFlipped=true;
    bool isPressed=false;
    PieceType thisType;


    ChessPiece(QWidget* father);
    void unFlip();
    void flip();
    void press();
    void release();
    void reStyle();
};

#endif // CHESSPIECE_H
