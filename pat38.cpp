/*
Given a collection of number segments, you are supposed to recover the smallest number from 
them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 
32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations 
of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:

Each input file contains one test case. Each case gives a positive integer N (<=10000) 
followed by N number segments. Each segment contains a non-negative integer of no more 
than 8 digits. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the smallest number in one line. Do not output leading zeros.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string s1, string s2)
{
	return (s1 + s2) < (s2 + s1);
}

int main()
{
	int N;
	cin >> N;
	vector<string> str(N);
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	sort(str.begin(), str.end(), cmp);
	int tag = 0;
	for (int i = 0; i < N; i++)
	{
		if (tag == 0)
		{
			int j = 0;
			while (j < str[i].size() && str[i][j] == '0')
				j++;
			if (j < str[i].size())
				{
					cout << str[i].substr(j, str[i].size() - j);
					tag = 1;
				}
		}
		else
			cout << str[i];
	}
	if (tag == 0)
		cout << '0';
	return 0;
}