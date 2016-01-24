/*
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary 
tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer 
N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 
0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order 
traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, 
and no extra space at the end of the line.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
	int key;
	int left;
	int right;
};

Node N[12];
queue<int> q;
int visited[12];
int lo[12], io[12];

void Level(int root)
{
	q.push(root);
	int cnt = 0;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		lo[cnt++] = tmp;
		if (N[tmp].left >= 0)
			q.push(N[tmp].left);
		if (N[tmp].right >= 0)
			q.push(N[tmp].right);
	}
}

int cnt = 0;
void InOrder(int root)
{
	if (N[root].left >= 0)
		InOrder(N[root].left);
	io[cnt++] = root;
	if (N[root].right >= 0)
		InOrder(N[root].right);
}

int main()
{
	int n, root;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b;
		cin >> b >> a;
		N[i].key = i;
		if (a >= '0' && a <= '9')
		{
			N[i].left = a - '0';
			visited[a - '0'] = 1;
		}
		else
			N[i].left = -1;
		if (b >= '0' && b <= '9')
		{
			N[i].right = b - '0';
			visited[b - '0'] = 1;
		}
		else
			N[i].right = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
			root = i;
	}
	Level(root);
	InOrder(root);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << lo[i];
		else
			cout << " " << lo[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << io[i];
		else
			cout << " " << io[i];
	}
	cout << endl;
	return 0;
}
