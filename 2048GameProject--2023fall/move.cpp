#include <iostream>
#include "move.h"
#include <cstdlib>
using namespace std;
extern int board[4][4];
extern int score;

void Move(char direction)
{
    score--;

    switch(direction)
    {
        case 'a':
        {
            for(int row = 0; row < 4; row++)
            {
                //restore value
                int temp[4] = {0};
                int index = 0;

                for(int col = 0; col < 4; col++)
                {
                    if(board[row][col] != 0)
                    {
                        temp[index]=board[row][col];
                        index++;   
                    }                
                }
            
                //check the cimbination
                for(int i = 0; i < 4; i++)
                {
                    while(temp[i]==temp[i+1])
                    {
                        score += temp[i];
                        temp[i] *= 2;
                        for(int j = i+1; j < 3; j++)
                        {
                            temp[j] = temp[j+1];
                        }
                        temp[3] == 0;
                    }
                }

                //return to the Board
                for(int col = 0; col < 4; col++)
                    board[row][col] = temp[col]; 
                
            }
            break;
        }

        case 'd':
        {
            for(int row = 0; row < 4; row++)
            {
                //restore value
                int temp[4] = {0};
                int index = 0;

                for(int col = 3; col > -1; col--)
                {
                    if(board[row][col] != 0)
                    {
                        temp[index]=board[row][col];
                        index++;   
                    }                
                }
            
                //check the cimbination
                for(int i = 0; i < 4; i++)
                {
                    while(temp[i]==temp[i+1])
                    {
                        score += temp[i];
                        temp[i] *= 2;
                        for(int j = i+1; j < 3; j++)
                        {
                            temp[j] = temp[j+1];
                        }
                        temp[0] == 0;
                    }
                }

                //return to the Board
                for(int col = 3; col > -1; col--)
                    board[row][col] = temp[col]; 
                
            }
            break;
        }

        case 'w':
        {
            for(int row = 0; row < 4; row++)
            {
                //restore value
                int temp[4] = {0};
                int index = 0;

                for(int col = 0; col < 4; col++)
                {
                    if(board[col][row] != 0)
                    {
                        temp[index]=board[col][row];
                        index++;   
                    }                
                }
            
                //check the cimbination
                for(int i = 0; i < 4; i++)
                {
                    while(temp[i]==temp[i+1])
                    {
                        score += temp[i];
                        temp[i] *= 2;
                        for(int j = i+1; j < 3; j++)
                        {
                            temp[j] = temp[j+1];
                        }
                        temp[3] == 0;
                    }
                }

                //return to the Board
                for(int col = 0; col < 4; col++)
                    board[col][row] = temp[col]; 
                
            }
            break;
        }
    
        case 's':
        {
            for(int row = 0; row < 4; row++)
            {
                //restore value
                int temp[4] = {0};
                int index = 0;

                for(int col = 3; col > -1; col--)
                {
                    if(board[col][row] != 0)
                    {
                        temp[index]=board[col][row];
                        index++;   
                    }                
                }
            
                //check the cimbination
                for(int i = 0; i < 4; i++)
                {
                    while(temp[i]==temp[i+1])
                    {
                        score += temp[i];
                        temp[i] *= 2;
                        for(int j = i+1; j < 3; j++)
                        {
                            temp[j] = temp[j+1];
                        }
                        temp[0] == 0;
                    }
                }

                //return to the Board
                for(int col = 3; col > -1; col--)
                    board[col][row] = temp[col]; 
                
            }
            break;
        }
    }

}

