#include<iostream>
using namespace std;

bool IsSpecial(int num);
int main()
{
    int numAmount, num, specialAmount = 0;
    cin >> numAmount;
    if (numAmount == 0) 
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < numAmount; i++)
    {
        cin >> num;
        if(IsSpecial(num))
            specialAmount++;
    }
    cout << specialAmount;
    return 0;
}

bool IsSpecial(int num)
{
    int unitDigit = num % 10, digit, sum = 0;
    do
    {   
        num /= 10;
        digit = num % 10;
        sum += digit;

    } while (num > 0);
    
    return unitDigit > sum;
}