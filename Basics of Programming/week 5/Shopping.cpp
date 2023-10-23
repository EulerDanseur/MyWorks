#include<iostream>
using namespace std;

int Division(int n, int num, int left);

int main()
{
    int n, price, money;
    cin >> n >> price >> money;
    int num = money / price;
    num += Division(n, num, 0);
    cout << num;
    return 0;	
}

int Division(int n, int num, int left)
{
    int addition = (num + left) / n;
    left = (num + left) % n;
    
    if(addition + left < n )
        return addition;
    
    return addition + Division(n, addition, left);    
}