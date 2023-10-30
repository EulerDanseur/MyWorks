#include<iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a ^ b ^ c)<<endl;
    a = 5, b = 9;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b;

    return 0;
}