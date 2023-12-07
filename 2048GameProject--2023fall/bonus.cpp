#include<iostream>
#include<conio.h>
#include"print.h"
#include "bonus.h"
using namespace std;
extern int board[4][4];
extern int score;
int dof = 2;

void Bonus(char selection)
{
    switch (selection)
    {
        case '1': {DoubleOrHalf(); break;}
        //case '2': {ClearOneNum(); break; }
    }
    return;
}

void DoubleOrHalf()
{
    if (dof > 0)
    {
        printf("\nPrint the row:\n");
        char row = _getche() - '0';
        printf("\nPrint the column\n");
        char col = _getche() - '0';
        if (board[row - 1][col - 1] == 0)
        {
            cout << "\nNull!!!\n";
            return;
        }
        printf("\nPrint the operation, \'/\' means half, \'*\' means double.");
        char operation = _getche();
        switch (operation)
        {
        case '/':
        {
            if (board[row - 1][col - 1] == 2)
            {
                cout << "\n2 is the minimum!!\n";
                return;
            }
            board[row - 1][col - 1] /= 2;
            break;
        }
        case '*':
        {
            board[row - 1][col - 1] *= 2;
            break;
        }
        }
        dof--;
        score -= 100;
        PrintBoard();
    }
    else
    {
        cout << "\nno more skill one!!!!\n";

    }
}

