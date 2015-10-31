/*
Given an increasing sequence S of N integers, the median is the number at the middle position. 
For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} 
is 15. The median of two sequences is defined to be the median of the nondecreasing sequence 
which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information 
of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that 
sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers 
are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long Tmp;
long long list[2000000];

void Merge(long long list[], long long *Tmp, int Lpos, int Rpos, int RightEnd)
{
	int LeftEnd = Rpos - 1;
	int Num = RightEnd - Lpos + 1;
	int count = 0;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (list[Lpos] < list[Rpos])
		{
			*Tmp = list[Lpos++];
			count++;
		}
		else if (list[Lpos] == list[Rpos])
		{
			*Tmp = list[Lpos++];
			count++;
			if (Num % 2 == 0 && count == Num / 2)
				return;
			else if (Num % 2 == 1 && count == (Num / 2 + 1))
				return;
			*Tmp = list[Rpos++];
			count++;
		}
		else
		{
			*Tmp = list[Rpos++];
			count++;
		}
		if (Num % 2 == 0 && count == Num / 2)
			return;
		else if (Num % 2 == 1 && count == (Num / 2 + 1))
			return;
	}
	if (Num % 2 == 0 && count == Num / 2)
		return;
	else if (Num % 2 == 1 && count == (Num / 2 + 1))
		return;
	while (Lpos <= LeftEnd)
	{
		*Tmp = list[Lpos++];
		count++;
		if (Num % 2 == 0 && count == Num / 2)
			return;
		else if (Num % 2 == 1 && count == (Num / 2 + 1))
			return;
	}
	while (Rpos <= RightEnd)
	{
		*Tmp = list[Rpos++];
		count++;
		if (Num % 2 == 0 && count == Num / 2)
			return;
		else if (Num % 2 == 1 && count == (Num / 2 + 1))
			return;
	}
}

int main()
{
	int n, m;
	cin >> n;
	//scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
		//scanf("%lld", &list[i]);
	}
	cin >> m;
	//scanf("%d", &m);
	for (int i = n; i < n + m; i++)
	{
		cin >> list[i];
		//scanf("%lld", &list[i]);
	}
	Merge(list, &Tmp, 0, n, n + m - 1);
	printf("%d", Tmp);
	return 0;
}
