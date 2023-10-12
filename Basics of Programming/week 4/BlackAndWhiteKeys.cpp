#include<iostream>
using namespace std;

int main()
{
	int length, flag, count = 1;
	cin >> length;
	if (length == 0)
	{
		cout << 0;
		return 0;
	}
	char key ;
	
	cin >> key;
	if (key == 'B')
		flag = 1;
	else
		flag = 0;

	for (int i = 2; i <= length; i++)
	{
		cin >> key;
		if (flag == 1)
		{
			if (key == 'W')
			{
				count++;
				flag = 0;
			}
		}
		else
		{
			if (key == 'B')
			{
				count++;
				flag = 1;
			}
		}
	}

	cout << count;
	return 0;
}

