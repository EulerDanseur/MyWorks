#include<iostream>
#include<cmath>
using namespace std;

int f(long long x);
int g(long long x);
int h(long long x);
bool IsPrime(int n);
int times_g = 0;

int main()
{
    long long x, m;
    cin >> x >> m;
    char func;
    for(int i = 0; i < m; i++)
    {
        cin >> func;
        if(func == 'f')
        {   
            x = f(x); 
            //times_g++; 
        }
        else if(func == 'g')
        {    
            x = g(x); 
            //times_g++; 
        }
        else
            x = h(x);
    }
    cout << x;
    return 0;
}

int f(long long x)
{
    long long a = 2 * 1e9;
    long long temp = x + x / 10 + 123456;
    times_g++;
    return min(temp, a - x);
}

int g(long long x)
{
    int digit, expo = 0, temp = x, result = 0;
    do
    {
        digit = temp % 10;
        temp /= 10;
        if(digit % 2 == 0)
        {    
            result += digit * pow(10, expo);
            expo++;
        }

    } while (temp != 0);
    times_g++;
    return result;
}

int h(long long x)
{
    if(IsPrime(times_g))
        return f(g(x));
    else
        return g(f(x));
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
