/*
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains 
the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms 
in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. 
It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as 
the input. Notice that there must be NO extra space at the end of each line. Please be accurate 
up to 1 decimal place.
*/
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main()
{
	int k, n;
	double d;
	double coe[2001];
	double temp[2001];
	for (int i = 0; i < 2001; i++)
	{
		coe[i] = temp[i] = 0;
	}
	cin >> k;
	int k_temp = k;
	vector<int> n_temp;
	while (k--)
	{
		cin >> n >> d;
		temp[n] = d;
		n_temp.push_back(n);
	}
	cin >> k;
	while (k--)
	{
		cin >> n >> d;
		for (int i = 0; i < k_temp; i++)
		{
			coe[n + n_temp[i]] += temp[n_temp[i]] * d;
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (coe[i] != 0)
		{
			count++;
		}
	}
	cout << count;
	for (int i = 2000; i >= 0; i--)
	{
		if (coe[i] != 0)
		{
			cout << fixed << setprecision(1);
			cout << " " << i << " " << coe[i];
		}
	}
	return 0;
}