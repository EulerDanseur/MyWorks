#include<iostream>
#include<iomanip>
using namespace std;

bool IsPrime(int n);
int SumPrime(int x, int y);

int main()
{
    int a, b, c, d, temp1, temp2, sum = 0;
    cin >> a >> b >> c >> d;
    temp1 = max(SumPrime(a, b), SumPrime(c, d));
    temp2 = max(SumPrime(a, c), SumPrime(b, d));
    sum = max(temp1, temp2);
    cout << sum;
    return 0;
}

bool IsPrime(int n)
{
    if (n == 1 || n == 0)
        return 0;
    
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int SumPrime(int x, int y)
{
   int sum = 0;
   for(int i = x; i <= y; i++)
   {
       if(IsPrime(i))
           sum += i;
   }
   return sum; 
}
