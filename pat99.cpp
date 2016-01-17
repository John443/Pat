/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way 
to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You 
are supposed to output the level order traversal sequence of that tree. The sample is illustrated 
by Figure 1 and 2.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer 
N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left 
and the right children of a node in the format "left_index right_index", provided that the nodes 
are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent 
the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers 
must be separated by a space, with no extra space at the end of the line.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 105
using namespace std;

int N;
int tree[MAX][3];
int key[MAX];
int num = 0;
bool tag = true;
queue<int> q;

void InOrder(int loc)
{
	if (tree[loc][1] != -1)
	{
		InOrder(tree[loc][1]);
	}
	tree[loc][0] = key[num];
	num++;
	if (tree[loc][2] != -1)
	{
		InOrder(tree[loc][2]);
	}
}

void LevOrder()
{
	q.push(0);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (tag)
		{
			cout << tree[cur][0];
			tag = false;
		}
		else
		{
			cout << " " << tree[cur][0];
		}
		if (tree[cur][1] != -1)
		{
			q.push(tree[cur][1]);
		}
		if (tree[cur][2] != -1)
		{
			q.push(tree[cur][2]);
		}
	}
	cout << endl;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i][1] >> tree[i][2];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> key[i];
	}
	sort(key, key + N);
	InOrder(0);
	LevOrder();
	return 0;
}