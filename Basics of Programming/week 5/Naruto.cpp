#include<iostream>
using namespace std;

int MinStep(int monsterNum, int count);

int main()
{
    int monsterNum;
    cin >> monsterNum;
    cout << MinStep(monsterNum, INT_MAX);
    return 0;
}

int MinStep(int monsterNum, int count)
{
    if(monsterNum == 1)
        return 1;

    count = min(count, 1 + MinStep( monsterNum - 1, count));

    if(monsterNum % 2 == 0)
        count = min(count, 1 + MinStep(monsterNum / 2, count));

    if(monsterNum % 3 == 0)
        count = min(count, 1 + MinStep(monsterNum / 3, count));

    return count;
}
