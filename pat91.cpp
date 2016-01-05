/*
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given 
the results of image analysis in which the core regions are identified in each MRI slice, your job 
is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: 
M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N 
matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and 
T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must 
not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents 
a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have 
to count the number of 1's to obtain the volume. However, there might be several separated core regions 
in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" 
and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 
6 red pixels are connected to the blue one.

Output Specification:

For each case, output in a line the total volume of the stroke core.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Point
{
public:
	int z, x, y;
	Point(int z, int x, int y): z(z), x(x), y(y) {}
	~Point() {}
};

int main()
{
	int m, n, l, t;
	cin >> m >> n >> l >> t;
	vector<vector<vector<int> > > mat;
	for (int k = 0; k < l; k++)
	{
		vector<vector<int> > v1;
		for (int i = 0; i < m; i++)
		{
			vector<int> v2;
			for (int j = 0; j < n; j++)
			{
				int tmp;
				cin >> tmp;
				v2.push_back(tmp);
			}
			v1.push_back(v2);
		}
		mat.push_back(v1);
	}
	int total = 0;
	queue<Point> q;
	int v;
	for (int k = 0; k < l; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[k][i][j] == 1)
				{
					v = 0;
					q.push(Point(k, i, j));
					while (!q.empty())
					{
						Point p = q.front();
						q.pop();
						int z = p.z;
						int x = p.x;
						int y = p.y;
						if (mat[z][x][y] == 1)
						{
							mat[z][x][y] = 2;
							++v;
							if (z > 0)
								q.push(Point(z - 1, x, y));
							if (z < l - 1)
								q.push(Point(z + 1, x, y));
							if (x > 0)
								q.push(Point(z, x - 1, y));
							if (x < m - 1)
								q.push(Point(z, x + 1, y));
							if (y > 0)
								q.push(Point(z, x, y - 1));
							if (y < n - 1)
								q.push(Point(z, x, y + 1));
						}
					}
					total += v >= t? v: 0;
				}
			}
		}
	}
	cout << total << endl;
	return 0;
}
