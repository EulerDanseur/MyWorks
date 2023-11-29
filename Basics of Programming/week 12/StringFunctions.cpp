#include<iostream>
using namespace std;

int StrLen(char str[])
{
    int count = 0;

    for(int i = 0; str[i] != 0; i++)
        count++;

    return count;
}

void StrCat(char a[], char b[])
{
    int aLen = StrLen(a);
    int bLen = StrLen(b);
    for(int i = 0; i < bLen; i++)
        a[aLen + i] = b[i];
}

void StrNCat(char a[], char b[], int n)
{
    int aLen = StrLen(a);
    int bLen = StrLen(b);
    if(bLen < n) n = bLen;

    for(int i = 0; i < n; i++)
        a[aLen + i] = b[i];
}

int StrCmp(char a[], char b[])
{
    int aLen = StrLen(a);
    int bLen = StrLen(b);
    if(aLen > bLen) aLen = bLen;

    for(int i = 0; i <= bLen; i++)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }      

    return 0;
}

int StrNCmp(char a[], char b[], int n)
{
    int aLen = StrLen(a);
    int bLen = StrLen(b);
    //if(aLen > bLen) aLen = bLen;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }      

    return 0;
}

