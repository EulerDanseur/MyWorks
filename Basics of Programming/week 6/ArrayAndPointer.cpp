#include<iostream>
using namespace std;

int main()
{
    //int arr[5];
    //int *arrPtr = arr;
    int arr2[4][5]={{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20}};
    
    //int **arr2Ptr = &(&arr2[0])[0];
    
    cout << **arr2;

    return 0;
}
