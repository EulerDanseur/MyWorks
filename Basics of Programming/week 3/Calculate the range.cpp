#include<iostream>
using namespace std;

int main()
{
    int amount, numinput, x, y, mini, maxi;

    cin >> amount;
    cin >> x;
    cin >> y;
    
    if(amount == 0 || amount == 1)
    {
        cout << 0;
        return 0;
    }   
    
    maxi=max(x,y);
    mini=min(x,y);

    for(int i=1; i <= amount - 2; i++)
    {
        cin >> numinput;
        maxi=max(numinput,maxi);
        mini=min(numinput,mini);
    }
    
    //comparing
    /*
    if(x < y)
        {
            mini=x;
            maxi=y;
        }
    else
        {
            mini=y;
            maxi=x;
        }
    
    
    for(int i=1; i <= amount - 2; i++)
    {
        cin >> numinput;
        if(numinput > maxi )
            maxi = numinput;
        else if(numinput < mini)
            mini = numinput;
    }
    */



    cout << maxi - mini;
    
    
    return 0;
}