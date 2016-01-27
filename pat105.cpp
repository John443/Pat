/*
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing 
order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a 
clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m*n must be 
equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then 
the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no 
more than 104. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 
1 space between two adjacent numbers, and no extra space at the end of each line.
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int num[100][100], flag[100][100];

bool cmp(const int & a, const int & b)
{
	return a > b;
}

int cal(int x)
{
	int y = sqrt(x);
	while (y > 0)
	{
		if (x % y == 0)
			return y;
		else
			--y;
	}
	return 1;
}

int main()
{
	int n;
	int sx = 0, sy = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int y = cal(n);
	int x = n / y;
	sort(v.begin(), v.end(), cmp);
	int cnt = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			flag[i][j] = 1;
	}
	while (cnt < n)
	{
		while (sy < y && flag[sx][sy] != 0)
		{
			num[sx][sy] = v[cnt++];
			flag[sx][sy] = 0;
			++sy;
		}
		--sy;
		++sx;
		while (sx < x && flag[sx][sy] != 0)
		{
			num[sx][sy] = v[cnt++];
			flag[sx][sy] = 0;
			++sx;
		}
		--sx;
		--sy;
		while (sy >= 0 && flag[sx][sy] != 0)
		{
			num[sx][sy] = v[cnt++];
			flag[sx][sy] = 0;
			--sy;
		}
		++sy;
		--sx;
		while (sx >= 0 && flag[sx][sy] != 0)
		{
			num[sx][sy] = v[cnt++];
			flag[sx][sy] = 0;
			--sx;
		}
		++sx;
		++sy;
	}
	for (int i = 0; i < x; i++)
	{
		cout << num[i][0];
		for (int j = 1; j < y; j++)
		{
			cout << " " << num[i][j];
		}
		cout << endl;
	}
	return 0;
}
