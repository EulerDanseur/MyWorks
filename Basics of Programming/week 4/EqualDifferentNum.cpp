#include<iostream>
using namespace std;
#include<cmath>

int IsEqualDifferentNum(int num);
int TypeOfNum(int num);
int Length(int num);

int main()
{
    int row;
    cin >> row;
    int num;
    for(int i = 1; i <= row; i++)
    {
        cin >> num;
        cout << IsEqualDifferentNum(num) << endl;        
    }
}

int IsEqualDifferentNum(int num)
{
    if(num <= 10)
        return -1;
    else if(num > 10 && num < 100) 
    {   
        if(num % 10 == 0 || num % 10 - num / 10 == 0)
            return -1;
        else
            return TypeOfNum(num);
    }

    int digit1 = num % 10, digit2 = (num / 10) % 10, temp = num / 100;	
    
    int diff = digit1 - digit2;
    
    if (digit1 == 0)
    {
        return -1;
    }
    
    while (temp != 0)
    {
       digit1 = digit2;
       digit2 = temp % 10;
       if(diff != digit1 - digit2 || digit2 == 0 || diff == 0)
           return -1;
       temp /= 10;
    }
    return TypeOfNum(num);
}

int TypeOfNum(int num)
{
    int length = Length(num);
    int high = num / pow(10, length - 1);
    int low = num % 10;
    return high + low;
}

int Length(int num)
{
    int length = 0;
    while(num != 0)
    {
        num /= 10;
        length++;
    }
    return length;
}