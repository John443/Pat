/*
To store English words, one method is to use linked lists and store a word letter by letter. 
To save some space, we may let the words share the same sublist if they share the same suffix. 
For example, "loading" and "being" are stored as showed in Figure 1.

Figure 1(see it on http://www.patest.cn/contests/pat-a-practise/1032)
You are supposed to find the starting position of the common suffix (e.g. the position of 
"i" in Figure 1).

Input Specification:

Each input file contains one test case. For each case, the first line contains two addresses 
of nodes and a positive N (<= 105), where the two addresses are the addresses of the first 
nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit 
positive integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is the letter contained by this node which is 
an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.

Output Specification:

For each case, simply output the 5-digit starting position of the common suffix. If the two 
words have no common suffix, output "-1" instead.
*/
#include<iostream>
#include<cstdio>
using namespace std;

int a[100001], b[100001];

int main()
{
	int start1, start2, N;
	cin >> start1 >> start2 >> N;
	for (int i = 0; i < N; i++)
	{
		int add, nxt;
		char dat;
		cin >> add >> dat >> nxt;
		a[add] = nxt;
	}
	while (start1 != -1)
	{
		++b[start1];
		start1 = a[start1];
	}
	bool tag = true;
	while (start2 != -1)
	{
		++b[start2];
		if (b[start2] == 2)
		{
			printf ("%05d\n", start2);
			tag = false;
			break;
		}
		start2 = a[start2];
	}
	if (tag)
	{
		cout << "-1" << endl;
	}
	return 0;
}