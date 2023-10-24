#include<iostream>
using namespace std;

int Linemax(int line, int matrix[5][5]);
int Columnmin(int column, int matrix[5][5]);


int main()
{
    int matrix[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> matrix[i][j];

    int flag = 0;
    for(int line = 0; line < 5; line++)
    {
        for(int column = 0; column < 5; column++)
        {
            if(matrix[line][column] == Linemax(line, matrix) 
                && matrix[line][column] == Columnmin(column, matrix))
            {
                cout << line + 1 <<" "<< column + 1<< " "<< matrix[line][column];
                flag++;
            }
        }
    }

    if(flag == 0)
    {
        cout <<"not found";
    }
    
    
    return 0;
}

int Linemax(int line, int matrix[5][5])
{
    int max = INT_MIN;
    for(int j = 0; j < 5; j++)
    {
        int num = matrix[line][j];

        if(num > max)
        {
            max = matrix[line][j];
        }
    }
    return max;
}

int Columnmin(int column, int matrix[5][5])
{
    int min = INT_MAX;
    for(int j = 0; j < 5; j++)
    {
        if(matrix[j][column] < min)
        {
            min = matrix[j][column];
        }
    }
    return min;
}