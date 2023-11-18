#include <iostream>
using namespace std;
//int cardAmount;
void QuickSort(int a[], int n);
int main()
{
    int fLimit, pointLimit, cardAmount, firstPerson;
    cin >> cardAmount >> fLimit >> pointLimit >> firstPerson;
    int f1[cardAmount], p1[cardAmount], f2[cardAmount], p2[cardAmount];
    for(int i = 0; i < cardAmount; i++)
        cin >> f1[i];
    for(int i = 0; i < cardAmount; i++)
        cin >> p1[i];
    for(int i = 0; i < cardAmount; i++)
        cin >> f2[i];
    for(int i = 0; i < cardAmount; i++)
        cin >> p2[i];
    
    int symbol1[cardAmount], symbol2[cardAmount];
    for(int i = 0; i < cardAmount; i++)
    {
        symbol1[i] = f1[i] + 10 * p1[i];
        symbol2[i] = f2[i] + 10 * p2[i];
    }

    QuickSort(symbol1, cardAmount);
    QuickSort(symbol2, cardAmount);
    Gameloop(symbol1, symbol2);

}
