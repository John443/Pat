/*
Zhejiang University has 40000 students and provides 2500 courses. Now given the registered 
course list of each student, you are supposed to output the student name lists of all the 
courses.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: 
N (<=40000), the total number of students, and K (<=2500), the total number of courses. 
Then N lines follow, each contains a student's name (3 capital English letters plus a 
one-digit number), a positive number C (<=20) which is the number of courses that this 
student has registered, and then followed by C course numbers. For the sake of simplicity, 
the courses are numbered from 1 to K.

Output Specification:

For each test case, print the student name lists of all the courses in increasing order of 
the course numbers. For each course, first print in one line the course number and the number 
of registered students, separated by a space. Then output the students' names in alphabetical 
order. Each name occupies a line.
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

void ReHashs(int num, char name[])
{
	char d = num % 10 + '0';
	num /= 10;
	char c = num % 26 + 'A';
	num /= 26;
	char b = num % 26 + 'A';
	num /= 26;
	char a = num % 26 + 'A';
	name[0] = a;
	name[1] = b;
	name[2] = c;
	name[3] = d;
	name[4] = '\0';
}

int Hashs(char name[])
{
	int id = 0;
	for (int i = 0; i < 3; i++)
	{
		id *= 26;
		id += name[i] - 'A';
	}
	id *= 10;
	id += name[3] - '0';
	return id;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int>	list[2510];
	for (int i = 0; i < N; i++)
	{
		char name[5];
		int num;
		scanf("%s %d", name, &num);
		int id = Hashs(name);
		for (int j = 0; j < num; j++)
		{
			int course;
			scanf("%d", &course);
			list[course].push_back(id);
		}
	}
	for (int i = 1; i <= K; i++)
	{
		sort(list[i].begin(), list[i].end());
		printf("%d %d\n", i, list[i].size());
		for (int j = 0; j < list[i].size(); j++)
		{
			char name[5];
			ReHashs(list[i][j], name);
			printf("%s\n", name);
		}
	}
	return 0;
}