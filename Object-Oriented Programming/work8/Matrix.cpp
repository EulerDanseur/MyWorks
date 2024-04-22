#include <iostream>
using namespace std;
class Matrix
{
    int **data;
    int rows, cols;
public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c)
    {
        if (rows > 0 && cols > 0)
        {
            data = new int * [rows];
            for (int i = 0; i < rows; ++i)
            {
                data[i] = new int[cols];
            }
        }
    }

    int &operator()(int r, int c)
    {
        return data[r][c];
    }

    int *operator[](int r)
    {
        return data[r];
    }

    void operator=(Matrix &m)
    {
        rows = m.rows;
        cols = m.cols;
        if (rows > 0 && cols > 0)
        {
            data = new int * [rows];
            for (int i = 0; i < rows; ++i)
            {
                data[i] = new int[cols];
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = m.data[i][j];
            }
        }
    }

};

int main()
{
    Matrix m1(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            m1[i][j] = i * 4 + j;
        }
    }
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << m1(i, j) << ", ";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Matrix m2;
    m2 = m1;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << m2[i][j] << ", ";
            m2[i][j] += 1;
        }
        cout << endl;
    }
    cout << "next" << endl;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << m1(i, j) << ", ";
        }
        cout << endl;
    }
    cout << "next" << endl;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << m2(i, j) << ", ";
        }
        cout << endl;
    }
    return 0;
}
