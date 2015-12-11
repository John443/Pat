/*
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. 
But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort 
{4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first 
N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation 
sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.
*/
#include <iostream>
#define MAX 100005
using namespace std;

int Check(int Array[], int begin, int end)
{
	for (int i = begin; i <= end; i++)
	{
		if (Array[i] != i)
			return i;
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;
	int Array[MAX];
	for (int i = 0; i < N; i++)
		cin >> Array[i];
	int index = Check(Array, 1, N - 1);
	int ans = 0;
	while (index)
	{
		if (Array[0] == 0)
		{
			Array[0] = Array[index];
			Array[index] = 0;
			ans++;
		}
		while (Array[0] != 0)
		{
			int tmp = Array[0];
			Array[0] = Array[tmp];
			Array[tmp] = tmp;
			ans++;
		}
		index = Check(Array, index, N - 1);
	}
	cout << ans;
	return 0;
}