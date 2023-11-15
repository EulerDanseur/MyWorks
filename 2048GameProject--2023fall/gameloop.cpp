#include <iostream>
#include "gameloop.h"
#include "number.h"
#include "print.h"
#include "move.h"
#include "bonus.h"
#include <cstdlib>
using namespace std;
extern int board[4][4];

int Gameloop()
{
    char direction;
    int vacantRange = 14;
    int vacantOrder[16] = {0};

    while(vacantRange > 0 || IfCombinable())
    {
        cin >> direction;
        
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

                if(If2048()) return 1;
                
                break;
            }
            default: cout << "wrong input!" << endl;
        }

    }
    
    return 0;
}