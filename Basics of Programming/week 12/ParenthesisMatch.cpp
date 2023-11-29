#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    string expr;
    getline(cin, expr);
    int flag = 0;
    for(char i : expr)
    {
        if(i == '(') flag++;
        else if(i == ')') flag--;
        if(flag < 0)
        {
            cout << 'N';
            return 0;
        }
    }
    if(flag != 0)
        cout << 'N';
    else
        cout << 'Y';
    return 0;
}