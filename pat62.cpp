/*
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about 
people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue 
must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called 
a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than 
a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according 
to Sima Guang's theory.

Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: 
N (<=105), the total number of people to be ranked; 
L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent 
  and virtue are both not below this line will be ranked; and 
H (<100), the higher line of qualification -- that is, those with both grades not below this line are 
  considered as the "sages", and will be ranked in non-increasing order according to their total grades. 
  Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also 
  ranked in non-increasing order according to their total grades, but they are listed after the "sages". 
Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". 
They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the 
L line are ranked after the "fool men".

Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers 
are separated by a space.
Output Specification:

The first line of output must give M (<=N), the total number of people that are actually ranked. 
Then M lines follow, each gives the information of a person in the same format as the input, according 
to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their 
virtue grades in non-increasing order. If there is still a tie, then output in increasing order of 
their ID's.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
	int ID;
	int Virtue;
	int Talent;
	int Total;
};

bool cmp(Person p1, Person p2)
{
	if (p1.Total > p2.Total)
		return true;
	else if (p1.Total == p2.Total && p1.Virtue > p2.Virtue)
		return true;
	else if (p1.Total == p2.Total && p1.Virtue == p2.Virtue && p1.ID < p2.ID)
		return true;
	else
		return false;
}

vector<Person> sage;
vector<Person> nobleman;
vector<Person> foolman;
vector<Person> other;

int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		Person tmp;
		cin >> tmp.ID >> tmp.Virtue >> tmp.Talent;
		tmp.Total = tmp.Virtue + tmp.Talent;
		if (tmp.Virtue >= H && tmp.Talent >= H)
		{
			sage.push_back(tmp);
			total++;
		}
		else if (tmp.Virtue >= H && tmp.Talent < H && tmp.Talent >= L)
		{
			nobleman.push_back(tmp);
			total++;
		}
		else if (tmp.Virtue < H && tmp.Virtue >= L && tmp.Talent < H && tmp.Talent >= L && tmp.Virtue >= tmp.Talent)
		{
			foolman.push_back(tmp);
			total++;
		}
		else if (tmp.Virtue >= L && tmp.Talent >= L)
		{
			other.push_back(tmp);
			total++;
		}
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(nobleman.begin(), nobleman.end(), cmp);
	sort(foolman.begin(), foolman.end(), cmp);
	sort(other.begin(), other.end(), cmp);
	//cout << total << endl;
	printf("%d\n", total);
	vector<Person>:: iterator it;
	for (it = sage.begin(); it != sage.end(); it++)
		//cout << it -> ID << " " << it -> Virtue << " " << it -> Talent << endl;
		printf("%08d %d %d\n", it->ID, it->Virtue, it->Talent);
	for (it = nobleman.begin(); it != nobleman.end(); it++)
		//cout << it -> ID << " " << it -> Virtue << " " << it -> Talent << endl;
		printf("%08d %d %d\n", it->ID, it->Virtue, it->Talent);
	for (it = foolman.begin(); it != foolman.end(); it++)
		//cout << it -> ID << " " << it -> Virtue << " " << it -> Talent << endl;
		printf("%08d %d %d\n", it->ID, it->Virtue, it->Talent);
	for (it = other.begin(); it != other.end(); it++)
		//cout << it -> ID << " " << it -> Virtue << " " << it -> Talent << endl;
		printf("%08d %d %d\n", it->ID, it->Virtue, it->Talent);
	return 0;
}