#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    string num2;
    cin >> num2;
    int num10 = 0, length = num2.length();
    int i = length - 1;
    for(char num : num2)
    { 
        if(num == '1')
            num10 += pow(2, i);
        i--;
    }
    cout << num10;
    return 0;
}