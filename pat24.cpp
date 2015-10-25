/*
A number that will be the same when it is written forwards or backwards is known as a 
Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers 
are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. 
First, the non-palindromic number is reversed and the result is added to the original number. 
If the result is not a palindromic number, this is repeated until it gives a palindromic 
number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 
67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the 
number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, 
where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The 
numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired 
palindromic number of N, and the second number is the number of steps taken to find the 
palindromic number. If the palindromic number is not found after K steps, just output the 
number obtained at the Kth step and K instead.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindromic(const string & s)
{
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

string Add(string & s)
{
	string s1(s);
	reverse(s.begin(), s.end());
	string s2(s);
	int carry = 0;
	int n = s1.size();
	for (int i = n - 1; i >= 0; i--)
	{
		int tmp = s1[i] - '0' + s2[i] - '0' + carry;
		s[i] = tmp % 10 + '0';
		carry = tmp / 10;
	}
	if (carry > 0)
	{
		s.insert(s.begin(), 1, carry + '0');
	}
	return s;
}

int main()
{
	string n;
	int k;
	cin >> n >> k;
	if (isPalindromic(n))
	{
		cout << n << endl;
		cout << 0 << endl;
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			n = Add(n);
			if (isPalindromic(n))
			{
				cout << n << endl;
				cout << i + 1 << endl;
				break;
			}
		}
		if (!isPalindromic(n))
		{
			cout << n << endl;
			cout << k << endl;
		}
	}
	return 0;
}
