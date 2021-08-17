#include "milichess.h"
#include "ui_milichess.h"
static int horAnchor[]={4,91,179,267,354};
static int verAnchor[]={7,48,91,133,175,218,354,395,438,481,523,566};
MiliChess::MiliChess(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiliChess)
{
    ui->setupUi(this);
#ifdef Q_OS_MACOS
    setFixedHeight(636);
#endif

}

MiliChess::~MiliChess()
{
    delete ui;
}

// Width:   434 px
