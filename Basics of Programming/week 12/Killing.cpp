#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    bool list[n];
    
    for(int i = 0; i < n; i++)
        list[i] = 1;
    
    int left = n; 
    bool kill = 1, flag = 1;
    while(left != 1)
    {
        for(int i = 0; i < n && flag; i++)
        {
            if(list[i] && kill)
            {
                list[i] = 0;
                kill = 0;
                left--;
                if(left == 1)
                {
                    flag = 0;
                }
            }
            else if(list[i])
            {
                kill = 1;
            }
        }
        kill = 1;

        for(int i = n - 1; i >= 0 && flag; i--)
        {
            if(list[i] && kill)
            {
                list[i] = 0;
                kill = 0;
                left--;
            }
            else if(list[i])
            {
                kill = 1;
            }
        }
        kill = 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(list[i])
        {
            cout << i + 1;
            break;
        }
    }

    return 0;

}