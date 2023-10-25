//四方定理计数 
#include<iostream>
#include<cmath>
using namespace std;
int count_g = 0;
void CountWays(int, int, int);

int main ()
{
    int num;
    cin >> num;
    CountWays(num, 4, num);
    cout << count_g;
    return 0;
}

void CountWays(int num, int times, int range)
{
    if(times < 0)
        return;
    else if(num == 0)
    {
        count_g++;
        return;
    }
    else if(num < 0)
        return;

    for(int i = range; i >= 0; i-- )
        CountWays(num - i*i, times - 1, i);
    
}