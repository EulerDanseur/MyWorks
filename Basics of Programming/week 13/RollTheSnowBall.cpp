#include <iostream>
using namespace std;
void RollingDown(char *, int, int);

int main()
{
    int row ,col;
    cin >> row >> col;

    char field[col][row];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> field[j][i];
    
    
    for(int i = 0; i < col; i++)
    {
        int start = 0;
        for(int j = 0; j < row; j++)
        {
            if(field[i][j] == '#')
            {
                RollingDown(field[i], start, j);
                start = j + 1;
            }
        }
        if(start != row)
        {
            RollingDown(field[i], start, row);
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            cout << field[j][i];
        
        cout << endl;
    }
}

void RollingDown(char *field, int start, int end)
{
    int cnt;
    for(int i = start; i < end; i++)
    {
        if(field[i] == 'o')
        {
            cnt++;
        }
    }
    for(int i = end - 1; i >= start; i--)
    {
        if(cnt != 0)
        {
            field[i] = 'o';
            cnt--;
        }
        else
            field[i] = 'u';
    }

}