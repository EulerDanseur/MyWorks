#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int slimit, amount1, amount2, cardAmount;
void Sort(int [], int n);
void Gameloop(int [], int [], int);
int Roundloop1(int [], int [], int, int, int);
int Roundloop2(int [], int [], int, int, int);
    
int  main()
{
    int testgroup;
    cin >> testgroup;
    for(int i = 0; i < testgroup; i++)
    {
    int fLimit, pointLimit,  firstPerson;
    cin >> cardAmount >> fLimit >> pointLimit >> firstPerson;
    slimit = pointLimit * 1000 + fLimit + 1;
    amount1 = cardAmount, amount2 = cardAmount;

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
    //int symbol[2][cardAmount];
 
    for(int i = 0; i < cardAmount; i++)
    {
        symbol1[i] = f1[i] + 1000 * p1[i];
        symbol2[i] = f2[i] + 1000 * p2[i];
        //symbol[0][i] = symbol1[i];
        //symbol[1][i] = symbol2[i];
    }
    
    Sort(symbol1, cardAmount);
    Sort(symbol2, cardAmount);
    Gameloop(symbol1, symbol2, firstPerson);
    }
    
    return 0;
}

void Gameloop(int a1[], int a2[], int firstPerson)
{
    if(firstPerson == -1)
    {    
        cout << "FS wins!"<< endl;
        return;
    }
    else if(firstPerson == -2)
    {
        cout << "FR wins!" << endl;
        return;
    }
    int flower, point1, point2;

    if(firstPerson == 1) 
    {
        flower = a1[0] % 1000;
        point1 = a1[0] / 1000;
        point2 = INT_MAX;
        a1[0] = slimit;
        amount1--;
        if(amount1 == 0)
        {    
            cout << "FS wins!"<< endl;
            return;
        }
        firstPerson = Roundloop2(a1, a2, flower, point1, point2);
    }
    else 
    {
        flower = a2[0] % 1000;
        point2 = a2[0] / 1000;
        point1 = INT_MAX;
        a2[0] = slimit;
        amount2--;
        if(amount2 == 0)
        {
            cout << "FR wins!" << endl;
            return;
        }
        firstPerson = Roundloop1(a1, a2, flower, point1, point2);
    }


    Sort(a1, cardAmount);
    Sort(a2, cardAmount);
    Gameloop(a1, a2, firstPerson);

}

int Roundloop1(int a1[], int a2[], int flower, int point1, int point2)
{
    for(int i = 0; i < cardAmount; i++)
    {
        if(a1[i] % 1000 == flower && a1[i] / 1000 > point2)
        {
            point1 = a1[i] / 1000;
            a1[i] = slimit;
            amount1--;
            if(amount1 == 0) return -1;
            return Roundloop2(a1, a2, flower, point1, point2);
        }
    }

    return 2;
}

int Roundloop2(int a1[], int a2[], int flower, int point1, int point2)
{
    for(int i = 0; i < cardAmount; i++)
    {
        if(a2[i] % 1000 == flower && a2[i] / 1000 > point1)
        {
            point2 = a2[i] / 1000;
            a2[i] = slimit;
            amount2--;
            if(amount2 == 0) return -2;
            return Roundloop1(a1, a2, flower, point1, point2);
        }
    }
    return 1;
}

void Sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}