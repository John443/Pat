/*
There is a public bike service in Hangzhou City which provides great convenience to the 
tourists from all over the world. One may rent a bike at any station and return it to 
any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the 
stations. A station is said to be in perfect condition if it is exactly half-full. If a 
station is full or empty, PBMC will collect or send bikes to adjust the condition of that 
station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach 
that station. If there are more than one shortest path, the one that requires the least 
number of bikes sent from PBMC will be chosen.

Figure 1(see it on http://www.patest.cn/contests/pat-a-practise/1018)
Figure 1 illustrates an example. The stations are represented by vertices and the roads 
correspond to the edges. The number on an edge is the time taken to reach one end station 
from another. The number written inside a vertex S is the current number of bikes stored at 
S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we 
have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 
bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from 
PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: 
Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), 
the total number of stations; Sp, the index of the problem station (the stations are 
numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. 
The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current 
number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, 
and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers 
in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that 
PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally 
after another space, output the number of bikes that we must take back to PBMC after the 
condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes 
that we must take back to PBMC. The judge's data guarantee that such a path is unique.
*/
#include<iostream>
#define INF 0x0FFFFFFF
using namespace std;

struct Set
{
	int path;
	int dist;
	int send;
	int back;
	bool known;
};

Set set[501];
int g[501][501];

void Dijkstra (int sp, int N, int C)
{
	set[sp].dist = 0;
	if (g[sp][sp] == 0)
    {
        set[sp].send = C / 2;
    }
    else
    {
        set[sp].back = C / 2;
    }
    int min, minSend, minBack;
    int tmp = sp;
    for (int i = 0; i <= N; i++)
    {
        int v = tmp;
    	min = INF;
    	if(v == 0)
    		break;
    	set[v].known = true;
    	for (int j = 0; j <= N; j++)
    	{
    		if (!set[j].known)
    		{
    			if (set[j].dist > set[v].dist + g[j][v])
    			{
    				set[j].dist = set[v].dist + g[j][v];
    				set[j].send = set[v].send + C / 2 - g[j][j];
                    set[j].back = set[v].back;
                    if (set[j].send < 0)
                    {
                        set[j].back -= set[j].send;
                        set[j].send = 0;
                    }
                    set[j].path = v;
    			}
    			else if (set[j].dist == set[v].dist + g[j][v])
    			{
    				int tmpSend = set[v].send + C / 2 - g[j][j];
    				int tmpBack = set[v].back;
    				if (tmpSend < 0)
                    {
                        tmpBack -= tmpSend;
                        tmpSend = 0;
                    }
                    if (tmpSend < set[j].send)
                    {
                        set[j].path = v;
                        set[j].send = tmpSend;
                        set[j].back = tmpBack;
                    }
                    else if (tmpSend == set[j].send && tmpBack < set[j].back)
                    {
                        set[j].path = v;
                        set[j].back = tmpBack;
                    }
    			}
                if (set[j].dist < min)
                {
                    min = set[j].dist;
                    minSend = set[j].send;
                    minBack = set[j].back;
                    tmp = j;
                }
                else if (set[j].dist == min)
                {
                    if (minSend > set[j].send)
                    {
                        minSend = set[j].send;
                        minBack = set[j].back;
                        tmp = j;
                    }
                    else if (minSend == set[j].send && minBack > set[j].back)
                    {
                        minBack = set[j].back;
                        tmp = j;
                    }
                }
    		}
    	}
    }
    cout << set[0].send << " ";
    int i = 0;
    while (i != sp)
    {
    	cout << i << "->";
    	i = set[i].path;
    }
    cout << i << " ";
    cout << set[0].back;
}

int main()
{
	int N, C, sp, M;
	cin >> C >> N >> sp >> M;
	for (int i = 0; i < 501; i++)
	{
		set[i].dist = INF;
		set[i].known = false;
		set[i].send = 0;
		set[i].back = 0;
		for (int j = 0; j < 501; j++)
		{
			g[i][j] = INF;
		}
	}
	g[0][0] = C / 2;
	for (int i = 1; i <= N; i++)
	{
		cin >> g[i][i];
	}
	for (int k = 0; k < M; k++)
	{
		int i, j, l;
		cin >> i >> j >> l;
		g[i][j] = g[j][i] = l;
	}
	Dijkstra (sp, N, C);
	return 0;
}