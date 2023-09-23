#include<iostream>
using namespace std;

int main() 
{
    int mod3, mod5, mod7;
    cin >> mod3 >> mod5 >> mod7;
    
    for (int i = 0; i < 10000 ; i++)
    {
        if (i % 3 == mod3 && i % 5 == mod5 && i % 7 == mod7)
        {
            cout << i;
            getchar();
            getchar();
            return 0;
        }
    }
    
}