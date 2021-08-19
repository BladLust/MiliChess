#include "chesspiece.h"

#include <QApplication>
#include <QEvent>
ChessPiece::ChessPiece(QWidget *father) : QPushButton(father) {}
void ChessPiece::unFlip() {
    isFlipped = false;
    reStyle();
}

void ChessPiece::flip() {
    isFlipped = true;
    reStyle();
}

void ChessPiece::press() {
    isPressed = true;
    reStyle();
}

void ChessPiece::release() {
    // Under Construction
    isPressed = false;
    reStyle();
}
void ChessPiece::reStyle() {
    QString style("border-image: url(:/imgs/");
    style +=
        (!isFlipped)
            ? QString("Unflipped")
            : (QString(TYPE_NAME[thisType]) + QString(side==BLUE ? "B" : "R"));
    style += QString(".png);");
    if (isPressed) {
        style += QString("border: 2px solid;");
    }
    setStyleSheet(style);
}
