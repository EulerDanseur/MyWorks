#include <QApplication>
#include "network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    netWork *nW = new netWork();
    //
    nW->connectNet();
    //  nW->loginShanbay();
    //  nW->queryWord("hello");
    return a.exec();
}
