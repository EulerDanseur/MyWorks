#include<iostream>
using namespace std;
void PrintOrder(int time[], int n);

int main()
{
    int n;
    cin >> n;
    int time[n];
    for(int i = 0; i < n; i++)
        cin >> time[i];
    PrintOrder(time, n);
    return 0;
}

void PrintOrder(int time[], int n)
{
    int order[n];
    for(int i = 0; i < n; i++)
        order[i] = time[i];
    
    for(int i = 0; i < n - 1; i++)
    {
        int max = order[i], maxNum = i;
        for(int j = i; j < n ; j++)
        {
            if(order[j] > max)
            {
                max = order[j];
                maxNum = j;
            }   
        }
        
        int tTemp = order[i];
        order[i]=order[maxNum];
        order[maxNum] = tTemp;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(order[j] == time[i])
                cout << j + 1 << " ";
        }
    }

}