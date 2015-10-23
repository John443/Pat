/*
A Digital Library contains millions of books, stored according to their titles, authors, 
key words of their abstracts, publishers, and published years. Each book is assigned an 
unique 7-digit number as its ID. Given any query from a reader, you are supposed to output 
the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=10000) which is the total number of books. Then N blocks follow, each contains 
the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any 
white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; 
there are no more than 1000 distinct key words in total; and there are no more than 1000 
distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is 
the number of user's search queries. Then M lines follow, each in one of the formats shown 
below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting 
book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" 
instead.
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<map<string, vector<string>>> map(6);
	string s, id, tmp;
	while (N--)
	{
		cin >> id;
		getchar();
		getline(cin, s);
		map[1][s].push_back(id);
		getline(cin, s);
		map[2][s].push_back(id);
		getline(cin, s);
		while (s.size())
		{
			int blank = s.find(" ");
			if (blank == -1)
			{
				map[3][s].push_back(id);
				break;
			}
			tmp = s.substr(0, blank);
			map[3][tmp].push_back(id);
			s = s.substr(blank + 1);
		}
		getline(cin, s);
		map[4][s].push_back(id);
		getline(cin, s);
		map[5][s].push_back(id);
	}
	int M;
	cin >> M;
	getchar();
	while (M--)
	{
		getline(cin, s);
		cout << s << endl;
		int k = s[0] - '0';
		s = s.substr(3);
		if (map[k].find(s) == map[k].end())
		{
			cout << "Not Found" << endl;
		}
		else
		{
			sort(map[k][s].begin(), map[k][s].end());
			for (auto it = map[k][s].begin(); it != map[k][s].end(); it++)
			{
				cout << *it << endl;
			}
		}
	}
	return 0;
}
