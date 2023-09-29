#include<iostream>
using namespace std;
int main()
{
    int lineNum, half;
    cin >> lineNum;
    half = lineNum / 2 ;
    
    for(int line = half; line > 0; line--)
    {
        for(int space = line; space > 0; space--)
            cout << " ";
        for(int star = 1; star <= lineNum - 2*line; star++)
            cout << "*";
        cout << endl;
    }

    for(int star = 1; star <= lineNum; star++)
        cout << "*";
    cout << endl;
    
    for(int line = 1; line <= half; line++)
    {
        for(int space = 1; space <= line; space++)
            cout << " ";
        for(int star = 1; star <= lineNum - 2*line; star++)
            cout << "*";
        cout << endl;
    }
    
    return 0;
}