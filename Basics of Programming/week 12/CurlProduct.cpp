#include <iostream>
using namespace std;
int a[50][50] = { 0 }, b[50][50] = { 0 }, c[50][50] = { 0 };
int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			cin >> b[i][j];

	for (int i = 0; i < m - k + 1; i++)
	{
		for (int j = 0; j < n - k + 1; j++)
		{
			int temp = 0;
			for (int x = i; x < i + k; x++)
				for (int y = j; y < j + k; y++)
					temp += a[x][y] * b[x - i][y - j];

			cout << temp << ' ';
		}
		cout << endl;
	}
}