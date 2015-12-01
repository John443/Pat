/*
Stack is one of the most fundamental data structures, which is based on the principle of 
Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top 
position) and Pop (deleting the top element). Now you are supposed to implement a stack with an 
extra operation: PeekMedian -- return the median value of all the elements in the stack. With N 
elements, the median value is defined to be the (N/2)-th smallest element if N is even, or 
((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer 
N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian 
command, print in a line the corresponding returned value. If the command is invalid, print 
"Invalid" instead.
*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdio>
#define MAX 100005
using namespace std;

int TreeArray[MAX];

int lowbit(int n)
{
	return n & (-n);
}

void update(int key, int num)
{
	while (key <= MAX)
	{
		TreeArray[key] += num;
		key += lowbit(key);
	}
}

int GetSum(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += TreeArray[n];
		n -= lowbit(n);
	}
	return sum;
}

int BinSearch(int target)
{
	int left = 0;
	int right = MAX;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int sum = GetSum(mid);
		if (sum > target)
			right = mid - 1;
		else if (sum < target)
			left = mid + 1;
		else if (sum == target)
			right = mid - 1;
	}
	return left;
}

int main()
{
	int N;
	//cin >> N;
	scanf("%d", &N);
	stack<int> s;
	char c[20];
	while (N--)
	{
		//cin >> c;
		scanf("%s", &c);
		switch(c[1])
		{
			case 'o':
				if (s.empty())
					//cout << "Invalid" << endl;
					printf("Invalid\n");
				else
				{
					int key = s.top();
					s.pop();
					//cout << key << endl;
					printf("%d\n", key);
					update(key, -1);
				}
				break;
			case 'u':
				int key;
				//cin >> key;
				scanf("%d", &key);
				s.push(key);
				update(key, 1);
				break;
			case 'e':
				if (s.empty())
					//cout << "Invalid" << endl;
					printf("Invalid\n");
				else
				{
					int mid = BinSearch((s.size() + 1) / 2);
					//cout << mid << endl;
					printf("%d\n", mid);
				}
				break;
		}
	}
	return 0;
}