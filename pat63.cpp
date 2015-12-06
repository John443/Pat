/*
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the 
number of distinct common numbers shared by the two sets, and Nt is the total number of distinct 
numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is 
the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed 
by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, 
followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 
1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 
1 decimal place.
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector< set<int> > data(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int M;
		cin >> M;
		while (M--)
		{
			int tmp;
			cin >> tmp;
			data[i].insert(tmp);
		}
	}
	int K;
	cin >> K;
	while (K--)
	{
		int a, b;
		cin >> a >> b;
		int total = data[a].size() + data[b].size();
		int num = total;
		for (set<int>::iterator it = data[a].begin(); it != data[a].end(); it++)
		{
			if (data[b].count(*it) == 1)
				num--;
		}
		printf("%.1f%%\n", double(total - num) / double(num) * 100);
	}
	return 0;
}