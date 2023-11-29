#include <iostream>
using namespace std;

typedef struct
{
    int time;
    int duration;
} custom;

inline int Min(int a[], int n)
{
    int min = 0;
    for(int i = 1; i < n; i++)
        if(a[i] < a[min]) min = i;
    
    return min;
}
void TimeSort(custom * p, int n);
int StrToSec(string);

int main()
{
    int n, win;
    cin >> n >> win;
    int temp[win];
    for(int i = 0; i < win; i++)
        temp[i]  =  28800;
    
    custom cus[n];
    int valid = n;
    string tempStr;
    for(int i = 0; i < n; i++)
    {
        cin >> tempStr >> cus[i].duration;

        if((tempStr).compare("17:00:00") > 0 )
        {
            cus[i].time = 86400;
            valid--;
            continue;
        }

        cus[i].time = StrToSec(tempStr);
        cus[i].duration *= 60; 
    }

    TimeSort(cus, n);


    int index = 0;

    int wait = 0;

    for(int i = 0; i < valid; i++)
    {   
        
        index = Min(temp, win);

        if(temp[index] - cus[i].time > 0)
        {
            wait += (temp[index] - cus[i].time);
            temp[index] += cus[i].duration;
        }
        else
            temp[index] = cus[i].time + cus[i].duration;
    }

    double avgwait = (double)wait / 60 / valid;

    printf("%.1f", avgwait);

    return 0;
}

void TimeSort(custom *cus, int n)
{
    for(int i = 0; i < n - 1; i++)
    for(int j = 0; j < n - i - 1; j++)
    {
        if(cus[j].time > cus[j + 1].time)
        {
            custom temp = cus[j];
            cus[j] = cus[j+1];
            cus[j+1] = temp;
        }
    }
}

int StrToSec(string a)
{
    int sec = 0, base = 36000;
    for(char i : a)
    {
        if(i >= '0' && i <='9')
        { 
            sec += ( (i-'0') * base );
            base/=10;
        }
        else
        {
            base /= 6;
            base *= 10;
        }
    }

    return sec;
}
