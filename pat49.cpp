/*
The task is simple: given any positive integer N, you are supposed to count the total number 
of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there 
are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int base = 1;
	int m = n;
	while (n != 0)
	{
		int tmp = n / 10;
		if (n % 10 > 1)
			sum += base;
		else if (n % 10 == 1)
			sum += m % base + 1;
		sum += tmp * base;
		base *= 10;
		n /= 10;
	}
	cout << sum << endl;
	return 0;
}
