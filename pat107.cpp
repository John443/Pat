/*
When register on a social network, you are always asked to specify your hobbies in order to find 
some potential friends with the same hobbies. A "social cluster" is a set of people who have some 
of their hobbies in common. You are supposed to find all the clusters.

Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer 
N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. 
Then N lines follow, each gives the hobby list of a person in the format:

Ki: hi[1] hi[2] ... hi[Ki]

where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, 
print the numbers of people in the clusters in non-increasing order. The numbers must be separated by 
exactly one space, and there must be no extra space at the end of the line.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct Node
{
	vector<int> son;
};
vector<int> par;
vector<int> Rank;
vector<int> num;
vector<Node> Hobby(1005);

int maxNum;

void Init(int n)
{
	par.resize(n);
	Rank.resize(n, 0);
	num.resize(n);
	for (int i = 0; i < n; i++)
	{
		num[i] = 1;
		par[i] = i;
	}
}

int Find(int x)
{
	if (x == par[x])
		return x;
	return par[x] = Find(par[x]);
}

bool cmp(const int & a, const int & b)
{
	return a > b;
}

void SetUnion(int a, int b)
{
	int x = Find(a);
	int y = Find(b);
	if (x == y)
		return;
	maxNum--;
	if (Rank[x] < Rank[y])
	{
		par[x] = y;
		num[y] += num[x];
	}
	else
	{
		par[y] = x;
		num[x] += num[y];
		if (Rank[x] == Rank[y])
			Rank[x]++;
	}
}

int main()
{
	int N;
	cin >> N;
	Init(N);
	maxNum = N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		char c;
		cin >> tmp >> c;
		for (int j = 0; j < tmp; j++)
		{
			int id;
			cin >> id;
			Hobby[id].son.push_back(i);
		}
	}
	for (int i = 0; i <= 1000; i++)
	{
		if (!Hobby[i].son.empty())
		{
			int a = Hobby[i].son[0];
			for (int j = 1; j < Hobby[i].son.size(); j++)
			{
				int b = Hobby[i].son[j];
				SetUnion(a, b);
			}
		}
	}
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		int a = Find(i);
		s.insert(a);
	}
	vector<int> list;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		int a = Find(*it);
		list.push_back(num[a]);
	}
	sort(list.begin(), list.end(), cmp);
	cout << maxNum << endl;
	for (int i = 0; i < list.size(); i++)
	{
		if (i == 0)
			cout << list[i];
		else
			cout << " " << list[i];
	}
	cout << endl;
	return 0;
}
