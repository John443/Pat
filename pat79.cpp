/*
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）
-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price 
P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the 
customers. It is assumed that each member in the supply chain has exactly one supplier except the 
root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:

Each input file contains one test case. For each case, the first line contains three positive numbers: 
N (<=10^5), the total number of the members in the supply chain (and hence their ID's are numbered 
from 0 to N-1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and 
r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, 
each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products 
from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means 
that the j-th member is a retailer, then instead the total amount of the product will be given after 
Kj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the total sales we can expect from all the retailers, accurate 
up to 1 decimal place. It is guaranteed that the number will not exceed 10^10.
*/
#include <iostream>
#include <cstdio>
#define MAX 100005
using namespace std;

struct Node
{
	int amount;
	int parent;
	double price;	
};

int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;
	Node n[MAX];
	n[0].price = P;
	for (int i = 0; i < N; i++)
	{
		int index;
		int num;
		cin >> num;
		n[i].amount = 0;
		if (num == 0)
			cin >> n[i].amount;
		else
		{
			for (int j = 0; j < num; j++)
			{
				cin >> index;
				n[index].parent = i;
				if (n[i].price != 0)
					n[index].price = n[i].price * (1 + r /100.0);
			}
		}
	}
	double total = 0;
	for (int i = 0; i < N; i++)
	{
		if (n[i].price == 0)
			n[i].price = n[n[i].parent].price * (1 + r / 100.0);
		if (n[i].amount != 0)
			total += n[i].amount * n[i].price;
	}
	printf("%.1lf\n", total);
	return 0;
}
