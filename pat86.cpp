/*
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, 
suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack 
operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); 
pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of 
operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer 
N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). 
Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index 
of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. 
A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there 
must be no extra space at the end of the line.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int iter = 0;
int val;
bool tag;
char op[10];

struct Node
{
	int num;
	Node * left;
	Node * right;
};

Node * BuildTree()
{
	if (iter >= n)
		return NULL;
	cin >> op;
	Node * root = NULL;
	if (op[1] == 'u')
	{
		cin >> val;
		root = new Node;
		root->num = val;
		root->left = root->right = NULL;
		iter++;
		root->left = BuildTree();
		iter++;
		root->right = BuildTree();
	}
	return root;
}

void DFS(Node * root)
{
	if (root == NULL)
		return;
	DFS(root->left);
	DFS(root->right);
	if (tag)
	{
		cout << root->num;
		tag = false;
	}
	else
	{
		cout << " " << root->num;
	}
}

int main()
{
	cin >> n;
	n = n * 2;
	Node * root = BuildTree();
	tag = true;
	DFS(root);
	cout << endl;
	return 0;
}
