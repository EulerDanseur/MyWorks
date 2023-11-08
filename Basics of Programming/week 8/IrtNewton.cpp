#include <iostream>
#include <iomanip>
using namespace std;

//double x = 0, temp = 0;
double ItrNewton(double a, double b, double c, double d);

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(2) << ItrNewton(a, b, c, d);
}

double ItrNewton(double a, double b, double c, double d)
{
    static double x = 0, temp = 0;
    if(b == 0 && c == 0 && d == 0)
    {
        return 0.00;
    }
    else if(b == 0 && c == 0)
    {
        return -d/a;
    }
    temp = x - ((a * x * x * x) + (b * x * x) + (c * x) + d)/(3 * a * x * x + 2 * b * x + c);
    if(temp - x <= 1e-6 || temp - x >= -1e-6)
    {
        return temp;
    }
    else 
    {
        x = temp;
        return ItrNewton(a, b, c, d);
    }
}