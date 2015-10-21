/*
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder 
and inorder traversal sequences, you are supposed to output the level order traversal sequence 
of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer 
N (<=30), the total number of nodes in the binary tree. The second line gives the postorder 
sequence and the third line gives the inorder sequence. All the numbers in a line are separated 
by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding 
binary tree. All the numbers in a line must be separated by exactly one space, and there must 
be no extra space at the end of the line.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	int value;
	Node * left;
	Node * right;
};

Node * Recursion(const vector<int> & post, const vector<int> & in, int ps, int pe, int is, int ie)
{
	if (ps > pe)
		return NULL;
	Node * root = new Node;
	root->value = post[pe];
	int mid = is;
	while (in[mid] != root->value)
		mid++;
	int lt = mid - is;
	root->left = Recursion(post, in, ps, ps + lt - 1, is, is + lt - 1);
	root->right = Recursion(post, in, ps + lt, pe - 1, is + lt + 1, ie - 1);
	return root;
}

vector<int> Output(Node * root)
{
	vector<int> result;
	if (root == NULL)
		return result;
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node * tmp = q.front();
		q.pop();
		result.push_back(tmp->value);
		if (tmp->left != NULL)
			q.push(tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> postorder;
	vector<int> inorder;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		postorder.push_back(k);
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		inorder.push_back(k);
	}
	Node * root = Recursion(postorder, inorder, 0, n - 1, 0, n - 1);
	vector<int> result;
	result = Output(root);
	for (auto i = result.begin(); i != result.end(); i++)
	{
		if (i == result.begin())
			cout << *i;
		else
			cout << " " << *i;
	}
	return 0;
}
