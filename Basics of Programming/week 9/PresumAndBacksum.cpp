#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], fsum[n], bsum[n];
    //input a, fsum
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0)
        {
            fsum[i]=a[i];
            continue;
        }
        fsum[i] = fsum[i - 1] + a[i];
    }
    //assign bsum
    bsum[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
        bsum[i] = bsum[i + 1] + a[i];
    
    //counting
    int count = 0;
    
    //since the intension of the question is vague, there would be 2 probably solves.
    //1. the fsum and bsum must be compared for the same i.
    for(int i = 0; i < n; i++)
        if(fsum[i] == bsum[i]) count++;
    
    //2. for different i.
    /*
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(fsum[i] == bsum[j]) count++;
    */

   cout << count;
   return 0;

}