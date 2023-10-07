#include<iostream>
using namespace std;

int main()
{
    string m;
    cin >> m;
    int multiple = 1;
    while(m.length() > 1)
    {    
        for(int digit : m)
        {
            if(digit == 48)
                continue;
            //expel 0

            digit-=48;
            multiple*=digit;
        }

        m = to_string(multiple);

        multiple = 1;
    }
    
    cout << m;
    return 0;
}