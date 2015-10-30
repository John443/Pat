/*
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers 
N (<=100000) and C, where N is the number of records and C is the column that you are supposed 
to sort the records with. Then N lines follow, each contains a record of a student. A 
student's record consists of his or her distinct ID (a 6-digit number), name (a string with 
no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records 
must be sorted in increasing order according to ID's; if C = 2 then the records must be 
sorted in non-decreasing order according to names; and if C = 3 then the records must be 
sorted in non-decreasing order according to grades. If there are several students who have 
the same name or grade, they must be sorted according to their ID's in increasing order.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

struct  Stu
{
	int ID;
	string name;
	int grade;
};

bool cmp1(Stu s1, Stu s2)
{
	return s1.ID < s2.ID;
}

bool cmp2(Stu s1, Stu s2)
{
	if (s1.name != s2.name)
		return s1.name < s2.name;
	else
		return s1.ID < s2.ID;
}

bool cmp3(Stu s1, Stu s2)
{
	if (s1.grade != s2.grade)
		return s1.grade < s2.grade;
	else
		return s1.ID < s2.ID;
}

int main()
{
	int n, c;
	cin >> n >> c;
	vector<Stu> list;
	for (int i = 0; i < n; i++)
	{
		Stu tmp;
		cin >> tmp.ID >> tmp.name >> tmp.grade;
		list.push_back(tmp);
	}
	if (c == 1)
	{
		sort(list.begin(), list.end(), cmp1);
	}
	if (c == 2)
	{
		sort(list.begin(), list.end(), cmp2);
	}
	if (c == 3)
	{
		sort(list.begin(), list.end(), cmp3);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%06d ", list[i].ID);
		cout << list[i].name;
		printf(" %d\n", list[i].grade);
	}
	return 0;
}
