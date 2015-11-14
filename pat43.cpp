/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's 
key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal 
sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line 
are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal 
sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", 
print in the next line the postorder traversal sequence of that tree. All the numbers in a 
line must be separated by a space, and there must be no extra space at the end of the line.
*/
#include<iostream>
#define MAX 1005
using namespace std;

struct Node
{
	int data;
	Node * left;
	Node * right;
};

int key[MAX];
int PreOrder[MAX];
int PreOrderImg[MAX];
int PostOrder[MAX];
int index = 0;

void InsertNode(Node * & p, int key, bool IsImg)
{
	if (p == NULL)
	{
		p = new Node();
		p->left = NULL;
		p->right = NULL;
		p->data = key;
		return;
	}
	else
	{
		if (IsImg)
		{
			if (p->data <= key)
				InsertNode(p->left, key, IsImg);
			else
				InsertNode(p->right, key, IsImg);
		}
		else
			if (p->data > key)
				InsertNode(p->left, key, IsImg);
			else
				InsertNode(p->right, key, IsImg);
	}
}

void Create(Node * & p, int arr[], int n, bool IsImg)
{
	for (int i = 0; i < n; i++)
	{
		InsertNode(p, arr[i], IsImg);
	}
}

void preOrder(Node * root, bool IsImg)
{
	if (root == NULL)
		return;
	if (IsImg)
		PreOrderImg[index++] = root->data;
	else
		PreOrder[index++] = root->data;
	if (root->left)
		preOrder(root->left, IsImg);
	if (root->right)
		preOrder(root->right, IsImg);
}

void postOrder(Node * root)
{
	if (root == NULL)
		return;
	if (root->left)
		postOrder(root->left);
	if (root->right)
		postOrder(root->right);
	PostOrder[index++] = root->data;
}

bool check(int a[], int b[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void PrintT(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
			cout << arr[i];
		else
			cout << " " << arr[i];
	}
	cout << endl;
}

void freeNode(Node * root)
{
	if (root->left == NULL && root->right == NULL)
		delete root;
	else if (root->left)
		freeNode(root->left);
	else if (root->right)
		freeNode(root->right);
}

int main()
{
	int N;
	cin >> N;
	Node * root = NULL;
	Node * rootImg = NULL;
	for (int i = 0; i < N; i++)
		cin >> key[i];
	Create(root, key, N, false);
	Create(rootImg, key, N, true);
	index = 0;
	preOrder(root, false);
	if (check(key, PreOrder, N))
	{
		cout << "YES" << endl;
		index = 0;
		postOrder(root);
		PrintT(PostOrder, N);
	}
	else
	{
		index = 0;
		preOrder(rootImg, true);
		if (check(key, PreOrderImg, N))
		{
			cout << "YES" << endl;
			index = 0;
			postOrder(rootImg);
			PrintT(PostOrder, N);
		}
		else
			cout << "NO" << endl;
	}
	freeNode(root);
	freeNode(rootImg);
	return 0;
}