#include <iostream>
#include <iomanip>
using namespace std;
void PrintYang(int row);
int Yang(int, int);
int lineTotal;
int main()
{    
    while(1)
    {
        cin >> lineTotal;
        PrintYang(lineTotal);
        //getchar();
        getchar();
    }
    return 0;
}

void PrintYang(int row)
{

    if(row != 1) PrintYang(row - 1);

    for(int i = 0; i <(lineTotal - row); i++)
    {
        printf("      ");
    }


    for(int col = 1; col < row + 1; col++)
    {
        //printf("\t%d\t", Yang(row, col));           
        cout << "      ";
        cout << setw(6) << left << Yang(row, col);
    }

    cout << endl;
}

int Yang(int row, int col)
{
    if(row == 1 || col == 1 || col == row)
        return 1;
    else
        return Yang(row - 1, col) + Yang(row - 1, col - 1);
}



