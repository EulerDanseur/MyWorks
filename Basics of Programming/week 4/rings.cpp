#include<iostream>
using namespace std;

int main()
{
    int grids, start, foots;
    cin >> grids >> start >> foots;
    bool flag = 1;
    for(int i = 1; i <= foots; i++)
    {
        if (flag == 1)
            start++;
        else 
            start--;

        if(start == grids)
            flag = 0;
        else if(start == 0)
            flag = 1;
    }
    cout << start;
    return 0;
}
    