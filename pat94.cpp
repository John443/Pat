/*
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong 
to the same generation. Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<100) which is 
the total number of family members in the tree (and hence assume that all the members are numbered from 
01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each 
contains the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, 
followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix 
the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number and the level of the corresponding 
generation. It is assumed that such a generation is unique, and the root level is defined to be 1.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 105
using namespace std;

vector<int> v[MAX];
queue<int> q;
int visited[MAX];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int ID, k, c;
		cin >> ID >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> c;
			v[ID].push_back(c);
		}
	}
	int max = 1, level = 1;
	int count = 0, cur_level = 0;
	q.push(1);
	int endNode = q.back();
	while (!q.empty())
	{
		int index = q.front();
		q.pop();
		for (int i = 0; i < v[index].size(); i++)
		{
			int tmp = v[index][i];
			if (!visited[tmp])
			{
				q.push(tmp);
				visited[tmp] = 1;
			}
		}
		if (index == endNode)
		{
			cur_level++;
			count = q.size();
			if (count > max)
			{
				max = count;
				level = cur_level + 1;
			}
			endNode = q.back();
		}
	}
	cout << max << " " << level << endl;
	return 0;
}
