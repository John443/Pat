/*
Eva loves to collect coins from all over the universe, including some other planets like Mars. 
One day she visited a universal shopping mall which could accept all kinds of coins as payments. 
However, there was a special requirement of the payment: for each bill, she could only use 
exactly two coins to pay the exact amount. Since she has as many as 105 coins with her, she 
definitely needs your help. You are supposed to tell her, for any given amount of money, whether 
or not she can find two coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive 
numbers: N (<=105, the total number of coins) and M(<=103, the amount of money Eva has to pay). 
The second line contains N face values of the coins, which are all positive numbers no more than 
500. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the two face values V1 and V2 (separated by a space) 
such that V1 + V2 = M and V1 <= V2. If such a solution is not unique, output the one with the 
smallest V1. If there is no solution, output "No Solution" instead.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> coin;

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}
	sort(coin.begin(), coin.end());
	int sum = 0;
	int left = 0;
	int right = N - 1;
	bool tag = false;
	while (left < right)
	{
		sum = coin[left] + coin[right];
		if (sum == K)
		{
			cout << coin[left]<< " " << coin[right] << endl;
			tag = true;
			break;
		}
		else if (sum > K)
			right--;
		else
			left++;
	}
	if (!tag)
		cout << "No Solution" << endl;
	return 0;
}