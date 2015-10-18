/*
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which 
devides the waiting area into two parts. All the customers have to wait in line behind the yellow 
line, until it is his/her turn to be served and there is a window available. It is assumed that no 
window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the 
average waiting time of all the customers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: 
N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines 
follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes 
of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that 
no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 
08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

Output Specification:

For each test case, print in one line the average waiting time of all the customers, in minutes and 
accurate up to 1 decimal place.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Customer
{
	int arrive;
	int process;
	int start;
	int leave;
};

bool cmp(Customer c1, Customer c2)
{
	return c1.arrive < c2.arrive;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<Customer> cust(n);
	for (int i = 0; i < n; i++)
	{
		int hh, mm, ss, proc;
		char c[2];
		cin >> hh >> c[0] >> mm >> c[1] >> ss >> proc;
		cust[i].arrive = (hh * 60 + mm) * 60 + ss;
		cust[i].process = proc * 60;
	}
	sort(cust.begin(), cust.end(), cmp);
	vector<int> window(k, 8 * 3600);
	int label;
	for (int i = 0; i < n; i++)
	{
		int min = 300000;
		for (int j = 0; j < k; j++)
		{
			if (window[j] < min)
			{
				min = window[j];
				label = j;
			}
		}
		cust[i].start = window[label]>cust[i].arrive ? window[label] : cust[i].arrive;
		cust[i].leave = cust[i].start + cust[i].process;
		window[label] = cust[i].leave;
	}
	double sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (cust[i].arrive <= 17 * 3600)
		{
			sum += (cust[i].start - cust[i].arrive);
			count++;
		}
	}
	cout << fixed << setprecision(1) << (sum / 60 / count) << endl;
	return 0;
}
