#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i, n;
	cin >> n;
	double a[n];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = n - 1; i >= 0; i--)
	{
		double temp = a[i];
		printf("%.2f ", temp);
	}
	return 0;
}