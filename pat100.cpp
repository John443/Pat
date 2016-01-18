/*
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" 
on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, 
elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds 
to 115 on Earth. In order to help communication between people from these two planets, you are supposed 
to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer 
N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an 
Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;

string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
	int N;
	map<string, int> low2int, high2int;
	for (int i = 0; i < 13; i++)
		low2int[low[i]] = i;
	for (int i = 1; i < 13; i++)
		high2int[high[i - 1]] = i;
	string s;
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++)
	{
		getline(cin, s);
		if (isdigit(s[0]))
		{
			int base = 13;
			int res = 0;
			for (int j = 0; j < s.size(); j++)
			{
				res = res * 10 + s[j] - '0';
			}
			vector<int> v;
			if (res == 0)
				v.push_back(0);
			while (res != 0)
			{
				v.push_back(res % base);
				res /= base;
			}
			if (v.size() == 1)
				cout << low[v[0]] << endl;
			else
			{
				if (v[0] != 0)
					cout << high[v[1] - 1] << " " << low[v[0]] << endl;
				else
					cout << high[v[1] - 1] << endl;
			}
		}
		else
		{
			string tmp;
			stringstream ss;
			vector<string> v;
			ss.str(s);
			while (!ss.fail())
			{
				ss >> tmp;
				v.push_back(tmp);
			}
			if (v.size() == 1)
			{
				if (low2int.find(v[0]) != low2int.end())
					cout << low2int[v[0]] << endl;
				else if (high2int.find(v[0]) != high2int.end())
					cout << high2int[v[0]] * 13 << endl;
			}
			else
			{
				cout << high2int[v[0]] * 13 + low2int[v[1]] << endl;
			}
		}
	}
	return 0;
}
