#include<iostream>
using namespace std;

int Count(int, int, int, int, int);

int main()
{
	int n, a, b, c, x, y, z;
	int count = 0;
	int countTrue = 0;
	cin >> n >> a >> b >> c >> x >> y >> z;
	int left1 = 0 ;
	for (int i = 0; i < x + 1; i++)
	{
		left1 = n - i * a;
		if(left1 == 0)
		{	
			count += 1;
			countTrue += 1; 
			break;
		}
        int bAmount = min(y, left1/ b);
		int cAmount = min(z, left1 / c);
		for(int j = 0 ; j <= bAmount; j++)
		{
			int left2 = left1 - b * j;
			if(left2 / c > z)
				continue;
			else if(left2 % c == 0)
				count ++;
		}
		countTrue += Count(b, c, bAmount, cAmount, left1);
	}
	cout << count << endl << countTrue;
	return 0;
}

int Count(int b, int c, int bAmount, int cAmount, int left1)
{
	if(bAmount == 0)
	{
		if(left1 % c == 0 && left1 / c <= cAmount)
			return 1;
		else
			return 0;
	}
	else if((left1 - b * bAmount) / c > cAmount)
		return 0;
	else if((left1 - b * bAmount) % c == 0)
	    return 1 + Count(b, c, bAmount - 1, cAmount, left1);
	else;
		return Count(b, c, bAmount - 1, cAmount, left1);
}