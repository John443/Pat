/*
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. 
This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, 
N (<=104), the total number of users, K (<=5), the total number of problems, and M (<=105), the total 
number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, 
and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), 
where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the 
information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is 
an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score 
obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has 
never submitted a solution for a problem, then "-" must be printed at the corresponding position. 
If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, 
users must be sorted in nonincreasing order according to the number of perfectly solved problems. 
And if there is still a tie, then they must be printed in increasing order of their id's. For those 
who has never submitted any solution that can pass the compiler, or has never submitted any solution, 
they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the 
ranklist.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 10005
using namespace std;

struct User
{
	int ID;
	int total;
	int p[6];
	int fullnum;
	int rank;
	bool tag;
};

User u[MAX];

bool cmp(const User & u1, const User & u2)
{
	if (u1.total > u2.total)
		return true;
	else if (u1.total == u2.total && u1.fullnum > u2.fullnum)
		return true;
	else if (u1.total == u2.total && u1.fullnum == u2.fullnum && u1.ID < u2.ID)
		return true;
	else
		return false;
}

int main()
{
	int N, K, M;
	cin >> N >> K >> M;
	int problem[6];
	for (int i = 1; i <= K; i++)
	{
		cin >> problem[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
			u[i].p[j] = -2;
		u[i].ID = i;
		u[i].total = 0;
		u[i].fullnum = 0;
		u[i].rank = 0;
		u[i].tag = false;
	}
	for (int i = 0; i < M; i++)
	{
		int u_id, p_id, score;
		cin >> u_id >> p_id >> score;
		if (u[u_id].p[p_id] < score)
		{
			u[u_id].p[p_id] = score;
			if (score == problem[p_id])
				u[u_id].fullnum++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (u[i].p[j] >= 0)
			{
				u[i].tag = true;
				u[i].total += u[i].p[j];
			}
		}
	}
	sort(u + 1, u + 1 + N, cmp);
	u[1].rank = 1;
	for (int i = 2; i <= N; i++)
	{
		if (u[i].total == u[i - 1].total)
			u[i].rank = u[i - 1].rank;
		else
			u[i].rank = i;
	}
	for (int i = 1; i <= N; i++)
	{
		if (u[i].tag == false)
			continue;
		printf("%d %05d %d", u[i].rank, u[i].ID, u[i].total);
		for (int j = 1; j <= K; j++)
		{
			if (u[i].p[j] >= 0)
				printf(" %d", u[i].p[j]);
			else if (u[i].p[j] == -1)
				printf(" 0");
			else if (u[i].p[j] == -2)
				printf(" -");
		}
		cout << endl;
	}
	return 0;
}
