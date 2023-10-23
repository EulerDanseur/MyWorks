#include<stdio.h>
int main()
{
	int n, money, price;
	scanf("%d%d%d", &n, &price, &money);
	int a = money / price;
	int b = a;
	int sum = 0;
	
    while (a > n - 1)
	{
		a = a - n + 1;
		sum += 1;
	}
	printf("%d", b + sum);
	return 0;
}