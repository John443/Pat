/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line 
contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number 
of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, 
respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, 
with the same format as the input. Notice that there must be NO extra space 
at the end of each line. Please be accurate to 1 decimal place.
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double coe[1001];
	int k, n;
	double d;
	for (int i = 0; i < 1001; i++)
	{
		coe[i] = 0;
	}
	cin >> k;
	while (k--)
	{
		cin >> n >> d;
		coe[n] += d;
	}
	cin >> k;
	while (k--)
	{
		cin >> n >> d;
		coe[n] += d;
	}
	int count = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (coe[i] != 0)
			count++;
	}
	cout << count;
	for (int i = 1000; i >= 0; i--)
	{
		if (coe[i] != 0)
		{
			cout << fixed << setprecision(1);
			cout << " " << i << " " << coe[i];
		}
	}
	return 0;
}
