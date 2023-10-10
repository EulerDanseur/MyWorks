#include<iostream>
using namespace std;

int path(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else if (n % 2 == 0)
        return path(n - 1) + path(n - 2) + path(n - 3);
    else    
        return path(n - 1) + path(n - 2);
}

int main()
{
    int knot;
    cin >> knot;
    cout << path(knot);
    return 0;
}


            

