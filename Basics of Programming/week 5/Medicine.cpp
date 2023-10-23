#include<iostream>
using namespace std;

int main()
{
    int total, people;
    cin >> total >> people;
    int sum = 0, result = 0;
    for(int i = 0; i < people; i++)
    {
        int temp;
        cin >> temp;
        if(sum + temp > total)
            result+=1;
        else
        {
            sum += temp;
        }
    }
    cout << result;
    return 0;
} 