#include <iostream>
using namespace std;

int main()
{
    int candy[11] = {10,2,8,22,16,4,10,6,14,20};
    bool uneven = 1;
    int add0 = 0, count = 0, equal = candy[0];
    do
    {
        add0 = candy[9] / 2 + candy[9] % 2;

        count++;
        
        for(int i = 10; i > 0; i--)
        {
            candy[i - 1] = candy[i - 1] / 2 + candy[i - 1] % 2;
            candy[i] += candy[i - 1];
        }
        candy[0] += add0;

        uneven = 0;
        if(candy[0] != candy[1])
        {
           if(candy[0] == candy[1] + 1)
           {
                //candy[1] ++;
                equal = candy[0];
           }
           else if (candy[0] + 1 == candy[1])
           {
                //candy[0] ++;
                equal = candy[1];
           }
           else
           {
                uneven = 1;
                continue;
           }
        }
        else
        {
            equal = candy[0];
        }
        for(int i = 2; i < 10; i++)
        {
            if((candy[i] != equal) && (equal != candy[i] + 1))
            {
                uneven = 1;
                break;
            }
        }
    }while(uneven);

    cout <<count<<' '<<equal;
    return 0;
}