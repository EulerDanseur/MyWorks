#include<iostream>
using namespace std;
void Sort(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Sort(arr, n);
    for(int i = 0; i < n;)
    {
        int count = 1;
        for(int j = i+1;j < n; j++)
        {
            if(arr[i] == arr[j])
                count++;
            else
                break;
        }
        if(count > n/2)
        {
            cout << arr[i];
        }
        i = i + count;
    }
    return 0;
}

void Sort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}