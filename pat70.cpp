/*
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types 
of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now 
given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum 
total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three 
kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 
7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we 
can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third 
kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers 
N (<=1000), the number of different kinds of mooncakes, and D (<=500 thousand tons), the maximum 
total demand of the market. Then the second line gives the positive inventory amounts (in thousand 
tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All 
the numbers in a line are separated by a space.

Output Specification:

For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 
decimal places.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1005
using namespace std;

struct Mooncake
{
	double amount;
	double price;
	double avprice;
};

Mooncake mooncake[MAX];

bool cmp(Mooncake m1, Mooncake m2)
{
	return m1.avprice > m2.avprice;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> mooncake[i].amount;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> mooncake[i].price;
	}
	for (int i = 0; i < N; i++)
	{
		mooncake[i].avprice = mooncake[i].price / mooncake[i].amount;
	}
	sort(mooncake, mooncake + N, cmp);
	double num = 0.0;
	double ans = 0.0;
	for (int i = 0; i < N; i++)
	{
		if (num + mooncake[i].amount <= M)
		{
			num += mooncake[i].amount;
			ans += mooncake[i].price;
		}
		else
		{
			ans += (M - num) * mooncake[i].avprice;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}