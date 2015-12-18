/*
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K 
elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; 
if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the 
first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which 
is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, 
and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next 
node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed 
in the same format as in the input.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int add;
	int key;
	int nxt;
};

void Reverse(vector<Node> & v, int begin, int end)
{
	while (begin < end)
	{
		swap(v[begin], v[end]);
		begin++;
		end--;
	}
}

int main()
{
	int head, N, K;
	cin >> head >> N >> K;
	vector<Node> v(100000);
	for (int i = 0; i < N; i++)
	{
		int index;
		cin >> index;
		cin >> v[index].key >> v[index].nxt;
		v[index].add = index;
	}
	int index = head;
	vector<Node> result;
	while (index != -1)
	{
		result.push_back(v[index]);
		index = v[index].nxt;
	}
	int len = result.size();
	int rev = len / K;
	for (int i = 0; i < rev; i++)
	{
		Reverse(result, i * K, (i + 1) * K - 1);
	}
	for (int i = 0; i < len - 1; i++)
	{
		result[i].nxt = result[i + 1].add;
		printf("%05d %d %05d\n", result[i].add, result[i].key, result[i].nxt);
	}
	printf("%05d %d %d\n", result[len - 1].add, result[len - 1].key, -1);
	return 0;
}
