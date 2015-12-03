/*
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered 
equal since they are both saved as 0.123*105 with simple chopping. Now given the number of significant 
digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that 
machine.

Input Specification:

Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the 
number of significant digits, and A and B are the two float numbers to be compared. Each float 
number is non-negative, no greater than 10100, and that its total digit number is less than 100.

Output Specification:

For each test case, print in a line "YES" if the two numbers are treated equal, and then the number 
in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated 
equal, and then the two numbers in their standard form. All the terms must be separated by a space, 
with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.
*/
#include <iostream>
#include <string>
using namespace std;

int Convert2Std(const string s, int n, string & result)
{
	int len = s.size();
	int i = 0;
	while (i < len && (s[i] == '0' || s[i] == '.'))
		i++;
	if (i == len)
	{
		for (int j = 0; j < n; j++)
			result += '0';
		return 0;
	}
	int cnt = 0;
	while (i < len)
	{
		if (s[i] != '.')
		{
			result += s[i];
			cnt++;
			if (cnt == n)
				break;
		}
		i++;
	}
	while (cnt < n)
	{
		result += '0';
		cnt++;
	}
	i = 0;
	int ex = 0;
	while (i < len && s[i] == '0')
		i++;
	while (i < len && s[i] != '.')
	{
		ex++;
		i++;
	}
	if (ex > 0)
		return ex;
	if (s[i] == '.')
		i++;
	while (i < len && s[i] == '0')
	{
		ex--;
		i++;
	}
	return ex;
}

int main()
{
	int N;
	string s1;
	string s2;
	cin >> N >> s1 >> s2;
	string base1, base2;
	int ex1 = Convert2Std(s1, N, base1);
	int ex2 = Convert2Std(s2, N, base2);
	if (ex1 == ex2 && base1 == base2)
	{
		cout << "YES 0." << base1 << "*10^" << ex1;
	}
	else
	{
		cout << "NO";
		cout << " 0." << base1 << "*10^" << ex1;
		cout << " 0." << base2 << "*10^" << ex2;
	}
	return 0;
}
