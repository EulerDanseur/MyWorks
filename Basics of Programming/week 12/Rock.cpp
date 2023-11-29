#include <iostream>
#include <cmath>
using namespace std;
void Sort(int [], int n);

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cin >> n;
        cout << n;
        return 0;
    }
    
    int length = n;
    int rock[n];
    for(int i = 0; i < n; i++)
        cin >> rock[i];
    
    do
    {
        Sort(rock, length);
        if(rock[0] == rock[1])
        {
            rock[0] = 0;
            rock[1] = 0;
            n -= 2;
        }
        else
        {
            rock[0] = abs(rock[1] - rock[0]);
            rock[1] = 0;
            n--;
        }
        
    } while (n > 1);

    Sort(rock, length);

    if(n == 0)
    {
        cout << 0;
    }
    else
    {
        cout << rock[0];
    }

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
