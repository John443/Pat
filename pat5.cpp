/*
Given a non-negative integer N, your task is to compute the sum of all the digits of N, 
and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. 
There must be one space between two consecutive words, but no extra space at the end of a line.
*/
#include<iostream>
#include<string>
using namespace std;
string numE[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
string int2str(int n);

int main()
{
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (int i = 0; i != s.length(); i++)
		{
			sum += s[i] - '0';
		}
		if (sum != 0)
		{
			string ssum = int2str(sum);
			for (int i = 0; i != ssum.length(); i++)
			{
				if (i < ssum.length() - 1)
					cout << numE[ssum[i] - '0'] << " ";
				else
					cout << numE[ssum[i] - '0'] << endl;
			}
		}
		else
			cout << numE[sum] << endl;
	}
	return 0;
}

string int2str(int n)
{
	char t[1000];
	int i = 0;
	string str = "";
	while (n)
	{
		t[i++] = (n % 10) + '0';
		n /= 10;
	}
	t[i] = 0;
	while (i)
	{
		str += t[--i];
	}
	return str;
}
