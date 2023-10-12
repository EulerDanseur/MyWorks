#include<iostream>
using namespace std;

int CountPath(int n);

int main()
{
    int n;
    cin >> n;
    cout << CountPath(n);
    return 0;
}

int CountPath(int n)
{
    if(n == 1 || n == 0)
        return 1;
    else   
        return CountPath(n - 1) + CountPath(n - 2);
}