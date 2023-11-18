#include<iostream>
#include<cstdlib>
#include <ctime>
#include "bonus.h"
#include "gameloop.h"
#include "move.h"
#include "number.h"
#include "print.h"
#include "startandend.h"
int score = 0;
int board[4][4]={0};

int main()
{
    srand(time(0));
    GameStart();
    Gameloop();
    GameEnd();

    return 0;
}