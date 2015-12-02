/*
Given any positive integer N, you are supposed to find all of its prime factors, and write them in 
the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing 
order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must 
NOT be printed out.
*/
#include<iostream>
#include<vector>
using namespace std;

bool IsPrime(int n)
{
	if (n <= 1)
		return false;
	else if (n == 2 || n == 3)
		return true;
	else
	{
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
}

int main()
{
	long N;
	cin >> N;
	if (N == 1)
		cout << "1=1";
	else
	{
		vector<int> result;
		long tmp = N;
		while (tmp != 1)
		{
			for (int i = 2; i <= tmp; i++)
			{
				if (IsPrime(i) && (tmp % i == 0))
				{
					result.push_back(i);
					tmp /= i;
					break;
				}
			}
		}
		cout << N << "=";
		vector<int>::iterator it = result.begin();
		cout << *it;
		long pre = *it;
		int cnt = 1;
		it++;
		while (it != result.end())
		{
			while (it < result.end() && *it == pre)
			{
				cnt++;
				it++;
			}
			if (cnt > 1)
			{
				cout << "^" << cnt;
				cnt = 1;
			}
			else
			{
				cout << "*" << *it;
				pre = *it;
				it++;
			}
		}
	}
	return 0;
}
