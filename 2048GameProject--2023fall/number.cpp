#include <iostream>
#include <cstdlib>
#include "number.h"
using namespace std;

//#define test 1;

#ifdef test;
int main()
{   
    srand(time(0));

    int count2 = 0, count4 = 0;

    for(int i = 0; i < 1000; i++)
    {
        int num = GenerateNum();
        cout << num ;
        if(num == 2) count2++;
        else    count4++;
    }
    cout  << endl << count2 << endl << count4;
}
#endif

int RandomNum()
{
    rand();

    int flag = (int)(10.0 * rand() / RAND_MAX);

    #ifdef test;
        cout << flag << " ";
    #endif

    if(flag < 4)
        return 4;
    else
        return 2;

}

int RandomPlace()
{

}

void GenerateNum()
{

}

inline int PlaceToOrder(int row, int col)
{
    return (row) * 4 + col;
}

inline int OrderToRow(int order)
{
    return order / 4;
}

inline int OrderToCol(int order)
{
    return order % 4;
}





