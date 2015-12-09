/*
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child 
subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing 
is done to restore this property. Figures 1-4 illustrate the rotation rules.
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer 
N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given 
in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node * left;
	Node * right;
	int height;
};

int Height(Node * p)
{
	if (p == NULL)
		return 0;
	else
		return p->height;
}

Node * SingleRotateWithLeft(Node * K2)
{
	Node * K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;
	K2->height = max(Height(K2->left), Height(K2->right)) + 1;
	K1->height = max(Height(K1->left), Height(K1->right)) + 1;
	return K1;
}

Node * SingleRotateWithRight(Node * K2)
{
	Node * K1 = K2->right;
	K2->right = K1->left;
	K1->left = K2;
	K2->height = max(Height(K2->left), Height(K2->right)) + 1;
	K1->height = max(Height(K1->left), Height(K1->right)) + 1;
	return K1;
}

Node * DoubleRotateWithLeft(Node * K3)
{
	K3->left = SingleRotateWithRight(K3->left);
	return SingleRotateWithLeft(K3);
}

Node * DoubleRotateWithRight(Node * K4)
{
	K4->right = SingleRotateWithLeft(K4->right);
	return SingleRotateWithRight(K4);
}

Node * Insert(int X, Node * T)
{
	if (T == NULL)
	{
		T = new Node;
		T->data = X;
		T->left = T->right = NULL;
	}
	else if (X < T->data)
	{
		T->left = Insert(X, T->left);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (X < T->left->data)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (X > T->data)
	{
		T->right = Insert(X, T->right);
		if (Height(T->right) - Height(T->left) == 2)
		{
			if (X > T->right->data)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	T->height = max(Height(T->left), Height(T->right)) + 1;
	return T;
}

int main()
{
	int n, x;
	Node * T = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		T = Insert(x, T);
	}
	cout << T->data;
	return 0;
}