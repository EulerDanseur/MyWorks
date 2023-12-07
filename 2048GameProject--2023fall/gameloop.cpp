#include <iostream>
#include "gameloop.h"
#include "number.h"
#include "print.h"
#include "move.h"
#include <conio.h>
#include "bonus.h"
#include <cstdlib>
using namespace std;
extern int board[4][4];

void Gameloop()
{
    char direction;
    int vacantRange = 14;
    int vacantOrder[16] = {0};

    while( vacantRange > 0 || IfCombinable() || !If2048() )
    {
        direction = _getche();
        system("cls");
        PrintBoard();
        switch(direction)
        {
            case '1': case '2': case '3': 
            {
                Bonus(direction); break;
            }

            case 'w': case 's': case 'a': case 'd':
            {    
                //move by the direction
                Move(direction);

                //generate new num
                vacantRange = VacantAmount(vacantOrder, vacantRange);
                GenerateNum(vacantOrder, vacantRange);

                //print the result
                PrintBoard();
                
                break;
            }
            default: cout << "wrong input!" << endl;
        }

    }
    
    return;
}