#include <iostream>
#include <map>
#include <vector>
#include<cstring>
using namespace std;
typedef struct
{
	int f;
	int l;
}s;
int main()
{
	vector<s>vec;
	char a[11] = { 0 }, b[11] = {0};
	cin >> a >> b;

	int A = 0, B = 0;

	for (int i = 0; a[i] != 0; i++)
	{
		if (a[i] == b[i])
			A++;
		else
			vec.push_back({ a[i] - '0', b[i] - '0' });

	}

	for (int i = 0; i < vec.size(); i++)
	for (int j = 0; j < vec.size(); j++)
	{
		if (vec[i].f == vec[j].l)
		{
			B++;
			vec[j].l = -1;
			break;
		}

	}

	cout << A << 'A' << B << 'B';
	
}