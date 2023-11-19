#include <iostream>
using namespace std;
//int cardAmount;
int slimit, amount1, amount2, cardAmount;
int SplitPoint2(int arr[], int start, int end);
void QuickSort(int a[], int, int n);
void Gameloop(int [], int [], int);
int Roundloop1(int [], int [], int, int);
int Roundloop2(int [], int [], int, int);
    
int  main()
{
    int testgroup;
    cin >> testgroup;
    for(int i = 0; i < testgroup; i++)
    {
    int fLimit, pointLimit,  firstPerson;
    cin >> cardAmount >> fLimit >> pointLimit >> firstPerson;
    slimit = pointLimit * 10 + fLimit + 1;
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
        symbol1[i] = f1[i] + 10 * p1[i];
        symbol2[i] = f2[i] + 10 * p2[i];
        //symbol[0][i] = symbol1[i];
        //symbol[1][i] = symbol2[i];
    }
    
    QuickSort(symbol1, 0, cardAmount);
    QuickSort(symbol2, 0, cardAmount);
    Gameloop(symbol1, symbol2, firstPerson);
    }
    
    return 0;
}
void Gameloop(int a1[], int a2[], int firstPerson)
{
    if(amount1 == 0)
    {    
        cout << "FS wins!"<< endl;
        return;
    }
    else if(amount2 == 0)
    {
        cout << "FR wins!" << endl;
        return;
    }
    int flower, point;

    if(firstPerson == 1) 
    {
        flower = a1[0] % 10;
        point = a1[0] / 10;
        a1[0] = slimit;
        amount1--;
        if(amount1 == 0)
        {    
            cout << "FS wins!"<< endl;
            return;
        }
        firstPerson = Roundloop2(a1, a2, flower, point);
    }
    else 
    {
        flower = a2[0] % 10;
        point = a2[0] / 10;
        a2[0] = slimit;
        amount2--;
        if(amount2 == 0)
        {
            cout << "FR wins!" << endl;
            return;
        }
        firstPerson = Roundloop1(a1, a2, flower, point);
    }


    QuickSort(a1, 0, cardAmount);
    QuickSort(a2, 0, cardAmount);
    Gameloop(a1, a2, firstPerson);

}

int Roundloop1(int a1[], int a2[], int flower, int point)
{
    for(int i = 0; i < cardAmount; i++)
    {
        if(a1[i] % 10 == flower && a1[i] / 10 > point)
        {
            point = a1[i] / 10;
            a1[i] = slimit;
            amount1--;
            return Roundloop2(a1, a2, flower, point);
        }
    }

    return 2;
}

int Roundloop2(int a1[], int a2[], int flower, int point)
{
    for(int i = 0; i < cardAmount; i++)
    {
        if(a2[i] % 10 == flower && a2[i] / 10 > point)
        {
            point = a2[i] /10;
            a2[i] = slimit;
            amount2--;
            return Roundloop1(a1, a2, flower, point);
        }
    }

    return 1;
}

void QuickSort(int arr[], int start, int end)
{
    if(end - start <= 1)
        return;
    int splitPoint = SplitPoint2(arr, start, end);

    QuickSort(arr, start, splitPoint - 1);

    QuickSort(arr, splitPoint + 1, end);

}

int SplitPoint2(int arr[], int start, int end)
{
    int pivot = arr[start];
    int former = start, later = end;
    while(former < later)
    {
        while(former < later && arr[later] >= pivot) later--;
        if(later > former) arr[former] = arr[later];
     
        while(former < later && arr[former] <= pivot) former++;
        if(later > former) arr[later] = arr[former];
    }

    arr[former] = pivot;
    return former;
}