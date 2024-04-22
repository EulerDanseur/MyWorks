#include "CalculatorQT.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorQT w;
    w.show();
    return a.exec();
}
