/*
This time you are asked to tell the difference between the lowest grade of all the male 
students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed 
by N lines of student information. Each line contains a student's name, gender, ID and grade, 
separated by a space, where name and ID are strings of no more than 10 characters with no 
space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. 
It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female 
student with the highest grade, and the second line gives that of the male student with the 
lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student 
is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.
*/
#include<iostream>
#include<string>
using namespace std;

struct Stu
{
	string name;
	string ID;
	int score;
};

int main()
{
	int n;
	cin >> n;
	Stu F, M;
	F.score = -1;
	M.score = 101;
	for (int i = 0; i < n; i++)
	{
		Stu tmp;
		char gender;
		cin >> tmp.name >> gender >> tmp.ID >> tmp.score;
		if (gender == 'F')
		{
			if (tmp.score > F.score)
			{
				F = tmp;
			}
		}
		else if (gender == 'M')
		{
			if (tmp.score < M.score)
			{
				M = tmp;
			}
		}
	}
	if (F.score == -1)
	{
		cout << "Absent" << endl;
		cout << M.name << " " << M.ID << endl;
		cout << "NA";
	}
	else if (M.score == 101)
	{
		cout << F.name << " " << F.ID << endl;
		cout << "Absent" << endl;
		cout << "NA";
	}
	else
	{
		cout << F.name << " " << F.ID << endl;
		cout << M.name << " " << M.ID << endl;
		cout << F.score - M.score;
	}
	return 0;
}