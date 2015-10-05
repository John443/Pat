/*
A family hierarchy is usually presented by a pedigree tree. Your job is to count 
those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, 
the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, 
each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, 
followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the 
root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every 
seniority level starting from the root. The numbers must be printed in a line, separated by a space, 
and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. 
Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. 
Then we should output "0 1" in a line.
*/
#include<iostream>
using namespace std;

class Tree
{
private:
	int n, m;
	int node[100][100];
	int res[100];
	int level;
public:
	Tree()
	{
		n = m = 0;
		for (int i = 0; i < 100; i++)
		{
			res[i] = 0;
			for (int j = 0; j < 100; j++)
			{
				node[i][j] = 0;
			}
		}
		level = 1;
	}
	~Tree() {}
	void Input()
	{
		cin >> n >> m;
		if(n == 0 || n <= m)
			return;
		for (int i = 0; i < m; i++)
		{
			int id, k;
			cin >> id >> k;
			for (int i = 0; i < k; i++)
			{
				int id_temp;
				cin >> id_temp;
				node[id][i] = id_temp;
			}
		}
	}
	bool Judge()
	{
		if (n == 0)
		{
			return false;
		}
		if (n > 1 && m == 0)
		{
			res[1] = n;
			return false;
		}
		return true;
	}
	void DFS(int id, int level)
	{
		int count = 0;
		for (int i = 0; i < 100; i++)
		{
			if (node[id][i] != 0)
				count++;
		}
		if (count == 0)
		{
			res[level]++;
		}
		for (int i = 0; i < count; i++)
		{
			this->level = max(level + 1, this->level);
			DFS(node[id][i], level + 1);	
		}
	}
	void Display()
	{
		for (int i = 1; i <= level; i++)
		{
			if (i == 1)
			{
				cout << res[i];
			}
			else
			{
				cout << " " << res[i];
			}
		}
	}
};

int main()
{
	Tree tree;
	tree.Input();
	if (tree.Judge())
	{
		tree.DFS(1, 1);
		tree.Display();
	}
	else
		tree.Display();
	return 0;
}
