/*
Given a string, you are supposed to output the length of the longest symmetric sub-string. 
For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", 
hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int max = 0;
	bool flag;
	int len = s.size();
	int i, j, k;
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++)
		{
			flag = false;
			for (k = i; k <= j; k++)
			{
				if (s[k] != s[i + j - k])
				{
					flag = true;
					break;
				}
			}
			if (!flag && j - i + 1 > max)
			max = j - i + 1;
		}
	}
	cout << max << endl;
	return 0;
}