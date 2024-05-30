#include "Start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Ceil);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    QPropertyAnimation *animation = new QPropertyAnimation(&w,"windowOpacity");
    animation->setDuration(500);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    return a.exec();
}
