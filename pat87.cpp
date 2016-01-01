/*
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your 
clients the route with the least cost while gaining the most happiness.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers 
N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed 
by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that 
represents the happiness one can gain from that city, except the starting city. Then K lines follow, 
each describes a route between two cities in the format "City1 City2 Cost". Here the name of a city is 
a string of 3 capital English letters, and the destination is always ROM which represents Rome.

Output Specification:

For each test case, we are supposed to find the route with the least cost. If such a route is not unique, 
the one with the maximum happiness will be recommended. If such a route is still not unique, then we 
output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution 
exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with 
the least cost, the cost, the happiness, and the average happiness (take the integer part only) of 
the recommended route. Then in the next line, you are supposed to print the route in the format 
"City1->City2->...->ROM".
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define MAXN 205
#define MAX 0x0FFFFFFF
using namespace std;

int n, k;
int G[MAXN][MAXN];
string name[MAXN];
int happiness[MAXN];
map<string, int> m;
int dis[MAXN];
int visited[MAXN];
vector<int> path;
int sumHp = 0, avgHp = 0, routeSum = 0, shortest = MAX;

void Dijkstra()
{
	for (int i = 0; i < n; i++)
	{
		dis[i] = G[0][i];
		visited[i] = 0;
	}
	int k = 0, min;
	dis[0] = 0;
	visited[0] = 1;
	for (int i = 1; i < n; i++)
	{
		min = MAX;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dis[j] < min)
			{
				min = dis[j];
				k = j;
			}
		}
		visited[k] = 1;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && dis[k] + G[k][j] < dis[j])
			{
				dis[j] = dis[k] + G[k][j];
			}
		}
	}
}

void DFS(int start, int end, vector<int> & tpath, int hpSum, int pathSum)
{
	if (pathSum > shortest)
		return;
	if (start == end)
	{
		if (pathSum > shortest)
			return;
		routeSum++;
		if (hpSum < sumHp)
			return;
		int avg = hpSum / (tpath.size() - 1);
		if (avg > avgHp)
		{
			avgHp = avg;
			path = tpath;
			sumHp = hpSum;
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && G[start][i] != MAX)
		{
			tpath.push_back(i);
			visited[i] = 1;
			DFS(i, end, tpath, hpSum + happiness[i], pathSum + G[start][i]);
			tpath.pop_back();
			visited[i] = 0;
		}
	}
}

int main()
{
	string city;
	int dest;
	cin >> n >> k >> city;
	name[0] = city;
	m[city] = 0;
	happiness[0] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> name[i] >> happiness[i];
		if (name[i] == "ROM")
			dest = i;
		m[name[i]] = i;
	}
	for (int i = 0; i < MAXN; i++)
	{
		dis[i] = MAX;
		for (int j = 0; j < MAXN; j++)
		{
			G[i][j] = MAX;
		}
	}
	for (int i = 0; i < k; i++)
	{
		string city1, city2;
		int cost;
		cin >> city1 >> city2 >> cost;
		int c1 = m[city1];
		int c2 = m[city2];
		if (cost < G[c1][c2])
			G[c1][c2] = G[c2][c1] = cost;
	}
	Dijkstra();
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	shortest = dis[dest];
	visited[0] = 1;
	vector<int> tpath(1, 0);
	DFS(0, dest, tpath, 0, 0);
	cout << routeSum << " " << shortest << " " << sumHp << " " << avgHp << endl;
	cout << city;
	for (int i = 1; i < path.size(); i++)
	{
		cout << "->" << name[path[i]];
	}
	return 0;
}
