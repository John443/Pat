/*
A gas station has to be built at such a location that the minimum distance between the station and 
any of the residential housing is as far away as possible. However it must guarantee that all the 
houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed 
to give the best recommendation. If there are more than one solution, output the one with the smallest 
average distance to all the houses. If such a solution is still not unique, output the one with the 
smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: 
N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for 
the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and 
DS, the maximum service range of the gas station. It is hence assumed that all the houses are 
numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, 
and Dist is the integer length of the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, 
print the minimum and the average distances between the solution and all the houses. The numbers in 
a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not 
exist, simply output “No Solution”.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 1015
#define INF 0x0FFFFFFF
using namespace std;

int G[MAX][MAX];
int dis[MAX];
bool known[MAX];

int Trans(char * str, int n)
{
	if (str[0] == 'G')
		return atoi(str + 1) + n - 1;
	else
		return atoi(str) -1;
}

void Dijkstra(int gas, int dis[], int total)
{
	for (int i = 0; i < total; i++)
	{
		dis[i] = G[gas][i];
		known[i] = false;
	}
	int k;
	int min = INF;
	for (int i = 1; i < total; i++)
	{
		min = INF;
		for (int j = 0; j < total; j++)
		{
			if (!known[j] && min > dis[j])
			{
				min = dis[j];
				k = j;
			}
		}
		known[k] = true;
		for (int j = 0; j < total; j++)
		{
			if (!known[j] && dis[j] > dis[k] + G[j][k])
			{
				dis[j] = dis[k] + G[j][k];
			}
		}
	}
}

int main()
{
	int N, M, K, D;
	cin >> N >> M >> K >> D;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			G[i][j] = INF;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b;
		char str[10];
		cin >> str;
		a = Trans(str, N);
		cin >> str;
		b = Trans(str, N);
		cin >> G[a][b];
		G[b][a] = G[a][b];
	}
	int total = N + M;
	int choice = -1;
	double ansmaxdis = -1;
	double ansavgdis = INF;
	for (int i = N; i < total; i++)
	{
		double mindis = INF;
		double avgdis = 0;
		bool tag = true;
		Dijkstra(i, dis, total);
		for (int j = 0; j < N; j++)
		{
			if (mindis > dis[j])
			{
				mindis = dis[j];
			}
			if (dis[j] > D)
			{
				tag = false;
				break;
			}
			avgdis += dis[j];
		}
		if (!tag)
			continue;
		avgdis /= N;
		if (mindis > ansmaxdis)
		{
			ansmaxdis = mindis;
			ansavgdis = avgdis;
			choice = i;
		}
		else if (mindis == ansmaxdis)
		{
			if (ansavgdis > avgdis)
			{
				ansavgdis = avgdis;
				choice = i;
			}
		}
	}
	if (choice != -1)
	{
		cout << "G" << choice + 1 - N << endl;
		printf("%.1f %.1f\n", double(ansmaxdis), double(ansavgdis));
	}
	else
	{
		cout << "No Solution" << endl;
	}
	return 0;
}