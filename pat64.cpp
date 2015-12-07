/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the 
bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is 
required that the tree must also be a CBT. You are supposed to output the level order traversal 
sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N 
(<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in 
a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding 
complete binary search tree. All the numbers in a line must be separated by a space, and there must 
be no extra space at the end of the line.
*/
#include <iostream>
#include <algorithm>
#define MAX 1005
using namespace std;

int key[MAX];
int level[MAX];
int ID = 0;

void Rebuild(int i, int n)
{
	if (i * 2 <= n)
		Rebuild(2 * i, n);
	level[i] = key[ID++];
	if (2 * i + 1 <= n)
		Rebuild(2 * i + 1, n);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> key[i];
	}
	sort(key, key + N);
	Rebuild(1, N);
	for (int i = 1; i < N; i++)
	{
		cout << level[i] << " ";
	}
	cout << level[N] << endl;
	return 0;
}
