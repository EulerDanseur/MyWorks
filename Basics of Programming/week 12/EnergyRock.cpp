#include <iostream>
using namespace std;

int main()
{
    int row, col, a, b, c, size;
    cin >> row >> col;
    int rockrow = row / 2 ;
    int rockcol = col / 2 ;
    size = row * col;
    a = rockrow * rockcol;
    b = a + (row - rockrow) * rockcol + (col - rockcol) * rockrow;
    c = size - b;

    printf("%d\n%d\n%d\n", a, b, c);

    return 0;

}