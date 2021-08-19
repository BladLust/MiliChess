#include <QApplication>

#include "milichess.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MiliChess w;
    w.show();
    return a.exec();
}
