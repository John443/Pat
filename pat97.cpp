/*
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated 
absolute values of the keys. That is, for each value K, only the first node of which the value or 
absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept 
in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the 
removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the 
first node, and a positive N (<= 105) which is the total number of nodes. The address of a node is 
a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 
104, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a 
line, and is printed in the same format as in the input.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct Node
{
	int add;
	int key;
	int next;
};

int visited[10005];

int main()
{
	int head, N;
	cin >> head >> N;
	vector<Node> v(100000);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v[tmp].add = tmp;
		cin >> v[tmp].key;
		cin >> v[tmp].next;
	}
	vector<Node> v1, v2;
	int p = head;
	while (p != -1)
	{
		if (!visited[abs(v[p].key)])
		{
			visited[abs(v[p].key)] = 1;
			v1.push_back(v[p]);
		}
		else
		{
			v2.push_back(v[p]);
		}
		p = v[p].next;
	}
	int n1 = v1.size();
	int n2 = v2.size();
	for (int i = 0; i < n1 - 1; i++)
	{
		v1[i].next = v1[i + 1].add;
		printf("%05d %d %05d\n", v1[i].add, v1[i].key, v1[i].next);
	}
	if (n1 > 0)
	{
		printf("%05d %d %d\n", v1[n1 - 1].add, v1[n1 - 1].key, -1);
	}
	for (int i = 0; i < n2 - 1; i++)
	{
		v2[i].next = v2[i + 1].add;
		printf("%05d %d %05d\n", v2[i].add, v2[i].key, v2[i].next);
	}
	if (n2 > 0)
	{
		printf("%05d %d %d\n", v2[n2 - 1].add, v2[n2 - 1].key, -1);
	}
	return 0;
}
