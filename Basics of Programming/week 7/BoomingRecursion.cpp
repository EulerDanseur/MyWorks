#include<iostream>
using namespace std;
int CountBooms(int n, int count);

int main()
{
    int n;
    cin >> n;
    int count = CountBooms(n, 0);
    cout << count;
    return 0;
}

int CountBooms(int n, int count)
{
    if(n == 1)
    {
        count++;
        return count;
    }
    n--;
    int flag34 = (3 * n % 4 == 0), flag35 = (3 * n % 5 == 0), flag45 = (4 * n % 5 == 0);
    int flag = flag34 + flag35 + flag45;
    switch(flag)
    {
        case 0: count+=3; break;
        case 1: count+=2; break;
        case 2: 
        {
            if(flag45) count++;
            else count+=2;
            break;    
        }
        case 3: count++;break;
    }

    return CountBooms(n, count);
}