/*
As an emergency rescue team leader of a city, you are given 
a special map of your country. The map shows several scattered cities connected by some roads. 
Amount of rescue teams in each city and the length of each road between any pair of cities 
are marked on the map. When there is an emergency call to you from some other city, your job 
is to lead your men to the place as quickly as possible, and at the mean time, call up 
as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, 
the first line contains 4 positive integers: N (<= 500) - the number of cities 
(and the cities are numbered from 0 to N-1), M - the number of roads, 
C1 and C2 - the cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of rescue teams 
in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, 
which are the pair of cities connected by a road and the length of that road, respectively. 
It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: 
the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams 
you can possibly gather.
All the numbers in a line must be separated by exactly one space, 
and there is no extra space allowed at the end of a line.
*/
#include<iostream>
using namespace std;
const int MAX_SIZE = 10000;
const int inf = 10000;

class Graph
{
private:
        int n, m, c1, c2;
        int team[500];
        int road[500][500];
        bool known[500];
        int dist[500];
        int maxteam[500];
        int path[500];
public:
        Graph()
        {
                n = m = c1 = c2 = 0;
                for (int i = 0; i < 500; i++)
                {
                       team[i] = 0;
                       for (int j = 0; j < 500; j++)
                               road[i][j] = inf;
                }
        }
        ~Graph() {}
        void Input()
        {
                cin >> n >> m >> c1 >> c2;
                for (int i = 0; i < n; i++)
                {
                       cin >> team[i];
                }
                for (int k = 0; k < m; k++)
                {
                        int i, j, l;
                        cin >> i >> j >> l;
                        road[i][j] = road[j][i] = l;
                }
        }
        void Dijkstra()
        {
                for (int i = 0; i < n; i++)
                {
                        known[i] = false;
                        dist[i] = inf;
                        path[i] = 0;
                        maxteam[i] = 0;
                }
                dist[c1] = 0;
                path[c1] = 1;
                maxteam[c1] = team[c1];
                for (int i = 0; i < n; i++)
                {
                        int p = 0;
                        int min = inf;
                        for (int j = 0; j < n; j++)
                        {
                                if (known[j] == false && dist[j] < min)
                                {
                                        min = dist[j];
                                        p = j;
                                }
                        }
                        if (p == c2 || min == inf)
                                return;
                        //if do not want to use return, put the known[], dist[], path[] and 
                        //maxteam[] in the function and use break in the if()
                        known[p] = true;
                        for (int j = 0; j < n; j++)
                        {
                                if (known[j] == true)continue;
                                if (dist[p] + road[p][j] < dist[j])
                                {
                                        dist[j] = dist[p] + road[p][j];
                                        path[j] = path[p];
                                        maxteam[j] = maxteam[p] + team[j];
                                }
                                else if (dist[p] + road[p][j] == dist[j])
                                {
                                        path[j] = path[p] + path[j];
                                        if (maxteam[j] < maxteam[p] + team[j])
                                        {
                                                maxteam[j] = maxteam[p] + team[j];
                                        }
                                }
                        }
                }
        }
        void Display(){ cout << path[c2] << " " << maxteam[c2]; }
};

int main()
{
        Graph G;
        G.Input();
        G.Dijkstra();
        G.Display();
        return 0;
}
