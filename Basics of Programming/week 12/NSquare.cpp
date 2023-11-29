#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int square[n][n];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        square[i][j] = 0;
    }
    square[n - 1][n/2] = 1;
    int row = n - 1, col = n/2;
    for(int i = 2; i <= n * n; i++)
    {
        if(!square[(row + 1)%n][(col + 1)%n])
        {
            row = (row + 1) % n;
            col = (col + 1) % n;
            square[row][col] = i;        
        }
        else
        {
            row = (row - 1 + n) % n;
            square[row][col] = i;
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        printf("%-4d", square[i][j]);
        
        cout << endl;
    }
    return 0;
}