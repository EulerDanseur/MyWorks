#include<iostream>
using namespace std;

int Factorial(int n);
int Combination(int n, int r);

int main()
{
    int n, r;
    cin >> n >> r;
    cout << Combination(n, r);
    return 0;
}

int Factorial(int n)
{
    if(n == 1 || n == 0)
        return 1;
    
    return n * Factorial(n - 1);
}

int Combination(int n, int r)
{
    if(n == 0)
        return 1;
    return Factorial(n) / (Factorial(r) * Factorial(n - r));
}