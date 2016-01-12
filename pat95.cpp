/*
Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect the in/out times 
and the plate numbers of the cars crossing the gate. Now with all the information available, you are 
supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of 
the day find the cars that have parked for the longest time period.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<= 10000), the 
number of records, and K (<= 80000) the number of queries. Then N lines follow, each gives a record in 
the format

plate_number hh:mm:ss status

where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents 
the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 
23:59:59; and status is either in or out.

Note that all times will be within a single day. Each "in" record is paired with the chronologically 
next record for the same car provided it is an "out" record. Any "in" records that are not paired with 
an "out" record are ignored, as are "out" records not paired with an "in" record. It is guaranteed that 
at least one car is well paired in the input, and no car is both "in" and "out" at the same moment. 
Times are recorded using a 24-hour clock.

Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are 
given in ascending order of the times.

Output Specification:

For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Car
{
	string plate;
	int time;
	bool tag;
};

bool cmp(Car c1, Car c2)
{
	if (c1.plate < c2.plate)
	{
		return true;
	}
	else if (c1.plate == c2.plate)
	{
		if (c1.time < c2.time)
			return true;
	}
	return false;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<Car> data(N);
	string stime;
	for (int i = 0; i < N; i++)
	{
		string a;
		int h, m, s;
		cin >> a;
		data[i].plate = a;
		scanf("%d:%d:%d", &h, &m, &s);
		data[i].time = (h * 60 + m) * 60 + s;
		cin >> a;
		if (a[0] == 'i')
			data[i].tag = false;
		else
			data[i].tag = true;
	}
	sort(data.begin(), data.end(), cmp);
	vector<int> inTime(24 * 60 * 60, 0);
	vector<int> outTime(24 * 60 * 60, 0);
	vector<string> maxPlate;
	string curPlate = data[0].plate;
	int curTime = 0;
	int maxTime = 0;
	for (int i = 1; i < N; i++)
	{
		if (data[i].plate == data[i - 1].plate)
		{
			if (data[i].tag && !data[i - 1].tag)
			{
				curTime += data[i].time - data[i - 1].time;
				if (curTime > maxTime)
				{
					maxTime = curTime;
					maxPlate.clear();
					maxPlate.push_back(curPlate);
				}
				else if (curTime == maxTime)
				{
					maxPlate.push_back(curPlate);
				}
				inTime[data[i - 1].time]++;
				outTime[data[i].time]++;
			}
		}
		else
		{
			curTime = 0;
			curPlate = data[i].plate;
		}
	}
	vector<int> res(24 * 60 * 60, 0);
	int tmp = 0;
	for (int i = 0; i < 24 * 60 * 60; i++)
	{
		tmp += res[i] + inTime[i] - outTime[i];
		res[i] = tmp;
	}
	while (K--)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		printf("%d\n", res[(h * 60 + m) * 60 + s]);
	}
	for (auto it = maxPlate.begin(); it != maxPlate.end(); it++)
	{
		cout << *it << " ";
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	return 0;
}
