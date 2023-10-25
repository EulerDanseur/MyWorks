#include<iostream>
using namespace std;

void TimeMachine(int, int, int, int);

int main()
{
    int h0, m0, s0, times;
    cin >> h0 >> m0 >> s0 >> times;
    TimeMachine(h0, m0, s0, times);
    return 0;
}

void TimeMachine(int h, int m, int s, int times)
{


    int dir, dh, dm;
    cin >> dir >> dh >> dm;
    
    
    while(s > 59)
    {
        m++;
        s -= 60;
    }
    while(s < 0)
    {
        m--;
        s += 60;
    }

    m += dm * dir;
    while(m > 59)
    {
        h++;
        m -= 60;
    }
    while(m < 0)
    {
        h--;
        m += 60;
    }

    h += dh * dir;
    while(h > 23)
        h -= 24;
    while(h < 0)
        h += 24;
    
    times--;
    
    if(times == 0)
    {
        cout << h << " "<< m << " " << s;
        return;
    }
    
    TimeMachine(h, m, s + 5, times); 

}