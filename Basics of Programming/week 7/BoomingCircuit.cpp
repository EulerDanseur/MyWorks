#include<iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int times = 0;
    for(int sec = 0; sec <= 5 * (n - 1); sec++)
    {
        if(sec % 5 == 0  || ( sec % 4 == 0 && sec / 4 < n)  || (sec % 3 == 0 && sec /3 < n))
            times++;
    }
    cout << times;
    return 0;
}
