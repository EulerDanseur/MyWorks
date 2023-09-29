#include<iostream>
using namespace std;
int main()
{
    int lineNum, half;
    cin >> lineNum;
    half = lineNum / 2 ;

    for(int line = -half; line <= half; line++)
    {
        int space = abs(line);
        int star = lineNum - 2 * space;

        for(int i = 0; i < space; i++)
            cout << " ";
            
        for(int i = 0; i < star; i++)
            cout << "*";

        cout << endl;
    }

    return 0;
}
