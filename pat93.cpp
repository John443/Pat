/*
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and 
the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:

Each input file contains one test case. For each case, there is only one line giving a string of no 
more than 105 characters containing only P, A, or T.

Output Specification:

For each test case, print in one line the number of PAT's contained in the string. Since the result 
may be a huge number, you only have to output the result moded by 1000000007.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	long long count = 0;
	int P = 0;
	int PA = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'T')
			count += PA;
		else if (s[i] == 'A')
			PA += P;
		else if (s[i] == 'P')
			P++;
	}
	cout << count % 1000000007 << endl;
	return 0;
}
