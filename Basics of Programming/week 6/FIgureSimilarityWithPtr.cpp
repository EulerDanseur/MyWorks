//#include<stdio.h>
//#include<stdbool.h>
#include<iostream>
#include<iomanip>
using namespace std;

double CalcSimilarity(bool **, bool **, int, int);

int main()
{
    int rowNum, colNum;
    cin >> rowNum >> colNum;
    bool **fig1 = , **fig2 = ;

    //input
    for(int i = 0; i < rowNum; i++)
        for(int j = 0; j < colNum; j++)
            cin >> *(*(fig1 + i) + j);

     for(int i = 0; i < rowNum; i++)
        for(int j = 0; j < colNum; j++)
            cin >> *(*(fig2 + i) + j);

    double similarity= CalcSimilarity(fig1, fig2, rowNum, colNum);
    //end input

    return 0;
}

double CalcSimilarity(bool **fig1, bool **fig2, int rowNum, int colNum)
{
    double count = 0;

    for(int row = 0; row < rowNum; row++)
        for(int col = 0; col < colNum; col++)
            if(*(*(fig1 + row) + col) == *(*(fig2 + row) + col))
                count ++;

    double total = rowNum * colNum;
    
    return 100 * count / total;
}