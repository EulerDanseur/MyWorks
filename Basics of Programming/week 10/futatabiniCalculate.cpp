#include <iostream>
using namespace std;
inline double Division(double x, double n);

int main()
{
    double x, n;
    cin >> x >> n;
    printf("%.2f", Division(x, n));
    return 0;
}

inline double Division(double x, double n)
{
    if(n == 1.00)
        return x/(1 + x);
    
    return x/(n + Division(x, n - 1));

}