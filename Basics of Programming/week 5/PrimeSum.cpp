#include<iostream>
using namespace std;

bool IsPrime(int n);
void PrimeSubs(int num);

int main ()
{
    int num;
    cin >> num;
    PrimeSubs(num);
    return 0;
}

bool IsPrime(int n)
{
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void PrimeSubs(int num)
{
    for(int i = 2; i <= num; i++)
        if(IsPrime(i))
            for (int j = num; j >= i; j--)
                if (IsPrime(j) && i + j == num)
                {
                     cout << i << " " << j << endl;
                     return;
                }
}