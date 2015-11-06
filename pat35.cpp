/*
To prepare for PAT, the judge sometimes has to generate random passwords for the users. The 
problem is that there are always some confusing passwords since it is hard to distinguish 1 
(one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to 
replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program 
to check the accounts generated by the judge, and to help the juge modify the confusing 
passwords.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N (<= 1000), 
followed by N lines of accounts. Each account consists of a user name and a password, both 
are strings of no more than 10 characters with no space.

Output Specification:

For each test case, first print the number M of accounts that have been modified, then print 
in the following M lines the modified accounts info, that is, the user names and the 
corresponding modified passwords. The accounts must be printed in the same order as they are 
read in. If no account is modified, print in one line "There are N accounts and no account is 
modified" where N is the total number of accounts. However, if N is one, you must print "There 
is 1 account and no account is modified" instead.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	string s1, s2;
	cin >> n;
	vector<pair<string, string> > result;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		bool tag = false;
		for (int j = 0; j != s2.size(); j++)
		{
			if (s2[j] == '1')
			{
				s2[j] = '@';
				tag = true;
			}
			if (s2[j] == 'l')
			{
				s2[j] = 'L';
				tag = true;
			}
			if (s2[j] == '0')
			{
				s2[j] = '%';
				tag = true;
			}
			if (s2[j] == 'O')
			{
				s2[j] = 'o';
				tag = true;
			}
		}
		if (tag)
			result.push_back(make_pair(s1, s2));
	}
	int k = result.size();
	if (k == 0)
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified";
		else
			cout << "There are " << n << " accounts and no account is modified";
	}
	else
	{
		cout << k << endl;
		for(int i = 0; i < k; i++)
			cout << result[i].first << " " << result[i].second << endl;
	}
	return 0;
}