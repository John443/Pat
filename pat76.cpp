/*
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may 
follow many other users as well. Hence a social network is formed with followers relations. When a 
user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then 
be forwarded again by their followers. Now given a social network, you are supposed to calculate the 
maximum potential amount of forwards for any specific user, assuming that only L levels of indirect 
followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: 
N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are 
counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each 
in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list 
of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. 
All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this 
user can triger, assuming that everyone who can view the initial post will forward it once, and that 
only L levels of indirect followers are counted.
*/
#include <iostream>
#include <queue>
#define MAX 1005
using namespace std;

int relation[MAX][MAX];
bool visited[MAX];

void Init(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			relation[i][j] = 0;
}

int BFS(int n, int query, int l)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	q.push(query);
	visited[query] = true;
	int curlevel = 0;
	int cnt = 0;
	int endlevel = q.back();
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		for (int j = 1; j <= n; j++)
		{
			if (relation[i][j] == 1 && !visited[j])
			{
				cnt++;
				visited[j] = true;
				q.push(j);
			}
		}
		if (i == endlevel)
		{
			curlevel++;
			endlevel = q.back();
		}
		if (curlevel == l)
			break;
	}
	return cnt;
}

int main()
{
	int n, l;
	cin >> n >> l;
	Init(n);
	int k;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int index;
			cin >> index;
			relation[index][i] = 1;
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int query;
		cin >> query;
		int cnt = BFS(n, query, l);
		cout << cnt << endl;
	}
	return 0;
}
