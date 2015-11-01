/*
A traveler's map gives the distances between cities along the highways, together with the 
cost of each highway. Now you are supposed to write a program to help a traveler to decide 
the shortest path between his/her starting city and the destination. If such a shortest path 
is not unique, you are supposed to output the one with the minimum cost, which is guaranteed 
to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive 
integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are 
numbered from 0 to N-1); M is the number of highways; S and D are the starting and the 
destination cities, respectively. Then M lines follow, each provides the information of a 
highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting 
point to the destination, followed by the total distance and the total cost of the path. The 
numbers must be separated by a space and there must be no extra space at the end of output.
*/
#include<iostream>
#define INF 0x0FFFFFFF
using namespace std;

int leng[500][500];
int cost[500][500];
struct Set
{
	int path;
	int dist;
	bool known;
	int fee;
};
Set set[500];

void Print(int d, int s)
{
	if (set[d].path != s)
	{
		Print(set[d].path, s);
		cout << " ";
	}
	cout << d;
}

void Dijkstra(int s, int d, int n)
{
	set[s].dist = 0;
	set[s].fee = 0;
	for (int i = 0; i < n; i++)
	{
		int v;
		int min = INF;
		for (int j = 0; j < n; j++)
		{
			if(!set[j].known && set[j].dist < min)
			{
				min = set[j].dist;
				v = j;
			}
		}
		if (v == d || min == INF)
			break;
		set[v].known = true;
		for (int j = 0; j < n; j++)
		{
			if (!set[j].known && set[v].dist + leng[j][v] < set[j].dist)
			{
				set[j].dist = set[v].dist + leng[j][v];
				set[j].fee = set[v].fee + cost[j][v];
				set[j].path = v;
			}
			else if (set[v].dist + leng[j][v] == set[j].dist)
			{
				if (set[j].fee > set[v].fee + cost[j][v])
				{
					set[j].fee = set[v].fee + cost[j][v];
					set[j].path = v;
				}
			}
		}
	}
	cout << s << " ";
	Print(d, s);
	cout << " " << set[d].dist << " " << set[d].fee;
}

int main()
{
	int n, m, s, d;
	for (int i = 0; i < 500; i++)
	{
		set[i].path = 0;
		set[i].dist = INF;
		set[i].known = false;
		set[i].fee = INF;
		for (int j = 0; j < 500; j++)
		{
			leng[i][j] = INF;
			cost[i][j] = INF;
		}
	}
	cin >> n >> m >> s >> d;
	for (int k = 0; k < m; k++)
	{
		int i, j, l, c;
		cin >> i >> j >> l >> c;
		leng[i][j] = leng[j][i] = l;
		cost[i][j] = cost[j][i] = c;
	}
	Dijkstra(s, d, n);
	return 0;
}
