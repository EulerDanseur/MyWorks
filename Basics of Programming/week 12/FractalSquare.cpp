#include <iostream>
using namespace std;
inline int IntPow(int base, int expo)
{
    int basic = base;
    base = 1;
    for(int i = 0; i < expo; i++)
        base*= basic;
    return base;
}

inline void Fractal(bool square[][1024], int row, int col, int size);

int main()
{
    int k;
    cin >> k;
    int size = IntPow(2, k+1);
    bool square[size][1024];

    for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
        square[i][j] = 1;

    Fractal(square, 0, 0, size);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        if(square[i][j])
            cout << "1 ";
        else 
            cout << "  ";
    
        cout << endl;
    }
    getchar();getchar();
    return 0;
}


inline void Fractal(bool square[][1024], int row, int col, int size)
{
    if(size == 2) return;

    for(int i = row + size / 4; i < row + size / 2 + size / 4; i++)
    for(int j = col + size / 4; j < col + size / 2 + size / 4; j++)
        square[i][j] = 0;
    
    size /= 2;
    Fractal(square, row, col, size);
    Fractal(square, row, col + size, size);
    Fractal(square, row + size, col, size);
    Fractal(square, row + size, col + size, size);
}