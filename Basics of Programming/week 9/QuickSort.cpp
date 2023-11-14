#include<iostream>
using namespace std;
void Swap(int *a, int *b);
void QuickSort(int arr[], int start, int end);
int SplitPoint1(int arr[], int start, int end);
int SplitPoint2(int arr[], int start, int end);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    QuickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}

void QuickSort(int arr[], int start, int end)
{
    if(end - start <= 1)
        return;
    int splitPoint = SplitPoint2(arr, start, end);

    QuickSort(arr, start, splitPoint - 1);

    QuickSort(arr, splitPoint + 1, end);

}

int SplitPoint1(int arr[], int start, int end)
{
    int pivot = arr[start];
    int splitPoint = start;
    for(int i = start + 1; i <= end; i++)
    if(arr[i] < pivot)
    {
        splitPoint++;
        Swap(&arr[i], &arr[splitPoint]);
    }
    Swap(&arr[start], &arr[splitPoint]);
    
    return splitPoint;
}

int SplitPoint2(int arr[], int start, int end)
{
    int pivot = arr[start];
    int former = start, later = end;
    while(former < later)
    {
        while(former < later && arr[later] >= pivot) later--;
        if(later > former) arr[former] = arr[later];
     
        while(former < later && arr[former] <= pivot) former++;
        if(later > former) arr[later] = arr[former];
    }

    arr[former] = pivot;
    return former;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}