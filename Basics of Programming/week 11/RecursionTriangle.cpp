#include<iostream>
#include<cmath>
using namespace std;
bool star[1024][1024] = {0}; 
inline int mid(int a, int b)
{
    return (a + b)/2 + 1;
}
void Triangle(int, int, int, int);

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    int size = pow(2, n - 1);
    Triangle(0, size - 1, 0, size - 1);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(star[i][j]) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
    
    return 0;
}

void Triangle(int rows, int rowe, int cols, int cole)
{
    if(rows == rowe)
    {
        star[rows][cols] = 1;
        return;
    }
    
    Triangle(rows, mid(rows, rowe) - 1, cols, mid(cols, cole) - 1);
    Triangle(mid(rows, rowe), rowe, cols, mid(cols, cole) - 1);
    Triangle(rows, mid(rows, rowe) - 1, mid(cols, cole), cole);


}