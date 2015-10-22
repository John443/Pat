/*
A graph which is connected and acyclic can be considered a tree. The height of the tree 
depends on the selected root. Now you are supposed to find the root that results in a highest 
tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 
to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, 
print them in increasing order of their numbers. In case that the given graph is not a tree, 
print "Error: K components" where K is the number of connected components in the graph.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define MAX 10005
using namespace std;

int dis[MAX];
vector<int> adj[MAX];
int parent[MAX];
int N;

int Find(int x)
{
	int p = x;
	while (p != parent[p])
		p = parent[p];
	return p;
}

void Union(int x, int y)
{
	int fx, fy;
	fx = Find(x);
	fy = Find(y);
	if (fx != fy)
		parent[fx] = fy;
}

int BFS(int start)
{
	for (int i = 1; i <= N; i++)
	{
		dis[i] = -1;
	}
	queue<int> q;
	q.push(start);
	dis[start] = 0;
	int maxdis = 0;
	while (!q.empty())
	{
		int cur = q.front();
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int tmp = adj[cur][i];
			if (dis[tmp] < 0)
			{
				q.push(tmp);
				dis[tmp] = dis[cur] + 1;
				if (dis[tmp] > maxdis)
					maxdis = dis[tmp];
			}
		}
		q.pop();
	}
	return maxdis;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		Union(x, y);
	}
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (parent[i] == i)
			count++;
	}
	if (count > 1)
		cout << "Error: " << count << " components" << endl;
	else
	{
		map<int, int> m;
		int max = BFS(1);
		int index;
		bool first = true;
		for (int i = 1; i <= N; i++)
		{
			if (dis[i] == max && first)
			{
				index = i;
				m[i]++;
				first = false;
			}
			else if (dis[i] == max)
			{
				m[i]++;
			}
		}
		max = BFS(index);
		dis[N] = max;
		for (int i = 1; i <= N; i++)
		{
			if (dis[i] == max)
				m[i]++;
		}
		map<int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++)
		{
			cout << it->first << endl;
		}
	}
	return 0;
}
