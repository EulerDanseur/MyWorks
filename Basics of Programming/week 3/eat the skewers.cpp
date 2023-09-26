#include<iostream>
using namespace std;

int main()
{
    int money, shrimp, egg, eno, left;
    cin >> money;
    
    //calculate the enokitake
    for(eno=0; ; eno++)
    {   
        left =  money - eno*3;
        if ((left % 7) % 5 == 0)
        break;
    }
    egg = (left % 7) / 3;
    shrimp = left / 7;

    cout << eno <<" "<< egg <<" "<< shrimp;
    return 0;

}