/*
Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. 
Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut 
at any position for only once and some of the diamonds are taken off the chain one by one. Once 
a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 
diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:

1. Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 
(with values 3+2+1+5+4=15).
2. Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 
(with values 5+4+6=15).
3. Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
Now given the chain of diamond values and the amount that a customer has to pay, you are 
supposed to list all the paying options for the customer.

If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: 
N (<=105), the total number of diamonds on the chain, and M (<=108), the amount that the 
customer has to pay. Then the next line contains N positive numbers D1 ... DN (Di<=103 for 
all i=1, ..., N) which are the values of the diamonds. All the numbers in a line are 
separated by a space.

Output Specification:

For each test case, print "i-j" in a line for each pair of i <= j such that 
Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be 
printed in increasing order of i.

If there is no solution, output "i-j" for pairs of i <= j such that Di + ... + Dj > M with 
(Di + ... + Dj - M) minimized. Again all the solutions must be printed in increasing order 
of i.

It is guaranteed that the total value of diamonds is sufficient to pay the given amount.
*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n, k;
	//cin >> n >> k;
	scanf("%d%d", &n, &k);
	int dia[100005];
	for (int i = 1; i <= n; i++)
	{
		//cin >> dia[i];
		scanf("%d", &dia[i]);
	}
	int sum = 0;
	int min = 0xFFFFFFF;
	int p1 = 1;
	int p2 = 1;
	vector<int> list;
	bool tag = false;
	while (p1 <= n)
	{
		while (sum < k && p2 <= n)
		{
			sum += dia[p2++];
		}
		if (sum == k)
		{
			if (!tag)
			{
				tag = true;
				list.clear();
			}
			list.push_back(p1);
			list.push_back(p2 - 1);
			min = 0;
		}
		else
		{
			if (sum > k)
			{
				if (min > sum - k)
				{
					min = sum - k;
					list.clear();
					list.push_back(p1);
					list.push_back(p2 - 1);
				}
				else if (min == sum - k)
				{
					list.push_back(p1);
					list.push_back(p2 - 1);
				}
			}
		}
		sum -= dia[p1];
		++p1;
	}
	for (int i = 0; i < list.size(); i++)
	{
		//cout << list[i] << "-" << list[i + 1] << endl;
		printf("%d-%d\n",list[i], list[i + 1]);
		i++;
	}
	return 0;
}
