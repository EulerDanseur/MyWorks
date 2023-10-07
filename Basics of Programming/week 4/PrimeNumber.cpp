#include<iostream>
using namespace std;

int IsPrime(int n);

int main()
{
    int n, count = 0;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        if(IsPrime(i))
            count++;
    }
    cout << count;
    return 0;
}

int IsPrime(int n)
{   
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}