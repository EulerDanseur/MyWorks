#include<iostream>
#include<cmath>
using namespace std;

int CountIsoNum(int);
bool IsIsoph(int);

int main()
{
    int num;
    cin >> num;
    int amount = CountIsoNum(num);
    cout << amount;

    return 0;
}

int CountIsoNum(int num)
{
    int count = 0;
    for(int i = 1; i <= num; i++)
        if(IsIsoph(i)) count++;

    return count;
}

bool IsIsoph(int n)
{
    int square = n * n;
    int expo = 0, left = square, add = 0;
    do
    {
        add += (left % 10) * pow(10, expo);
        
        if(add == n) return 1;
        else if(add > n) return 0;
        
        expo++;
        left /= 10;
    } while (left != 0);
    return 0;
}