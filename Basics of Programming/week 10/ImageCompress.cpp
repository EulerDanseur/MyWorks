#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
using namespace std;

int DexToOct(char);
void SortUp(int [], int);
void SortDown(int [], int);
void PrintOctToDexDouble(int);
int Compress(int);
void PrintOctToDex(int);

int standard[16];

int main()
{
    int n;
    cin >> n;
    char tens, units;
    int points[n][20] = {0};
    int order[20 * n] = {0};
    int count[256]={0};

    int length = 0;
    
    getchar();

    for(int i = 0; i < n; i++)
    {
        int flag = 1;
        for(int j = 0; j < 20; j++)
        {
            if(flag)
            {
                tens = getchar();        
                if(tens == 10)
                {
                    flag = 0;
                    length = j;
                    order[i * 20 + j] = 256;
                    points[i][j] = 256;
                    continue;
                }
                units = getchar();
                order[i * 20 + j] = DexToOct(tens) * 16 + DexToOct(units);
                points[i][j] = order[i*20 + j];
            }
            else
            {
                order[i * 20 + j] = 256;
                points[i][j] = 256;
            }
        }
    }
    SortUp(order, n * 20);
    
    for(int i = 0; i < 256; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n * 20; j++)
        {
            if(i == order[j]) cnt++;
            else if(i < order[j])
            {
                count[i] = cnt * 1000 + 255 - i;
                break;
            }
        }
    }
    SortDown(count, 256);

    for(int i = 0; i < 16; i++)
    {
        standard[i] = 255 - count[i] % 1000;
        //cout << " " << standard[i] << " ";
        PrintOctToDexDouble(standard[i]);
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < length; j++)
        {
            points[i][j] = Compress(points[i][j]);
            PrintOctToDex(points[i][j]);
        }
        cout << endl;
    }    
}

void PrintOctToDexDouble(int num)
{
    if(num < 10)
    {
        cout << "0" << num;
    }
    else if(num < 16)
    {
        cout << "0" << (char)('A' + num - 10);
    }
    else
    {
        int tens = num / 16;
        int units = num % 16;
        if(tens < 10)
            cout << tens;
        else
            cout << (char)('A' + tens - 10);

        if(units < 10)
            cout << units;
        else
            cout << (char)('A' + units - 10);
    }
}

void PrintOctToDex(int num)
{
    if(num < 10)
    {
        cout << num;
    }
    else if(num < 16)
    {
        cout << (char)('A' + num - 10);
    }

}

int Compress(int num)
{
    int min = INT_MAX;
    int minNum = 0;
    for(int i = 0; i < 16; i++)
    {
        if(abs(standard[i] - num) <= min)
        {
            min = abs(standard[i] - num);
            minNum = i;
        }
    }
    return minNum;
}

int DexToOct(char digits)
{
    if(digits >= 'A' && digits <= 'F')
        return digits - 'A' + 10;
    else 
        return digits - '0';
}

void SortUp(int arr[], int n)
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

void SortDown(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}