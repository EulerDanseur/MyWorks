#include<stdio.h>
#include<math.h>
double root(double a, double b);
double f(double x);
int main()
{
	double product,x;
	product = f(1) * f(2);
	if (product > 0) {
		printf("There is no root!");
	}
	else {
		x = root(1, 2);
		printf("%.6lf", x);
	}
	return 0;
}
double f(double x)
{
	double y;
	y = x * x / 4 - sin(x);
	return y;
}

double root(double a, double b)
{
	double eps,c;
	eps = 1e-6;
	c = (a + b) / 2;
	if (fabs(f(c)) <= eps) 
		return c;
	else {
		if (f(a) * f(c) <= 0)
		return root(a, c);
		if (f(b) * f(c) <= 0)
		return root(c, b);
	}
}