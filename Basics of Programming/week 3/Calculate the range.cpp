#include<iostream>
using namespace std;
int main()
{
    int amount, numinput, x, y, min, max;

    cin >> amount;
    cin >> x;
    cin >> y;
    
    if(amount == 0 || amount == 1)
    {
        cout << 0;
        return 0;
    }   
    
    if(x < y)
        {
            min=x;
            max=y;
        }
    else
        {
            min=y;
            max=x;
        }


    for(int i=1; i <= amount - 2; i++)
    {
        cin >> numinput;
        if(numinput > max )
            max = numinput;
        else if(numinput < min)
            min = numinput;
    }
    
    cout << max - min;
    
    
    return 0;
}