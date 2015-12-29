/*
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters 
corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please 
list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and 
the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are 
either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). 
It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The 
English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed 
that there is at least one worn out key.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s1, s2, res;
	cin >> s1 >> s2;
	int m = s1.size();
	int n = s2.size();
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (s1[i] != s2[j])
		{
			res += s1[i];
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	while (i < m)
	{
		res += s1[i++];
	}
	vector<bool> tag(256, false);
	for (auto it = res.begin(); it != res.end(); it++)
	{
		char tmp = toupper(*it);
		if (!tag[tmp])
		{
			tag[tmp] = true;
			cout << tmp;
		}
	}
	return 0;
}