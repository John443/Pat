/*
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）
-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price 
P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the 
customers. It is assumed that each member in the supply chain has exactly one supplier except the root 
supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: 
N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered 
from 0 to N-1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, 
the percentage rate of price increment for each distributor or retailer. Then N lines follow, each 
describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from 
supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means 
that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate 
up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one 
space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 100005
using namespace std;

struct Node
{
	int parent;
	int level;
	vector<int> son;
};

Node N[MAX];
vector<int> check;

int main()
{
	int n;
	double p, r;
	cin >> n >> p >> r;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k == 0)
			check.push_back(i);
		else
		{
			while (k--)
			{
				int tmp;
				cin >> tmp;
				N[i].son.push_back(tmp);
				N[tmp].parent = i;
			}
		}
	}
	int root = 0;
	N[root].level = 0;
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		int slevel = N[tmp].level;
		for (int i = 0; i < N[tmp].son.size(); i++)
		{
			N[N[tmp].son[i]].level = slevel + 1;
			q.push(N[tmp].son[i]);
		}
	}
	int maxLev = MAX;
	int cnt = 0;
	for (int i = 0; i < check.size(); i++)
	{
		if (N[check[i]].level < maxLev)
		{
			maxLev = N[check[i]].level;
			cnt = 0;
		}
		if (N[check[i]].level == maxLev)
		{
			cnt++;
		}
	}
	double price = p * pow(1 + r / 100.0, maxLev);
	printf("%.4lf %d\n", price, cnt);
	return 0;
}