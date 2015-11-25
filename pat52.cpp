/*
A linked list consists of a series of structures, which are not necessarily adjacent in memory. 
We assume that each structure contains an integer key and a Next pointer to the next structure. 
Now given a linked list, you are supposed to sort the structures according to their key values 
in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N 
(< 105) and an address of the head node, where N is the total number of nodes in memory and 
the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next 
is the address of the next node. It is guaranteed that all the keys are distinct and there is 
no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total 
number of nodes in the list and all the nodes must be sorted order.
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int add;
	int key;
	int nxt;
};

bool cmp(Node n1, Node n2)
{
	return n1.key < n2.key;
}

int main()
{
	int N;
	int head;
	cin >> N >> head;
	Node node[100001];
	for (int i = 0; i < N; i++)
	{
		int index;
		cin >> index;
		cin >> node[index].key >> node[index].nxt;
		node[index].add = index;
	}
	int count = 0;
	int index = head;
	vector<Node> list;
	while (index != -1)
	{
		count++;
		list.push_back(node[index]);
		index = node[index].nxt;
	}
	sort(list.begin(), list.end(), cmp);
	if (list.size() == 0)
	{
		cout << "0 -1" << endl;
	}
	else
	{
		printf("%d %05d\n", count, list[0].add);
		for (int i = 0; i < count - 1; i++)
		{
			list[i].nxt = list[i + 1].add;
			printf("%05d %d %05d\n", list[i].add, list[i].key, list[i].nxt);
		}
		printf("%05d %d %d\n", list[count - 1].add, list[count - 1].key, -1);
	}
	return 0;
}