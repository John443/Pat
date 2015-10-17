/*
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day 
when the call is made. When a customer starts connecting a long-distance call, the time will 
be recorded, and so will be the time when the customer hangs up the phone. Every calendar 
month, a bill is sent to the customer for each minute called (at a rate determined by the 
time of day). Your job is to prepare the bills for each month, given a set of phone call 
records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and 
the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll 
(cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in 
the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each 
phone call record consists of the name of the customer (string of up to 20 characters 
without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is 
paired with the chronologically next record for the same customer provided it is an 
"off-line" record. Any "on-line" records that are not paired with an "off-line" record are 
ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed 
that at least one call is well paired in the input. You may assume that no two records for 
the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first 
print in a line the name of the customer and the month of the bill in the format shown by 
the sample. Then for each time period of a call, print in one line the beginning and ending 
time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls 
must be listed in chronological order. Finally, print the total charge for the month in the 
format shown by the sample.
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;

int rate[24];

struct Record
{
	int month;
	int day;
	int hour;
	int minu;
	string tag;
};

bool cmp(Record & r1, Record & r2)
{
	if (r1.month < r2.month)
		return true;
	else if (r1.month == r2.month && r1.day < r2.day)
		return true;
	else if (r1.month == r2.month && r1.day == r2.day && r1.hour < r2.hour)
		return true;
	else if (r1.month == r2.month && r1.day == r2.day && r1.hour == r2.hour && r1.minu < r2.minu)
		return true;
	else
		return false;
}

double CountFee(Record r1, Record r2, int * totaltime)
{
	*totaltime = 0;
	double fee = 0;
	while (r1.day < r2.day || r1.hour < r2.hour || r1.minu < r2.minu)
	{
		fee += rate[r1.hour];
		(*totaltime)++;
		r1.minu++;
		if (r1.minu == 60)
		{
			r1.minu = 0;
			r1.hour++;
			if (r1.hour == 24)
			{
				r1.hour = 0;
				r1.day++;
			}
		}
	}
	return fee;
}

int main()
{
	for (int i = 0; i < 24; i++)
	{
		cin >> rate[i];
	}
	int n;
	cin >> n;
	map<string, vector<Record>> list;
	for (int i = 0; i < n; i++)
	{
		string name;
		char c[3];
		Record temp;
		cin >> name >> temp.month >> c[0] >> temp.day >> c[1] >> temp.hour >> c[2] >> temp.minu >> temp.tag;
		list[name].push_back(temp);
	}
	map<string, vector<Record>>::iterator m;
	vector<Record>::iterator r;
	for (m = list.begin(); m != list.end(); m++)
	{
		sort((m->second).begin(), (m->second).end(), cmp);
	}
	for (m = list.begin(); m != list.end(); m++)
	{
		int totaltime = 0;
		double totalcost = 0;
		bool find = false;
		for (r = (m->second).begin(); r != (m->second).end(); r++)
		{
			Record temp = *r;
			if (temp.tag == "on-line")
			{
				if ((r + 1) != (m->second).end())
				{
					Record next = *(r + 1);
					if (next.tag == "off-line")
					{
						if (!find)
						{
							cout << m->first << " ";
							cout << setfill('0') << setw(2) << r->month << endl;
							find = true;
						}
						cout << setfill('0') << setw(2) << temp.day << ":";
						cout << setfill('0') << setw(2) << temp.hour << ":";
						cout << setfill('0') << setw(2) << temp.minu << " ";
						cout << setfill('0') << setw(2) << next.day << ":";
						cout << setfill('0') << setw(2) << next.hour << ":";
						cout << setfill('0') << setw(2) << next.minu << " ";
						double fee = CountFee(temp, next, &totaltime);
						cout << totaltime << " $" << fixed << setprecision(2) << fee / 100.0 << endl;
						totalcost += fee;
					}
				}
			}
		}
		if (find)
		{
			cout << "Total amount: $" << fixed << setprecision(2) << totalcost/100.0 << endl;
		}
	}
	return 0;
}
