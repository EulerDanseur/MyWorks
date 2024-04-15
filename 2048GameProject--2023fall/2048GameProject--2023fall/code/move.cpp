#include "move.h"
#include "My2048.h"

extern int board[4][4];
extern int score;
int movable = 0;

void Move(int direction)
{
    if(score > 0) score--;
    
    switch (direction)
    {
    case 'A':
    case Qt::Key_Left:
    {
        for (int row = 0; row < 4; row++)
        {
            //restore value
            int temp[4] = { 0 };
            int index = 0;

            for (int col = 0; col < 4; col++)
            {
                if (board[row][col] != 0)
                {
                    temp[index] = board[row][col];
                    index++;
                   
                }

            }

            //check the cimbination
            for (int i = 0; i < 4; i++)
            {
                if (temp[i] == temp[i + 1])
                {
                    
                    score += temp[i];
                    if(temp[i] != 0) temp[i] = 2 * temp[i] + 4096;
                    for (int j = i + 1; j < 3; j++)
                    {
                        temp[j] = temp[j + 1];
                    }
                    temp[3] = 0;
                }
            }

            //return to the Board
            for (int col = 0; col < 4; col++)
            {
                if (board[row][col] != temp[col])
                    movable = 1;
                board[row][col] = temp[col];
            }
        }
        break;
    }

    case 'D':
    case Qt::Key_Right:
    {
        for (int row = 0; row < 4; row++)
        {
            //restore value
            int temp[4] = { 0 };
            int index = 3;

            for (int col = 3; col > -1; col--)
            {
                if (board[row][col] != 0)
                {
                    
                    temp[index] = board[row][col];
                    index--;
                }

            }

            //check the combination
            for (int i = 3; i >= 0; i--)
            {
                if (temp[i] == temp[i - 1])
                {
                    score += temp[i];
                    if (temp[i] != 0) temp[i] = 2 * temp[i] + 4096;
                    for (int j = i - 1; j > 0; j--)
                    {
                        temp[j] = temp[j - 1];
                    }
                    temp[0] = 0;
                }
            }

            //return to the Board
            for (int col = 3; col > -1; col--)
            {
                if(board[row][col] != temp[col])
                    movable = 1;
                board[row][col] = temp[col];
            }
        }
        break;
    }

    case 'W':
    case Qt::Key_Up:
    {
        for (int row = 0; row < 4; row++)
        {
            //restore value
            int temp[4] = { 0 };
            int index = 0;

            for (int col = 0; col < 4; col++)
            {
                if (board[col][row] != 0)
                {

                    temp[index] = board[col][row];
                    index++;
                }

            }

            //check the cimbination
            for (int i = 0; i < 4; i++)
            {
                if (temp[i] == temp[i + 1])
                {
                    score += temp[i];
                    if (temp[i] != 0) temp[i] = 2 * temp[i] + 4096;
                    for (int j = i + 1; j < 3; j++)
                    {
                        temp[j] = temp[j + 1];
                    }
                    temp[3] = 0;
                }
            }

            //return to the Board
            for (int col = 0; col < 4; col++)
            {
                if (board[col][row] != temp[col])
                    movable = 1;
                board[col][row] = temp[col];
            }
        }
        break;
    }

    case 'S':
    case Qt::Key_Down:
    {
        for (int row = 0; row < 4; row++)
        {
            //restore value
            int temp[4] = { 0 };
            int index = 3;

            for (int col = 3; col > -1; col--)
            {
                if (board[col][row] != 0)
                {
                    
                    temp[index] = board[col][row];
                    index--;
                }

            }

            //check the combination
            for (int i = 3; i >= 0; i--)
            {
                if (temp[i] == temp[i - 1])
                {
                    score += temp[i];
                    if (temp[i] != 0) temp[i] = 2 * temp[i] + 4096;
                    for (int j = i - 1; j > 0; j--)
                    {
                        temp[j] = temp[j - 1];
                    }
                    temp[0] = 0;
                }
            }

            //return to the Board
            for (int col = 3; col > -1; col--)
            {
                if (board[col][row] != temp[col])
                    movable = 1;
                board[col][row] = temp[col];
            }
        }
        break;
    }
    }

}

