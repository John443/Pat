/*
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology 
of Zhejiang University. Each test is supposed to run simultaneously in several places, and 
the ranklists will be merged immediately after the test. Now it is your job to write a 
program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive 
number N (<=100), the number of test locations. Then N ranklists follow, each starts with 
a line containing a positive integer K (<=300), the number of testees, and then K lines 
containing the registration number (a 13-digit number) and the total score of each testee. 
All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the 
final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of 
the final ranks. The testees with the same score must have the same rank, and the output 
must be sorted in nondecreasing order of their registration numbers.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Testee
{
	string ID;
	int score;
	int location;
	int total_rank;
	int local_rank;
};

bool cmp(Testee t1, Testee t2)
{
	if (t1.score != t2.score)
		return t1.score > t2.score;
	else
		return t1.ID < t2.ID;
}

int main()
{
	int n, k;
	cin >> n;
	vector<Testee> Local;
	vector<Testee> Total;
	for (int i = 0; i < n; i++)
	{
		Local.clear();
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			Testee tmp;
			cin >> tmp.ID >> tmp.score;
			tmp.location = i + 1;
			tmp.local_rank = tmp.total_rank = 0;
			Local.push_back(tmp);
		}
		sort(Local.begin(), Local.end(), cmp);
		Local[0].local_rank = 1;
		int count = 0;
		for (int j = 1; j < k; j++)
		{
			if (Local[j].score == Local[j - 1].score)
			{
				Local[j].local_rank = Local[j - 1].local_rank;
				count++;
			}
			else
			{
				Local[j].local_rank = Local[j - 1].local_rank + 1 + count;
				count = 0;
			}
		}
		for (int j = 0; j < k; j++)
			Total.push_back(Local[j]);
	}
	sort(Total.begin(), Total.end(), cmp);
	Total[0].total_rank = 1;
	int count = 0;
	for (int j = 1; j != Total.size(); j++)
	{
		if (Total[j].score == Total[j - 1].score)
		{
			Total[j].total_rank = Total[j - 1].total_rank;
			count++;
		}
		else
		{
			Total[j].total_rank = Total[j - 1].total_rank + 1 + count;
			count = 0;
		}
	}
	cout << Total.size() << endl;
	for (int i = 0; i != Total.size(); i++)
	{
		cout << Total[i].ID << " " << Total[i].total_rank << " " << Total[i].location << " " << Total[i].local_rank << endl;
	}
	return 0;
}
