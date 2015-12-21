/*
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, 
and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" 
where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) 
is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, 
you must re-define the table size to be the smallest prime number which is larger than the size given 
by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: 
MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, 
respectively. Then N distinct positive integers are given in the next line. All the numbers in a line 
are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in 
one line. All the numbers in a line are separated by a space, and there must be no extra space at 
the end of the line. In case it is impossible to insert the number, print "-" instead.
*/
#include <iostream>
#define MAX 10010
using namespace std;

int Hash[MAX];
int visited[MAX];

bool IsPrime(int n)
{
	if (n == 2)
		return true;
	else if (n < 2 || n % 2 == 0)
	{
		return false;
	}
	for (int i = 3; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int m, n;
	cin >> m >> n;
	int size = m;
	while (!IsPrime(size))
	{
		size++;
	}
	int index;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		Hash[i] = -1;
		for (int j = 0; j < size; j++)
		{
			index = (tmp % size + j * j) % size;
			if (!visited[index])
			{
				visited[index] = 1; Hash[i] = index;
				break;
			}
		}
	}
	cout << Hash[0];
	for (int i = 1; i < n; i++)
	{
		if (Hash[i] == -1)
			cout << " -";
		else
			cout << " " << Hash[i];
	}
	cout << endl;
	return 0;
}
