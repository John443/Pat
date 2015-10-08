/*
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be 
{ Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous 
subsequence which has the largest sum of its elements. For example, given sequence 
{ -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum 
being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers 
of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains 
a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last 
numbers of the maximum subsequence. The numbers must be separated by one space, but there 
must be no extra space at the end of a line. In case that the maximum subsequence is not 
unique, output the one with the smallest indices i and j (as shown by the sample case). 
If all the K numbers are negative, then its maximum sum is defined to be 0, and you are 
supposed to output the first and the last numbers of the whole sequence.
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> seq;
	int max = -1;
	bool flag = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		seq.push_back(num);
		if (num >= 0)
			flag = true;
	}
	int begin = seq[0];
	int	end = seq[n-1];
	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = i; j < n; j++)
			{
				sum += seq[j];
				if (sum > max)
				{
					begin = seq[i];
					end = seq[j];
					max = sum;
				}
			}
		}
		cout << max << " " << begin << " " << end << endl;
	}
	else
		cout << 0 << " " << begin << " " << end << endl;
	return 0;
}