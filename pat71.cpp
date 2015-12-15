/*
People often have a preference among synonyms of the same word. For example, some may prefer 
"the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down 
a speaker's identity, which is useful when validating, for example, whether it's still the same 
person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly 
used word?

Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 
1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one 
alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed 
by a space and the number of times it has occurred in the input. If there are more than one such 
words, print the lexicographically smallest one. The word should be printed in all lower case. Here 
a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical 
characters or the line beginning/end.

Note that words are case insensitive.
*/
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

map<string, int> m;
map<string, int>::iterator it;

int main()
{
	char c;
	string s;
	while (c = getchar(), c != '\n')
	{
		if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z')
		{
			s.push_back(c);
		}
		else if (c >= 'A' && c <= 'Z')
		{
			s.push_back(c + 'a' - 'A');
		}
		else
		{
			if (!s.empty())
			{
				m[s]++;
				s.clear();
			}
		}
	}
	if (!s.empty())
	{
		m[s]++;
		s.clear();
	}
	int max_cnt = 0;
	string res;
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second > max_cnt)
		{
			max_cnt = it->second;
			res = it->first;
		}
		else if (it->second == max_cnt && res > it->first)
		{
			res = it->first;
		}
	}
	cout << res << " " << max_cnt << endl;
	return 0;
}