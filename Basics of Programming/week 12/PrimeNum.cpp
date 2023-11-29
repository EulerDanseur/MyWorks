#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool num[n + 1];
    num[0] = 0; num[1] = 0; num[2] = 1;
    for(int i = 3; i < n; i++)
        num[i] = 1;
    
    for(int i = 2; i < n + 1; i++)
    {
        if(num[i])
        {
            for(int j = i * 2; j < n + 1; j += i)
            {
                num[j] = 0;
            }
        }
    }
    for(int i = 2; i < n + 1; i++)
    if(num[i])
    {
        cout << i <<endl;
    }
    
}