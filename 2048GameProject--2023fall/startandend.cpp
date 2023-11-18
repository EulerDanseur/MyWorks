#include <iostream>
#include <cstdlib>
#include "print.h"
#include "number.h"
#include <conio.h>
extern int board[4][4];
extern int score;
using namespace std;

void GameStart()
{
    PrintRule();
    score = 0;
    PrintBoard();
    //generate the 2 in the corner
    int corner[4] = {0, 3, 12, 15};
    int first = rand() / RAND_MAX * 3;
    board[OrderToRow(corner[first])][OrderToCol(corner[first])] = 2;
    
    int second = 0;
    do
    {
        second = 15 * rand() / RAND_MAX;

    } while (second == corner[first]);
    board[OrderToRow(second)][OrderToCol(second)] = 2;
    
    PrintBoard(); 

}

void GameEnd()
{
    if(If2048())
        cout << "Win!"<< endl;
    else
        cout << "Zannen~" << endl;

    cout << "Your score is "<< score << endl;

    cout << "Press 'e' to exit.";
    
    char flag = 0;

    do
    {
        flag = _getche();

    } while (flag != 'e');
    

}