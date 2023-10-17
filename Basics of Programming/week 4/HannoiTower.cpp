#include<iostream>
using namespace std;

int MinStep(int n);
void PrintStep(char x, char y, char z, int start, int end);

int main()
{
    int towerNum;
    cin >> towerNum;
    int step = MinStep(towerNum);
    cout << step << " steps" << endl;
    PrintStep('A', 'B', 'C', 1, step);
    return 0;
}

int MinStep(int n)
{
    if(n == 1)
        return 1;
    else
        return 1 + 2 * MinStep(n - 1);
}

void PrintStep(char init, char trans, char goal, int start, int end)
{
    if(start == end)
    {
        printf("step %d: %c to %c\n", start, init, goal);
    }
    else
    {
        int current = (start + end) / 2;
        PrintStep(init, goal, trans, start, current - 1);
        printf("step %d: %c to %c\n", current, init, goal);
        PrintStep(trans, init, goal, current + 1, end);
    }
}