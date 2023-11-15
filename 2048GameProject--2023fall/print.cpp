#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "print.h"

void PrintBoard(int board[][4])
{   
    //clear the screen
    system("cls");

    //print the numbers
    printf("%d\t%d\t%d\t%d\t\n", board[0][0], board[0][1],board[0][2], board[0][3]);
    printf("%d\t%d\t%d\t%d\t\n", board[1][0], board[1][1],board[1][2], board[1][3]);
    printf("%d\t%d\t%d\t%d\t\n", board[2][0], board[2][1],board[2][2], board[2][3]);
    printf("%d\t%d\t%d\t%d\t\n", board[3][0], board[3][1],board[3][2], board[3][3]);
    printf("\n");   
}

void PrintScore(int score)
{
    printf("Score: %d\n", score);
}
