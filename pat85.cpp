/*
Given a sequence of positive integers and another positive integer p. The sequence is said to be a 
"perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as 
possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers 
N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter. 
In the second line there are N positive integers, each is no greater than 109.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a 
perfect subsequence.
*/
#include <iostream>
#include <algorithm>
#define MAX 100005
using namespace std;

long long v[MAX];

int main()
{
	int n;
	long long p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v, v + n);
	int maxlen = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + maxlen - 1; j < n; j++)
		{
			long long tmp = v[i] * p;
			if (v[j] > tmp)
				break;
			if (maxlen < j - i + 1)
				maxlen = j - i + 1;
		}
	}
	cout << maxlen << endl;
	return 0;
}