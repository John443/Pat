/*
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? 
The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while 
that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the 
set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 
10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 
is true. If the equation is impossible, print "Impossible". If the solution is not unique, output 
the smallest possible radix.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Radix
{
private:
	long long n1, n2;
	int tag, radix;
	string N1, N2;
	long long base, max, ans;
public:
	Radix()
	{
		n1 = n2 = 0;
		tag = radix = 0;
		base = max = 0;
		ans = -1;
	}
	~Radix() {}
	void Input()
	{
		cin >> N1 >> N2 >> tag >> radix;
	}
	long long Convert2int(string s, long long base)
	{
		long long n = 0;
		for (int i = 0; i != s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				n = s[i] - '0' + n * base;
			else if (s[i] >= 'a' && s[i] <= 'z')
				n = n * base + s[i] - 'a' + 10;
		}
		return n;
	}
	void FindSmallBase(string s)
	{
		char max = '0';
		for (long long i = 0; i != s.size(); i++)
		{
			if (s[i] > max)
				max = s[i];
		}
		if (max >= '0'&& max <= '9')
			base = max - '0' + 1;
		else if (max >= 'a'&& max <= 'z')
			base = max - 'a' + 11;
	}
	void BinSearch(string s, long long min, long long max, long long n)
	{
		long long mid = min;
		while (min <= max)
		{
			long long sum = 0;
			for (int j = 0; j != s.size(); j++)
			{
				if (s[j] >= '0' && s[j] <= '9')
					sum = s[j] - '0' + sum * mid;
				else if (s[j] >= 'a' && s[j] <= 'z')
					sum = sum * mid + s[j] - 'a' + 10;
				if (sum > n)
				{
					max = mid - 1;
					break;
				}
			}
			if (sum < n)
				min = mid + 1;
			if (sum > n)
				max = mid - 1;
			if (sum == n)
			{
				ans = mid;
				max = mid - 1;
			}
			mid = (min + max) / 2;
		}
	}
	void Get()
	{
		long long temp;
		if (tag == 2)
		{
			N1.swap(N2);
		}
		n1 = Convert2int(N1, radix);

		FindSmallBase(N2);
		temp = (base > n1) ? base : n1;
		BinSearch(N2, base, temp, n1);
	}
	void Display()
	{
		if (ans == -1)
		{
			cout << "Impossible" << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
};

int main()
{
	Radix radix;
	radix.Input();
	radix.Get();
	radix.Display();
	return 0;
}
