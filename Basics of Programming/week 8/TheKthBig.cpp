#include<iostream>
using namespace std;
void Sort(int arr[], int n);

int main()
{
    int n, k;
    cin >> n ;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    Sort(arr, n);
    cout << arr[k-1];
    return 0;
}

void Sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

