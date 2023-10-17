#include<iostream>
using namespace std;

bool IsComplete(int num);
void PrintFactors(int num);

int main ()
{
    int num;
    cin >> num;
    for(int i = 1; i <= num; i++)
    {
        if(IsComplete(i))
            PrintFactors(i);
    }
    return 0;
}

bool IsComplete(int num)
{
    int sum = 0;
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
            sum += i;
    }
    return sum == num;
}

void PrintFactors(int num)
{
    cout << num << " its factors are ";
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
            cout << i << " ";
    }
    cout << endl;
}