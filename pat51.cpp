/*
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N 
and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop 
sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 
from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers 
(all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), 
and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop 
sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the 
stack, or "NO" if not.
*/
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

bool isValid(int list[], int len, int cap)
{
	stack<int> s;
	int cur = 1;
	int ind = 0;
	while (ind < len)
	{
		while (s.empty() || s.top() != list[ind])
		{
			if (cur > list[ind] || s.size() >= cap)
				return false;
			s.push(cur++);
		}
		s.pop();
		++ind;
	}
	return true;
}

int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	int list[1005];
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> list[j];
		if (isValid(list, N, M))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}