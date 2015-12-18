/*
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. 
The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer 
portion has exactly one digit, there is at least one digit in the fractional portion, and the number 
and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional 
notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number 
A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute 
value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the 
significant figures kept, including trailing zeros.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string raw;
	cin >> raw;
	if (raw[0] == '-')
	{
		cout << "-";
	}
	string s(raw.begin() + 1, raw.end());
	int lens = s.length();
	string s1(s.begin(), s.begin() + 1);
	int pose = s.find('E');
	string s2(s.begin() + 2, s.begin() + pose);
	int lens2 = s2.length();
	int tag;
	if (s[pose + 1] == '-')
		tag = -1;
	else
		tag = 1;
	string s3(s.begin() + pose + 2, s.end());
	int lens3 = s3.length();
	int exp = 0;
	for (int i = 0; i < lens3; i++)
	{
		exp *= 10;
		exp += s3[i] - '0';
	}
	if (exp == 0)
		cout << s1 << "." << s2;
	else
	{
		if (tag == 1)
		{
			if (exp == lens2)
				cout << s1 << s2;
			else if (exp > lens2)
			{
				cout << s1 << s2;
				for (int i = lens2; i < exp; i++)
					cout << "0";
			}
			else
			{
				cout << s1;
				for (int i = 0; i < exp; i++)
					cout << s2[i];
				cout << ".";
				for (int i = exp; i < lens2; i++)
					cout << s2[i];
			}
		}
		else
		{
			cout << "0.";
			int zero = exp - 1;
			for (int i = 0; i < zero; i++)
				cout << "0";
			cout << s1 << s2;
		}
	}
	cout << endl;
	return 0;
}
