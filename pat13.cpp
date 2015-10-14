/*
It is vitally important to have all the cities connected by highways in a war. If a city is 
occupied by the enemy, all the highways from/toward that city are closed. We must know immediately 
if we need to repair any other highways to keep the rest of the cities connected. Given the map of 
cities which have all the remaining highways marked, you are supposed to tell the number of highways 
need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then 
if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers 
N (<1000), M and K, which are the total number of cities, the number of remaining highways, 
and the number of cities to be checked, respectively. Then M lines follow, each describes 
a highway by 2 integers, which are the numbers of the cities the highway connects. The cities 
are numbered from 1 to N. Finally there is a line containing K numbers, which represent the 
cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that 
city is lost.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Find(vector<int> & root, int a)
{
	if (root[a] != a)
		root[a] = Find(root, root[a]);
	return root[a];
}

int GraphNum(const vector<pair<int, int>> & road, int N, int lostcity)
{
	vector<int> root;
	int result = N - 1;
	for (int i = 0; i <= N; i++)
	{
		root.push_back(i);
	}
	for (auto it = road.begin(); it != road.end(); it++)
	{
		if ((*it).first != lostcity && (*it).second != lostcity)
		{
			int ar = Find(root, (*it).first);
			int br = Find(root, (*it).second);
			if (ar != br)
			{
				result--;
				root[ar] = br;
			}
		}
	}
	return result;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<pair<int, int>> road;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		road.push_back(make_pair(a, b));
	}
	int x;
	while (K--)
	{
		cin >> x;
		cout << (GraphNum(road, N, x) - 1) << endl;
	}
	return 0;
}
