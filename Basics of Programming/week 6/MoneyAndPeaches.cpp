#include<iostream>
#include<climits>
using namespace std;

bool MonkeyOperation(int, int);

int main()
{
    for(int i = 1; i < INT_MAX; i++)
        if(MonkeyOperation(i, 5))
            return 0;
    
    return 0;
}

bool MonkeyOperation(int peach, int times)
{
    int temp = peach;
    for(int i = 0; i < times; i++)
    {
        temp--;
        if(temp % 5 != 0 || temp <= 0)
            return 0;
        else
            temp = (4 * temp)/ 5;   
    }
    cout << peach << " " << temp << endl;
    return 1;
}