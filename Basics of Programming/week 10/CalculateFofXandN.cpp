#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    double result = x;
    for(int i = 1; i < n+1; i++)
    {
        result = sqrt(result + i);
    }
    printf("%.2f", result);

    return 0;
}