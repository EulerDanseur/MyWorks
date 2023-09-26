#include<iostream>
using namespace std;
int main ()
{
    int xdate, mdate, i, j;
    cin >> xdate >> mdate;
    for(i = xdate; i <= 365; i+=3)
        
        
        if((i - mdate) % 7 == 0 && i - mdate >= 0)
        {    
            cout << "oui";
            return 0;
        }
        
    /*
       for(j = xdate; j <= 365; j+=7)
            if(i == j)
                {
                    cout << "oui";
                    return 0;
                }*/

                
    cout << "non";
    return 0;
}