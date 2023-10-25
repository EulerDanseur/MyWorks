#include<iostream>
using namespace std;

double ComputeLineK(double x1, double y1, double x2, double y2);
double ComputeLineB(double x1, double y1, double x2, double y2);
void PrintEquation(double k, double b);

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2)
    {
        cout << "x=" << x1;
        return 0;
    }

    double k = ComputeLineK(x1, y1, x2, y2);
    double b = ComputeLineB(x1, y1, x2, y2);

    PrintEquation(k, b);

    return 0;
}

double ComputeLineK(double x1, double y1, double x2, double y2)
{
    return (y2 - y1) / (x2 - x1);
}

double ComputeLineB(double x1, double y1, double x2, double y2)
{
    return y1 - x1 * ComputeLineK(x1, y1, x2, y2);
}

void PrintEquation(double k, double b)
{
    if(k == 0)
        cout << "y=" << b;
    else if(k == 1 && b == 0)
        cout << "y=x";
    else if(k == 1)
        cout << "y=x+" << b;
    else
        cout << "y=" << k << "x+" << b;
}