#include <iostream>

using namespace std;

class Fraction
{
	int numerator, denominator;

public:
	Fraction(int numerator0 = 0, int denominator0 = 1) : numerator(abs(numerator0)), denominator(abs(denominator0))
	{
		int sign = (numerator0 < 0) ^ (denominator0 < 0) ? -1 : 1;
		numerator *= sign;
		// 保证分母不为0
		if (denominator0 == 0)
		{
			cout << "Invalid denominator!" << endl;
			exit(1);
		}

		//约分
		for(int i = 2; i <= abs(numerator0) && i <= abs(denominator0); i++)
		{
			if (numerator0 % i == 0 && denominator0 % i == 0)
			{
				numerator /= i;
				denominator /= i;
			}
		}
	}

	Fraction(const Fraction & f)
	{
		numerator = f.numerator;
		denominator = f.denominator;
	}

	~Fraction()
	{
		numerator = 0;
		denominator = 1;
	}

	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}

	Fraction operator+(Fraction f)
	{
		return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator);
	}
	Fraction operator-(Fraction f)
	{
		return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
	}
	Fraction operator*(Fraction f)
	{
		return Fraction(numerator * f.numerator, denominator * f.denominator);
	}
	Fraction operator/(Fraction f)
	{
		return Fraction(numerator * f.denominator, denominator * f.numerator);
	}
};

int main()
{
	Fraction f1(5, -4), f2(3, 6);
	f1.print(); // 输出：-5/4
	f2.print(); // 输出：1/2
	Fraction f3 = f1 + f2;
	f3.print(); // 输出：-3/4
	Fraction f4 = f1 - f2;
	f4.print(); // 输出：-7/4
	Fraction f5 = f1 * f2;
	f5.print(); // 输出：-5/8
	Fraction f6 = f1 / f2;
	f6.print(); // 输出：-5/2
	return 0;
}