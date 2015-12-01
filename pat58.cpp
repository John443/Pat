/*
If you are a fan of Harry Potter, you would know the world of magic has its own currency system 
-- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts 
to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are 
given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is 
an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, 
separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the 
input.
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a[3], b[3];
	char c;
	cin >> a[0] >> c >> a[1] >> c >> a[2];
	cin >> b[0] >> c >> b[1] >> c >> b[2];
	a[2] = a[2] + b[2];
	if (a[2] >= 29)
	{
		a[1]++;
		a[2] -= 29;
	}
	a[1] = a[1] + b[1];
	if (a[1] >= 17)
	{
		a[0]++;
		a[1] -= 17;
	}
	a[0] = a[0] + b[0];
	cout << a[0] << "." << a[1] << "." << a[2] << endl;
	return 0;	
}
