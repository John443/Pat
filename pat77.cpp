/*
The Japanese language is notorious for its sentence ending particles. Personal preference of such 
particles can be considered as a reflection of the speaker's personality. Such a preference is called 
"Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial 
sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). 
Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's 
spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix 
of all N lines. If there is no such suffix, write "nai".
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s[305];
	getchar();
	for (int i = 0; i < n; i++)
		getline(cin, s[i]);
	int len = s[0].size();
	bool tag = false;
	int index;
	int i;
	for (i = 0; i < len; i++)
	{
		for (int j = 1; j < n; j++)
		{
			int k = s[j].size() - 1;
			int m = s[j - 1].size() - 1;
			if (s[j][k - i] != s[j - 1][m - i] || i > k || i > m)
			{
				index = i;
				tag = true;
				break;
			}
		}
		if (tag)
			break;
	}
	if (i == len)
		index = 0;
	else
		index = len - index;
	if (index == len)
		cout << "nai" << endl;
	else
	{
		cout << s[0].substr(index) << endl;
	}
	return 0;
}
