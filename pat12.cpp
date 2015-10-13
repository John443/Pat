/*
To evaluate the performance of our first year CS majored students, we consider their grades of 
three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), 
and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that 
is, among the four ranks with respect to the three courses and the average grade, we print the 
best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in 
C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one 
in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and 
M (<=2000), which are the total number of students, and the number of students who would check 
their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 
6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the 
order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the 
corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or 
more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Student
{
	int ID;
	int C;
	int M;
	int E;
	int A;
};

bool sortByA(Student A, Student B)
{
	return A.A > B.A;
}
bool sortByC(Student A, Student B)
{
	return A.C > B.C;
}
bool sortByM(Student A, Student B)
{
	return A.M > B.M;
}
bool sortByE(Student A, Student B)
{
	return A.E > B.E;
}

int main()
{
	Student stu;
	int n, m;
	vector<Student> list;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> stu.ID >> stu.C >> stu.M >> stu.E;
		stu.A = (stu.C + stu.M + stu.E) / 3;
		list.push_back(stu);
	}
	map<int, int> Rank;
	map<int, char> Type;
	sort(list.begin(), list.end(), sortByA);
	int rank = 0;
	int score = -1;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].A != score)
			rank = i + 1;
		score = list[i].A;
		Rank[list[i].ID] = rank;
		Type[list[i].ID] = 'A';
	}
	sort(list.begin(), list.end(), sortByC);
	rank = 0;
	score = -1;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].C != score)
			rank = i + 1;
		score = list[i].C;
		if (rank < Rank[list[i].ID])
		{
			Rank[list[i].ID] = rank;
			Type[list[i].ID] = 'C';
		}
	}
	sort(list.begin(), list.end(), sortByM);
	rank = 0;
	score = -1;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].M != score)
			rank = i + 1;
		score = list[i].M;
		if (rank < Rank[list[i].ID])
		{
			Rank[list[i].ID] = rank;
			Type[list[i].ID] = 'M';
		}
	}
	sort(list.begin(), list.end(), sortByE);
	rank = 0;
	score = -1;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].E != score)
			rank = i + 1;
		score = list[i].E;
		if (rank < Rank[list[i].ID])
		{
			Rank[list[i].ID] = rank;
			Type[list[i].ID] = 'E';
		}
	}
	vector<int> ID;
	int id;
	for (int i = 0; i < m; i++)
	{
		cin >> id;
		ID.push_back(id);
	}
	for (int i = 0; i < m; i++)
	{
		if (Rank.count(ID[i]))
		{
			cout << Rank[ID[i]] << " " << Type[ID[i]] << endl;
		}
		else
			cout << "N/A" << endl;
	}
	return 0;
}