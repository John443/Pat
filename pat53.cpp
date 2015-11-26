/*
Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of 
a path from R to L is defined to be the sum of the weights of all the nodes along the path from 
R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a 
given number. For example, let's consider the tree showed in Figure 1: for each node, the upper 
number is the node ID which is a two-digit number, and the lower number is the weight of that node. 
Suppose that the given number is 24, then there exists 4 different paths which have the same given 
weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges 
in Figure 1(http://www.patest.cn/contests/pat-a-practise/1053).

Input Specification:

Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the 
number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given 
weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree 
node Ti. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its 
children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, 
let us fix the root ID to be 00.

Output Specification:

For each test case, print all the paths with weight S in non-increasing order. Each path occupies 
a line with printed weights from the root to the leaf in order. All the numbers must be separated 
by a space with no extra space at the end of the line.

Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there 
exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, S;
vector<int> adjoin[105];
vector<int> path;
int weight[105];
int visited[105];

void DFS(int w, int ID)
{
	visited[ID] = 1;
	w += weight[ID];
	if (w > S)
		return;
	else if (w == S && adjoin[ID].size() == 0)
	{
		path.push_back(weight[ID]);
		cout << path[0];
		for (int i = 1; i < path.size(); i++)
		{
			cout << " " << path[i];
		}
		cout << endl;
		path.pop_back();
	}
	else if (w < S && adjoin[ID].size() > 0)
	{
		int maxweight = 0;
		int maxid = 0;
		path.push_back(weight[ID]);
		while (maxid != -1)
		{
			maxid = maxweight = -1;
			for (int i = 0; i < adjoin[ID].size(); i++)
			{
				if (!visited[adjoin[ID][i]] && weight[adjoin[ID][i]] > maxweight)
				{
					maxweight = weight[adjoin[ID][i]];
					maxid = adjoin[ID][i];
				}
			}
			if (maxid != -1)
			{
				DFS(w, maxid);
			}
		}
		path.pop_back();
	}
	return;
}

int main()
{
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < M; i++)
	{
		int ID, k;
		cin >> ID >> k;
		for (int j = 0; j < k; j++)
		{
			int child;
			cin >> child;
			adjoin[ID].push_back(child);
		}
	}
	DFS(0, 0);
	return 0;
}