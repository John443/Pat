/*
A number that will be the same when it is written forwards or backwards is known as a 
Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers 
are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept 
of palindromicity can be applied to the natural numbers in any numeral system. Consider a 
number N > 0 in base b >= 2, where it is written in standard notation with k+1 digits ai as 
the sum of (aibi) for i from 0 to k. Here, as usual, 0 <= ai < b for all i and ak is 
non-zero. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 in any 
base and is also palindromic by definition.

Given any non-negative decimal integer N and a base b, you are supposed to tell if N is a 
palindromic number in base b.

Input Specification:

Each input file contains one test case. Each case consists of two non-negative numbers N 
and b, where 0 <= N <= 109 is the decimal number and 2 <= b <= 109 is the base. The numbers 
are separated by a space.

Output Specification:

For each test case, first print in one line "Yes" if N is a palindromic number in base b, 
or "No" if not. Then in the next line, print N as the number in base b in the form 
"ak ak-1 ... a0". Notice that there must be no extra space at the end of output.
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N, b, c[10000];
	cin >> N >> b;
	if (N == 0)
		cout << "Yes" << endl << "0";
	else
	{
		int i = 0;
		while (N)
		{
			c[i++] = N%b;
			N /= b;
		}
		bool flag = true;
		for (int k = 0; k < i / 2; k++)
		{
			if (c[k] != c[i - k - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		for (int k = i - 1; k >= 0; k--)
		{
			if (k == i - 1)
				cout << c[k];
			else
				cout << " " << c[k];
		}
	}
	return 0;
}
