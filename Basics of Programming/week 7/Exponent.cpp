#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long double ExpSeries(int, int);

int main()
{
    int x;
    int precision;
    cin >> x >> precision;
    long double result = ExpSeries(x, precision);
    cout << setprecision(precision + 1) <<result;
    return 0;
}

long double ExpSeries(int x, int precision)
{
    long double result = 1, check = 1;
    long double term = 1, k = x, b = 1;
    long long a = 1;
    if(x == 0) return result;
    long double deviation = pow(0.1, precision);
    for(int i = 1;;i++)
    {
        //series
        //term *= (k / i);
        
        a *= k;
        b *= i;
        term = a / b;
        result += term;
        
        //check the precision
        if(abs(result - check) <= deviation)
            break;
        else
            check = result;
    }
    return result;

}