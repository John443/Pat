/*
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their 
sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format 
"a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a 
negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be 
non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational 
numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that 
all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and 
a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. 
If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the 
output integers are in the range of long int.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

long long Gcd(long long a, long long b)
{
	long long r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

string f(long long a, long long b)
{
	if (a == 0)
		return "0";
	string s;
	stringstream ss;
	int flag = 1;
	if (a < 0)
	{
		flag = -1;
		a = -a;
		ss << "(-";
	}
	long long tmp = Gcd(a, b);
	a /= tmp;
	b /= tmp;
	if (a % b == 0)
		ss << a / b;
	else if (a / b > 0)
	{
		ss << a / b << " ";
		ss << a % b << "/" << b;
	}
	else
	{
		ss << a << "/" << b;
	}
	if (flag == -1)
		ss << ")";
	getline(ss, s);
	return s;
}

int main()
{
	long a1, b1, a2, b2;
	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
	string s1 = f(a1, b1);
	string s2 = f(a2, b2);
	cout << s1 << " + " << s2 << " = " << f(a1 * b2 + a2 * b1, b1 * b2) << endl;
	cout << s1 << " - " << s2 << " = " << f(a1 * b2 - a2 * b1, b1 * b2) << endl;
	cout << s1 << " * " << s2 << " = " << f(a1 * a2, b1 * b2) << endl;
	cout << s1 << " / " << s2 << " = ";
	if (a2 == 0)
	{
		cout << "Inf";
	}
	else
	{
		long long d1 = a1 * b2;
		long long d2 = a2 * b1;
		if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 < 0))
		{
			d1 = -d1;
			d2 = -d2;
		}
		cout << f(d1, d2);
	}
	cout << endl;
	return 0;
}
