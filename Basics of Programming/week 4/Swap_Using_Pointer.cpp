#include<iostream>
using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;    
}

int main()
{
    int a, b;
    cin >> a >> b;
    Swap(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}