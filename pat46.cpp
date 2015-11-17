/*
The task is really simple: given N exits on a highway which forms a simple cycle, you are 
supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N 
(in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between 
the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers 
in a line are separated by a space. The second line gives a positive integer M (<=104), with 
M lines follow, each contains a pair of exit numbers, provided that the exits are numbered 
from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between 
the corresponding given pair of exits.
*/
#include<iostream>
#include<cstdio>
using namespace std;

int arr[100001];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		arr[i] = arr[i - 1] + tmp;
	}
	int M;
	scanf("%d", &M);
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
			a ^= b ^= a ^= b;
		if (arr[b - 1] - arr[a - 1] < arr[N] - arr[b - 1] + arr[a - 1])
			printf("%d\n", arr[b - 1] - arr[a - 1]);
		else
			printf("%d\n", arr[N] - arr[b - 1] + arr[a - 1]);
	}
	return 0;
}