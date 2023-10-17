#include<iostream>
using namespace std;
#include<cmath>
void IsNarcissis(int n);
int Length(int n);

int main()
{
	int row;
	cin >> row;
	int n;
	for (int i = 1; i <= row; i++)
	{
		cin >> n;
		IsNarcissis(n);
	}
	
	return 0;
}

void IsNarcissis(int n)
{
	int num = 0, digit, left = n;
	while (left != 0)
	{
		digit = left % 10;
		num += pow(digit, Length(n));
		left /= 10;
	}
	if (num == n)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

int Length(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}