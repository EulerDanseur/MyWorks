#include<iostream>
using namespace std;

int main()
{
    //input
    int n, index;
    cin >> n;
    
    int arr[10000];
    for(int i = 0; i < 10000; i++)
        arr[i] = i + 1;
    
    for(int i = 0; i < n; i++)
    {
        cin >> index;
        arr[index - 1] = 0;
    }

    for(int i = 0; i < 10000; i++)
    {
        if(arr[i] != 0)
        {
            cout << arr[i] << endl;
            return 0;
        }
    }
   
}