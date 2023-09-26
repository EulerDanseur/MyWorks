#include<iostream>
using namespace std;
int main()
{
    int d, sum = 0, i = 1;
    while(i <= 10)
    {
        scanf("%d", &d);
        if(d > 0)
        {
            sum += d;
            ++i;
        }
    }
    printf("%d ", sum);

    return 0;
}

/*
int d, sum = 0, i = 1;
while(i <= 10)
{
 scanf("%d", &d);
 if(d <= 0)
     continue;
 sum += d;
 ++i;
}
printf("%d ", sum);
*/
