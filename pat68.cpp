/*
Eva loves to collect coins from all over the universe, including some other planets like Mars. One 
day she visited a universal shopping mall which could accept all kinds of coins as payments. However, 
there was a special requirement of the payment: for each bill, she must pay the exact amount. Since 
she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, 
for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: 
N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second 
line contains N face values of the coins, which are all positive numbers. All the numbers in a line 
are separated by a space.

Output Specification:

For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that 
V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra 
space at the end of the line. If such a solution is not unique, output the smallest sequence. If 
there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there 
exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].
*/
#include <iostream>
#include <functional>
#include <algorithm>
#define N 10005
#define M 105
using namespace std;

int coin[N];
int dp[N][M], flag[N][M];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	sort(coin + 1, coin + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= m; j++)
		{
			if (dp[i - 1][j] <= dp[i - 1][j - coin[i]] + coin[i])
			{
				dp[i][j] = dp[i - 1][j - coin[i]] + coin[i];
				flag[i][j] = 1;
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	if (dp[n][m] != m)
	{
		cout << "No Solution";
	}
	else
	{
		bool tag = true;
		for (int i = n; i >= 1 && m > 0; i--)
		{
			if (flag[i][m])
			{
				if (tag)
				{
					cout << coin[i];
					tag = false;
				}
				else
					cout << " " << coin[i];
				m -= coin[i];
			}
		}
	}
	return 0;
}