/*
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）
-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P 
and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the 
supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: 
N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); 
P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor 
or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for 
the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are 
separated by a space.

Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate 
up to 2 decimal places, and the number of retailers that sell at the highest price. There must be 
one space between the two numbers. It is guaranteed that the price will not exceed 1010.
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#define MAX 100005
using namespace std;

int N;
double P, r;
vector<int> v[MAX];
deque<int> q;
int visited[MAX];
int root;

void BFS(int root, int * height, int count[])
{
	q.push_back(root);
	visited[root] = 1;
	int endNode = q.back();
	while (!q.empty())
	{
		int index = q.front();
		q.pop_front();
		for (int i = 0; i < v[index].size(); i++)
		{
			int j = v[index][i];
			if (!visited[j])
			{
				visited[j] = 1;
				q.push_back(j);
			}
		}
		if (index == endNode)
		{
			(*height)++;
			count[*height] = q.size();
			endNode = q.back();
		}
	}
}

int main()
{
	cin >> N >> P >> r;
	int count[MAX];
	int height = 0;
	count[0] = 1;
	for (int i = 0; i < N; i++)
	{
		int index;
		cin >> index;
		if (index == -1)
			root = i;
		else
			v[index].push_back(i);
	}
	BFS(root, &height, count);
	printf("%.2lf %d\n", P * pow(1 + r / 100.0, height - 1), count[height - 1]);
	return 0;
}
