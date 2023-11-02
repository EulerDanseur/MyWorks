#include<iostream>
using namespace std;
bool IsPrime(int i);

int main()
{
    int num;
    cin >> num;
    int temp = num;
    for(int i = 2; ; i++)
    if(num % i == 0)
    {
        int times = 0;
        while(temp % i == 0)
        {
            temp /= i;
            times++;
        }
        if(times != 0)
            printf("%d(%d)", i, times);
        if(i >= temp) break;
    }
    return 0;
}

bool IsPrime(int i)
{
    if(i == 2)
        return 1;
    
    for(int j = 2; j * j< i; j++)
    {
        if(i % j == 0)
            return 0;
    }
    return 1;
}