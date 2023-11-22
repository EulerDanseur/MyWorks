#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    
    int mount[m + 2][n + 2] = {0};
    for(int i = 0; i < m + 2; i++)
    for(int j = 0; j < n + 2; j++)
        mount[i][j] = 0;
    
    for(int i = 1; i < m + 1; i++)
    for(int j = 1; j < n + 1; j++)
        cin >> mount[i][j];

    int outline = 0;
    for(int i = 1; i < m + 1; i++)
    for(int j = 1; j < n + 1; j++)
    {
        if(mount[i][j] == 0)
            continue;
        
        if(mount[i - 1][j] == 0) outline++;
        if(mount[i + 1][j] == 0) outline++;
        if(mount[i][j - 1] == 0) outline++;
        if(mount[i][j + 1] == 0) outline++;
    }

    cout << outline;

    return 0;

}