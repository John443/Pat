/*
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 
to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 
9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. 
Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double 
a given number with k digits, you are to tell if the resulting number consists of only a 
permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no 
more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number 
that consists of only a permutation of the digits in the original number, or "No" if not. 
Then in the next line, print the doubled number.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string Twice(const string & s)
{
	string s2(s);
	int carry = 0;
	int tmp;
	for (auto it = s2.rbegin(); it != s2.rend(); it++)
	{
		tmp = (*it - '0') * 2 + carry;
		carry = tmp / 10;
		*it = tmp % 10 + '0';
	}
	if (carry > 0)
		s2.insert(s2.begin(), 1, carry + '0');
	return s2;
}

vector<char> Convert(string s)
{
	vector<char> v;
	for (int i = 0; i != s.size(); i++)
	{
		v.push_back(s[i]);
	}
	return v;
}

int main()
{
	string s1;
	cin >> s1;
	string s2 = Twice(s1);
	if (s2.size() > s1.size())
		cout << "No" << endl << s2;
	else
	{
		vector<char> v1 = Convert(s1);
		vector<char> v2 = Convert(s2);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		if (v1 == v2)
			cout << "Yes" << endl << s2;
		else
			cout << "No" << endl << s2;
	}
	return 0;
}
