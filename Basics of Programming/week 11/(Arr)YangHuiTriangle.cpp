#include <iostream>
#include <iomanip>
using namespace std;
//void PrintYang(int row);
//int Yang(int, int);
int lineTotal;
int main()
{    
    while(1)
    {
        cin >> lineTotal;
        unsigned ** yang = new unsigned * [lineTotal];
        for(int row = 0; row < lineTotal; row++)
        {
            for(int i = 0; i <(lineTotal - row - 1); i++)
            {
                cout << setw(8) << ' ';
            }

            yang[row] = new unsigned[row+1];
            for(int col = -1; col < row; )
            {
                col++;
                if(col == 0 || col == row || row == 0)
                    yang[row][col] = 1;
                else
                    yang[row][col] = yang[row - 1][col] + yang[row - 1][col - 1];
                
                cout << setw(8) << ' ';
                cout << setw(8) << left << yang[row][col];
            }
            
            if(row >= 2)
            {    
                
                delete []yang[row - 2];
                yang[row - 2] = NULL;
            }

            cout << endl;
        
        }
        delete []yang[lineTotal - 1], yang[lineTotal - 2];
        yang[lineTotal - 1] = NULL, yang[lineTotal - 2] = NULL;

        delete []yang;
        yang = NULL;
    }
    return 0;
}

/* void PrintYang(int row, int **yang)
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



 */