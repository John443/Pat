/*
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed 
in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are 
in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" 
is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator 
have no common factor. You must output only the fractional part if the integer part is 0.
*/
#include <iostream>
#include <cstdio>
using namespace std;

long long Gcd(long long a, long long b)
{
	long long r;
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long Lcm(long long a, long long b)
{
	return a / Gcd(a, b) * b;
}

int main()
{
	int n;
	cin >> n;
	long long a1 = 0, b1 = 1, a2, b2;
	long long multiple, factor;
	for (int i = 0; i < n; i++)
	{
		cin >> a2;
		getchar();
		cin >> b2;
		multiple = Lcm(b1, b2);
		a1 *= multiple / b1;
		a2 *= multiple / b2;
		a1 += a2;
		b1 = multiple;

		factor = Gcd(a1, b1);
		a1 /= factor;
		b1 /= factor;
		if (a1 == 0)
			b1 = 1;
	}
	if (a1 == 0)
		cout << 0;
	else
	{
		if (a1 / b1 != 0)
		{
			cout << a1 / b1;
			a1 %= b1;
			if (a1 != 0)
				cout << " ";
		}
		if (a1 != 0)
		{
			cout << a1 << "/" << b1;
		}
	}
	return 0;
}