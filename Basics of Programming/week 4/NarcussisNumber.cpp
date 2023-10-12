#include<iostream>
using namespace std;
#include<cmath>
void Calculate(int n);

int main()
{
	int row;
	cin >> row;
	int n;
	for (int i = 1; i <= row; i++)
	{
		cin >> n;
		Calculate(n);
	}
	
	return 0;
}

void Calculate(int n)
{
	int num = 0, digit, left = n;
	int dits = 0, cal_dits = n;
	while (cal_dits != 0)
	{
		dits += 1;
		cal_dits /= 10;
	}
	while (left != 0)
	{
		digit = left % 10;
		num += pow(digit, dits);
		left /= 10;
	}
	if (num == n)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}