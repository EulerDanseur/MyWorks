#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int result = num & 1;
    
    if(result)
        cout << "odd";
    else
        cout << "even";

    return 0;
}