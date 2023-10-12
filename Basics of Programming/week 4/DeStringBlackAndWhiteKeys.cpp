#include<iostream>
using namespace std;

int main()
{
	int length, flag, count = 0;
	cin >> length;
	if (length == 0)
	{
		cout << 0;
		return 0;
	}
	string key;
	
	cin >> key;

	for (char k : key)
	{
		if (flag == 1 && k == 'W')
		{
				count++;
				flag = 0;
		}
		else if(flag == 0 && k == 'B')
		{
		
				count++;
				flag = 1;
		}
	}

	cout << count;
	return 0;
}

