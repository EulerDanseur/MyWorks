#include<iostream>
using namespace std;

int n;
int Max(int a, int b);
int CountCoins(int coin[], int length);
//int CountCoins(int arr[], int start, int count);

int main()
{
    cin >> n;
    int coin[n];
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    
    int coinMax = CountCoins(coin, n);

    cout << coinMax;
    return 0;
}

int CountCoins(int coin[], int length)
{
    int earn[length];
    earn[0] = coin[0];
    earn[1] = Max(coin[0], coin[1]);
    for(int i = 2; i < length; i++)
        earn[i] = Max(earn[i - 1], earn[i - 2] + coin[i]);
    
    return earn[length - 1];
}

int CountCoins(int arr[], int start, int count)
{
    if(start >= n)
        return count;
    int thisMax = CountCoins(arr, start + 2, count + arr[start]);
    int nextMax = CountCoins(arr, start + 3, count + arr[start + 1]);
    
    return Max(thisMax, nextMax);
    
}

int Max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}