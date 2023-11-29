#include<iostream>
using namespace std;
#define N 100
int cal(bool f[][N], int n, int j);
int main()
{
	int n;
	cin >> n;
	bool f[N][N] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> f[i][j];
	int num = 0;
	//for (int k = 0; k < n; k++)
		{
		    for (int j = 0; j < n; j++)
			{
				if (f[j][j] == 1)
				{
					f[j][j] = 0;
					num += cal(f, n, j);
				}
			}
		}
		cout << num << endl;
	return 0;
}

int cal(bool f[][N], int n,int j)
{
	for (int l = 0; l < n; l++)
		if (f[j][l] == 1 && j != l)
			return 0;
	return 1;
}


/* 5
1 0 0 0 0 0
0 1 1 0 0 1
0 1 1 0 1 0
0 0 0 1 0 1
0 0 1 0 1 0
0 1 0 1 0 1 */