#include<iostream>
using namespace std;

int ExchangeNum(int n);

int main()
{
    int n;
    cin >> n;
    cout << ExchangeNum(n);
    return 0;
}

int ExchangeNum(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    
    return (n - 1) * ExchangeNum(n - 2) + (n - 1)*ExchangeNum(n - 1);
}