/*
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in 
non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking 
the second number from the first one. Repeat in this manner we will soon end up at the number 
6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each 
step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed 
as 4-digit numbers.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int Max[4], Min[4];

int main()
{
	int maximum, minimum;
	int n;
	cin >> n;
	do
	{
		for (int i = 0; i < 4; i++)
		{
			Max[i] = Min[i] = n % 10;
			n /= 10;
		}
		sort(Max, Max + 4, greater<int>());
		sort(Min, Min + 4);
		maximum = minimum = 0;
		for (int i = 0; i < 4; i++)
		{
			maximum = maximum * 10 + Max[i];
			minimum = minimum * 10 + Min[i];
		}
		n = maximum - minimum;
		printf("%04d - %04d = %04d\n", maximum, minimum, n);
	} while (n != 0 && n != 6174);
	return 0;
}