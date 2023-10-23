#include<iostream>
using namespace std;

int main()
{
	int n, a, b, c, x, y, z;
	int times = 0;
	cin >> n >> a >> b >> c >> x >> y >> z;
	int sum = 0;
	for (int i = 0; i < x+1; i++)
	{	
		for (int j = 0; j < y+1; j++)
		{	

			for (int k = 0; k < z+1; k++)
			{
				sum = i * a + j * b + k * c;
				if (sum == n)
					times++;
			}
		}
	}
	cout << times;
	return 0;
}