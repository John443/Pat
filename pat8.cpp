/*
The highest building in our city has only one elevator. A request list is made up with N positive 
numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 
6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will 
stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when 
the requests are fulfilled.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N positive 
numbers. All the numbers in the input are less than 100.

Output Specification:

For each test case, print the total time on a single line.
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	const int up = 6;
	const int down = 4;
	const int stop = 5;
	vector<int> elevator;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			elevator.push_back(num);
		}
		int sum = n * stop;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				sum += elevator[0] * up;
			else if (elevator[i] > elevator[i - 1])
				sum += (elevator[i] - elevator[i - 1]) * up;
			else if (elevator[i] < elevator[i - 1])
				sum += (elevator[i - 1] - elevator[i]) * down;
		}
		cout << sum;
	}
	return 0;
}