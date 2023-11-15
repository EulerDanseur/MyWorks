#include <iostream>
#include "gameloop.h"
#include "number.h"
#include <cstdlib>
using namespace std;

void Gameloop(int board[][4])
{
    char direction;
    bool gameover = false;
    cin >> direction;
    while(DoGenerateNum(board))
    {
        Move(direction);
    }
}