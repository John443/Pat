/*
There is a classical process named partition in the famous quick sort algorithm. In this process we 
typically choose one element as the pivot. Then the elements less than the pivot are moved to its left 
and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, 
could you tell how many elements could be the selected pivot for this partition?

For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer 
N (<= 105). Then the next line contains N distinct positive integers no larger than 109. The numbers 
in a line are separated by spaces.

Output Specification:

For each test case, output in the first line the number of pivot candidates. Then in the next line 
print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, 
and no extra space at the end of each line.
*/
#include <iostream>
#include <algorithm>
#define MAX 100005
using namespace std;

int maxn[MAX], minn[MAX], ans[MAX], store[MAX];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> store[i];
	}
	store[0] = -1;
	store[n + 1] = 1e9 + 1;
	int maxi = -1;
	int mini = 1e9 + 1;
	for (int i = 1; i <= n; i++)
	{
		maxn[i] = maxi;
		minn[n - i + 1] = mini;
		if (store[i] > maxi)
			maxi = store[i];
		if (store[n - i + 1] < mini)
			mini = store[n - i + 1];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (store[i] > maxn[i] && store[i] < minn[i])
			ans[cnt++] = store[i];
	}
	sort(ans, ans + cnt);
	cout << cnt << endl;
	if (cnt > 0)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (i == 0)
				cout << ans[i];
			else
				cout << " " << ans[i];
		}
	}
	cout << endl;
	return 0;
}
