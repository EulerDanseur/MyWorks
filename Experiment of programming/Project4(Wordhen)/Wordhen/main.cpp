#include "Start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Ceil);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
