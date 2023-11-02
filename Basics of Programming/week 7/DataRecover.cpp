#include<iostream>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    #ifdef unsigned
    unsigned int low16 = n;
    low16 = low16 & 0xffff;
    unsigned int high16 = n;
    unsigned int times = 1;
    do
    {
        high16 = high16 >> 16;
        times *= 65536;

    } while ( (high16 >> 16) != 0);
    
    unsigned int temp = ( n - low16 ) - high16 * times;
    
    n = temp + low16 * times + high16;
    #endif

    n = ((n & 0x0000ffff) << 16) | ((n & 0xffff0000) >> 16);

    cout << n;
    return 0;
}