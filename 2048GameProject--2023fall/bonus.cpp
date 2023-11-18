#include<iostream>
#include<conio.h>
using namespace std;

void Bonus(char selection)
{
    switch (selection)
    {
        case '1': {DoubleOrHalf(); break;}
        case '2': 
    }
    return;
}

void DoubleOrHalf()
{
    printf("\nPrint the row:\n");
    char row = _getche();
    printf("\nPrint the column\n");
    char col = _getche();
    printf("\nPrint the operation, \'/\' means half, \'*\' means double.");
    char operation = _getche();

}
