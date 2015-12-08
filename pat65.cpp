/*
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, 
each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where 
X is the case number (starting from 1).
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a, b, c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		long long temp = a + b;
		if (a > 0 && b > 0 && temp <= 0)
			cout << "Case #" << i << ": true" << endl;
		else if (a < 0 && b < 0 && temp >= 0)
			cout << "Case #" << i << ": false" << endl;
		else
		{
			if (a + b > c)
				cout << "Case #" << i << ": true" << endl;
			else
				cout << "Case #" << i << ": false" << endl;
		}
	}
	return 0;
}