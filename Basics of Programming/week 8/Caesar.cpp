#include <iostream>
using namespace std;

int main(){
    string Caesar;
    cin >> Caesar;
    for(int i=0;i<26;i++)
    {
        char Caesar2[500];
        
        for(int j=0;j < Caesar.length();j++)
        {
            Caesar2[j]=96+(Caesar[j]-97+i)%26;
        }
        printf("%s\n",Caesar2);
    }
    return 0;
}