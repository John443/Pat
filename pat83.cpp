/*
Given a list of N student records with name, ID and grade. You are supposed to sort the records with 
respect to the grade in non-increasing order, and output those student records of which the grades 
are in a given interval.

Input Specification:

Each input file contains one test case. Each case is given in the following format:

N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer 
in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. It is guaranteed that all 
the grades are distinct.

Output Specification:

For each test case you should output the student records of which the grades are in the given interval 
[grade1, grade2] and are in non-increasing order. Each student record occupies a line with the student's 
name and ID, separated by one space. If there is no student's grade in that interval, output "NONE" instead.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
	char name[15];
	char ID[15];
	int grade;
};

bool cmp(Stu s1, Stu s2)
{
	return s1.grade > s2.grade;
}

int main()
{
	int n;
	cin >> n;
	vector<Stu> list;
	for (int i = 0; i < n; i++)
	{
		Stu tmp;
		cin >> tmp.name >> tmp.ID >> tmp.grade;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end(), cmp);
	int a, b;
	bool tag = false;
	cin >> a >> b;
	vector<Stu>:: iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (it->grade >= a && it->grade <= b)
		{
			tag = true;
			printf("%s %s\n", it->name, it->ID);
		}
		else if (it->grade >= b)
			continue;
		else
			break;
	}
	if (!tag)
		cout << "NONE";
	return 0;
}
