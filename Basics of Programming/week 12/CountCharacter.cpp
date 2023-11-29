#include <iostream>
using namespace std;

void CountChar(string a, int *countNum, int *countLetter);

int main()
{
    string a;
    getline(cin, a);
    int countNum = 0, countLetter = 0;
    CountChar(a, &countNum, &countLetter);

    cout << countNum << ' ' << countLetter;
    return 0;

}

void CountChar(string a, int *countNum, int *countLetter)
{
    for(char i : a)
    {
        if(i >= '0' && i <= '9') 
            (*countNum)++;
        else if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) 
            (*countLetter)++;        
    }
}