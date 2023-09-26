#include<iostream>
using namespace std;
int main()
{
    
    int k, b, i, j;
    char m;
    while(m != 'e')
    {
        cin >> k >> b;
        for(i = 10; i >= 0; i--)
        {
            for(j = 1; j <= k * (b + i); j++)
            {
                cout << "  ";
            }
            cout << "*" << endl;
        }
        scanf("%c", &m);
    }
    return 0;

   //int k, b, i, j;

}