#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[200] = {}, b[200] = {}, c[200] = {};
	cin >> a >> b;
	int strlen_a = strlen(a);
	int strlen_b = strlen(b);
	if (strlen_a == strlen_b)
	{
		for (int i = strlen_a - 1; i >= 0; i--)
		{
			c[i] = a[i] + b[i] + c[i] - '0';
			if (c[i] >= '9' + 1)
			{
				c[i] = c[i] - 10;
				if (i > 0)
				{
					c[i - 1] = c[i - 1] + 1;
				}
				if (i == 0)
				{
					for (int j = strlen_a - 1; j >= 0; j--)
					{
						c[j + 1] = c[j];
					}
					c[0] = '1';
				}
			}
		}
	}
	if (strlen_a != strlen_b)
	{
		int max, min;
		bool a_less = 1;
		if (strlen_a > strlen_b)
		{
			max = strlen_a;
			min = strlen_b;
			a_less = 0;
		}
		else {
			max = strlen_b;
			min = strlen_a;
		}
		if (a_less == 1)
		{
			for (int i1 = 0; i1 < strlen_a; i1++)
			{
				a[i1 + max - min] = a[i1];
				a[i1] = '0';
			}
			for (int i = 0; i < max - min; i++)
			{
				a[i] = '0';
			}
		}
		if (a_less == 0)
		{
			for (int i2 = 0; i2 < strlen_b; i2++)
			{
				b[i2 + max - min] = b[i2];
			}
			for (int i = 0; i < max - min; i++)
			{
				b[i] = '0';
			}
		}
		for (int i3 = max - 1; i3 >= 0; i3--)
		{
			c[i3] = a[i3] + b[i3] + c[i3] - '0';
			if (c[i3] >= '9' + 1)
			{
				c[i3] = c[i3] - 10;
				if (i3 > 0)
				{
					c[i3 - 1] = c[i3 - 1] + 1;
				}
				if (i3 == 0)
				{
					for (int j1 = max - 1; j1 >= 0; j1--)
					{
						c[j1 + 1] = c[j1];
					}
					c[0] = '1';
				}
			}
		}
	}
	
	cout << c;
	return 0;
}