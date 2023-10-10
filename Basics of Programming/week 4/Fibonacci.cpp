#include<iostream>
using namespace std;

long long FibRecurse(int n);
int count=0;
int main()
{
    int num;
    cin >> num;
    cout << FibRecurse(num)<< " " << count;

    return 0;
}

long long FibRecurse(int n)
{   
    count++;
    if (n == 2 || n == 1)
        return 1;
    else 
        return FibRecurse(n - 2) + FibRecurse(n - 1);
}

int FibCow(int year)
{
    int fib1 = 1, fib2 = 1, fib3 = 1, temp;
    if(year < 4)
        return 1;
    else
        for(int i = 4; i <= year; i++)
        {
            temp = fib1 + fib3;
            fib1 = fib2;
            fib2 = fib3;
            fib3 = temp;
        }
    return temp;
}
/*
6

5 4

3 4 2 3
1 2 2 3 1 2 
1 2
*/