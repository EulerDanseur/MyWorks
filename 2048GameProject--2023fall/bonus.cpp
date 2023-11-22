#include<iostream>
#include<conio.h>
#include"print.h"
#include "bonus.h"
using namespace std;
extern int board[4][4];

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
    printf("\nPrint the row:\n");
    char row = _getche() - '0';
    printf("\nPrint the column\n");
    char col = _getche() - '0';
    printf("\nPrint the operation, \'/\' means half, \'*\' means double.");
    char operation = _getche();
    switch (operation)
    {
    case '/':
    {
        board[row-1][col-1] /= 2;
        break;
    }
    case '*':
    {
        board[row-1][col-1] *= 2;
        break;
    }
    }
    
    PrintBoard();
}