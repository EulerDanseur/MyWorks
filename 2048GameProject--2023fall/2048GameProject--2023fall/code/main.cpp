#include "My2048.h"
#include <ctime>
#include <cstdlib>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    My2048 w;
    w.show();
    return a.exec();
}
