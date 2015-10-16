/*
A reversible prime in any number system is a prime whose "reverse" in that number system is also 
a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is 
also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if 
N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two 
integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
*/
#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int n)
{
	if (n == 1)
		return false;
	int end = sqrt(n);
	for (int i = 2; i <= end; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int Reverse(int n, int d)
{
	int t[20];
	int i = 0;
	int ans = 0;
	int base = 1;
	while (n)
	{
		t[i++] = n%d;
		n /= d;
	}
	t[i] = 0;
	while (i)
	{
		ans += t[--i] * base;
		base *= d;
	}
	return ans;
}

int main()
{
	int n, d;
	while (cin >> n && (n > 0))
	{
		cin >> d;
		if (IsPrime(n) && IsPrime(Reverse(n, d)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
