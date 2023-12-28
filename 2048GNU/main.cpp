#include "gameboard.h"
#include <QtWidgets\QApplication>
#include<iostream>
#include<cstdlib>
#include <ctime>
#include <conio.h>
//#include "bonus.h"
#include "move.h"
#include "number.h"




int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
   
    srand(time(0));

    GameBoard window;
        
    window.show();

    return a.exec();
}