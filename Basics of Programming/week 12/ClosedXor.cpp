#include <iostream>
using namespace std;

int main()
{
while(1)
{
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    
    int temp = 0;
    int flag = 1;
    for(int i = 0; i < n && flag; i++)
    for(int j = i + 1; j < n && flag; j++)
    {
        temp = num[i] ^ num[j];   
        for(int k = 0; k < n; k++)
        {    
            if(temp == num[k])
            {
                flag = 1;
                break;
            }

            flag = 0;
        }
    }

    if(flag) cout << "YAHAhA!";
    else cout << "DaKiKi";
}
}