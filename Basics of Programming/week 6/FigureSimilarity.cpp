//#include<stdio.h>
//#include<stdbool.h>
#include<iostream>
#include<iomanip>
using namespace std;

double CalcSimilarity(bool *, bool *, int, int);

int main()
{
    int rowNum, colNum;
    cin >> rowNum >> colNum;
    
    bool fig1[rowNum][colNum], fig2[rowNum][colNum];
    
    //input
    for(int i = 0; i < rowNum; i++)
        for(int j = 0; j < colNum; j++)
            cin >> fig1[i][j];

     for(int i = 0; i < rowNum; i++)
        for(int j = 0; j < colNum; j++)
            cin >> fig2[i][j];
    //end input
    bool *address1 = &fig1[0][0], *address2 = &fig2[0][0];
    double similar=CalcSimilarity(address1, address2, rowNum, colNum);

    double count = 0;
    
    for(int i = 0; i < rowNum; i++)
        for(int j = 0; j < colNum; j++)
            if(fig1[i][j] == fig2[i][j])
                count++;

    double total = (rowNum) * (colNum);
    
    double similarity =100 * count / total ;

    cout << setprecision(4) << similarity << endl;
    cout << setprecision(4) << similar;

    return 0;
}

double CalcSimilarity(bool *fig1, bool *fig2, int rowNum, int colNum)
{
    double count = 0;

    for(int row = 0; row < rowNum; row++)
        for(int col = 0; col < colNum; col++)
            if(*((fig1 + row) + col) == *((fig2 + row * colNum) + col))
                count ++;

    double total = rowNum * colNum;
    
    return 100 * count / total;
}