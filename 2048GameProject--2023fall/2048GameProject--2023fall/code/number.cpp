#include <cstdlib>
#include <ctime>
#include "number.h"
using namespace std;
int board[4][4];
int score = 0;

int RandomNum()
{
    rand();

    int flag = (int)(100.0 * rand() / RAND_MAX);

    //90 percent 2, 10 percent 4 
    if (flag < 10)
        return 4;
    else
        return 2;

}

int RandomOrder(int vacantOrder[], int range)
{
    rand();

    //randomly generate a number, and take it from the VacantArray
    int idx = range * rand() / RAND_MAX;
    
    return vacantOrder[idx];
}

void GenerateNum(int vacantOrder[], int range)
{
    if (range == 0) return;

    int randomOrder = RandomOrder(vacantOrder, range);
    
    board[OrderToRow(randomOrder)][OrderToCol(randomOrder)] = -RandomNum();
}

int VacantAmount(int vacantOrder[], int indexVacant)
{

    indexVacant = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
            {
                //using vacantOrder to restore the vacant positions
                vacantOrder[indexVacant] = PlaceToOrder(i, j);
                indexVacant++;
            }

    return indexVacant;

}

bool IfCombinable()
{
    for (int i = 1; i < 3; i++)
    {
        if (
            board[0][i] == board[0][i - 1]
            || board[0][i] == board[0][i + 1]
            || board[3][i] == board[3][i + 1]
            || board[3][i] == board[3][i - 1]
            || board[i][0] == board[i + 1][0]
            || board[i][0] == board[i - 1][0]
            || board[i][3] == board[i + 1][3]
            || board[i][3] == board[i - 1][3]
            )
            return true;
    }
    for (int row = 1; row < 3; row++)
        for (int col = 1; col < 3; col++)
            if (board[row][col] == board[row + 1][col]
                || board[row][col] == board[row - 1][col]
                || board[row][col] == board[row][col - 1]
                || board[row][col] == board[row][col + 1]) return true;

    return false;
}

bool If2048()
{
    for (int row = 0; row < 4; row++)
        for (int col = 0; col < 4; col++)
            if (board[row][col] == 2048) return true;

    return false;
}

int PlaceToOrder(int row, int col)
{
    return (row) * 4 + col;
}

int OrderToRow(int order)
{
    return order / 4;
}

int OrderToCol(int order)
{
    return order % 4;
}

