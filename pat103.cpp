/*
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K 
positive integers. You are supposed to write a program to find the K-P factorization of N for any 
positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers 
N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, 
such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with 
the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen 
-- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 
1<=L<=K such that ai=bi for i<L and aL>bL

If there is no solution, simple output "Impossible".
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int P;
long long N, K;

long long Lpower(long long n, long long p)
{
	if (n == 1)
		return 1;
	int factor = n;
	for (int i = 1; i < p; i++)
		n *= factor;
	return n;
}

vector<int> final;
int curSum = 0;

bool DFS(long long N, int cur, vector<int> & factors)
{
	if (cur == K)
	{
		if (N == 0)
		{
			int sum = 0;
			for (int i = 0; i < factors.size(); i++)
				sum += factors[i];
			if (sum >= curSum)
			{
				final = factors;
				curSum = sum;
			}
			return true;
		}
		else
			return false;
	}
	long long lower = cur > 0 ? factors[cur - 1] : 1;
	long long upper = sqrt(double(N));
	for (long long i = lower; i <= upper; i++)
	{
		long long res = Lpower(i, P);
		if (N >= res)
		{
			factors[cur] = i;
			if (N >= res)
			{
				DFS(N - res, cur + 1, factors);
			}
			else
				return false;
		}
	}
	return true;
}

int main()
{
	cin >> N >> K >> P;
	vector<int> factors(K);
	DFS(N, 0, factors);
	reverse(final.begin(), final.end());
	if (final.size() == K)
	{
		cout << N << " = ";
		for (int i = 0; i < final.size(); i++)
		{
			if (i == 0)
				cout << final[i] << "^" << P;
			else
				cout << " + " << final[i] << "^" << P;
		}
	}
	else
		cout << "Impossible";
	cout << endl;
	return 0;
}
