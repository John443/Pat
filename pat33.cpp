/*
With highways available, driving a car from Hangzhou to any other city is easy. But since 
the tank capacity of a car is limited, we have to find gas stations on the way from time to 
time. Different gas station may give different price. You are asked to carefully design the 
cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive 
numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between 
Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the 
car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each 
contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance 
between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by 
a space.

Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. 
It is assumed that the tank is empty at the beginning. If it is impossible to reach the 
destination, print "The maximum travel distance = X" where X is the maximum possible distance 
the car can run, accurate up to 2 decimal places.
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Gas
{
	double price;
	double distance;
};

bool cmp(Gas g1, Gas g2)
{
	return g1.distance < g2.distance;
}

int main()
{
	double C, D, D_avg;
	int N;
	cin >> C >> D >> D_avg >> N;
	vector<Gas> station;
	Gas tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp.price >> tmp.distance;
		station.push_back(tmp);
	}
	tmp.price = 0;
	tmp.distance = D;
	station.push_back(tmp);
	sort(station.begin(), station.end(), cmp);
	if (station[0].distance != 0)
	{
		cout << "The maximum travel distance = 0.00" << endl;
	}
	else
	{
		int v = 0;
		double maxdis = C * D_avg;
		double fee = 0;
		double left;
		while (station[v].distance < D)
		{
			double minPrice = -1;
			int minTag = -1, findTag = -1;
			for (int j = v + 1; j <= N && (station[j].distance - station[v].distance <= maxdis); j++)
			{
				if (minPrice == -1 || station[j].price < minPrice)
				{
					minPrice = station[j].price;
					minTag = j;
				}
				if (findTag == -1 && station[v].price > station[j].price)
				{
					findTag = j;
				}
			}
			if (minTag == -1)
				break;
			if (findTag == -1)
			{
				if (D - station[v].distance <= maxdis)
				{
					fee += ((D - station[v].distance) / D_avg - left) * station[v].price;
					left = 0;
					v = N;
				}
				else
				{
					fee += (C - left) * station[v].price;
					left = C - (station[minTag].distance - station[v].distance) / D_avg;
					v = minTag;
				}
			}
			else
			{
				fee += ((station[findTag].distance - station[v].distance) / D_avg - left) * station[v].price;
				left = 0;
				v = findTag;
			}
		}
		if (station[v].distance == D)
			printf("%.2f", fee);
		else
		{
			cout << "The maximum travel distance = ";
			printf("%.2f", station[v].distance + maxdis);
		}
	}
	return 0;
}
