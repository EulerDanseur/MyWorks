#include<iostream>
using namespace std;
int main ()
{
    /*
    int i, j;
    for(i = 1; i <= 9; i++)
    {
        for(j = 1; j <= 9; j++)
            printf("%d\t", i * j);
        printf("\n");
    }
    return 0;
    */


    /*
       int i, j;
    for(i = 1; i <= 9; i++)
    {
        for(j = 1; j < i ; j++)
            printf("\t");
        for(j = i; j <= 9; j++)
            printf("%d\t", i * j);
        printf("\n");
    }
    return 0;
    */

    int i, j;
    for(i = 1; i <= 9; i++)
    {
        for(j = 1; j <= 9; j++)
            if(j < i)
                printf("\t");
            else
                printf("%d\t", i * j);
        printf("\n");
    }
    return 0;
}
    
