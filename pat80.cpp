/*
It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications 
in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview 
grade GI. The final grade of an applicant is (GE + GI) / 2. The admission rules are:

The applicants are ranked according to their final grades, and will be admitted one by one from the 
top of the rank list.
If there is a tied final grade, the applicants will be ranked according to their national entrance 
exam grade GE. If still tied, their ranks must be the same.
Each applicant may have K choices and the admission will be done according to his/her choices: 
if according to the rank list, it is one's turn to be admitted; and if the quota of one's most 
preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices 
will be considered one by one in order. If one gets rejected by all of preferred schools, then this 
unfortunate applicant will be rejected.
If there is a tied rank, and if the corresponding applicants are applying to the same school, then 
that school must admit all the applicants with the same rank, even if its quota will be exceeded.

Input Specification:

Each input file contains one test case. Each case starts with a line containing three positive integers: 
N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; 
and K (<=5), the number of choices an applicant may have.

In the next line, separated by a space, there are M positive integers. The i-th integer is the 
quota of the i-th graduate school respectively.

Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the 
applicant's GE and GI, respectively. The next K integers represent the preferred schools. For the 
sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are 
numbered from 0 to N-1.

Output Specification:

For each test case you should output the admission results for all the graduate schools. The results 
of each school must occupy a line, which contains the applicants' numbers that school admits. The 
numbers must be in increasing order and be separated by a space. There must be no extra space at 
the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 105
using namespace std;

struct Stu
{
	int num;
	int GE;
	int GI;
	int choice[5];
};

bool cmp(Stu s1, Stu s2)
{
	if (s1.GE + s1.GI == s2.GE + s2.GI)
		return s1.GE > s2.GE;
	else
		return s1.GE + s1.GI > s2.GE + s2.GI;
}

int main()
{
	int n, m, k;
	int quota[MAX];
	int vacancy[MAX];
	Stu s[40005];
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> quota[i];
		vacancy[i] = quota[i];
	}
	vector<Stu> v;
	for (int i = 0; i < n; i++)
	{
		Stu tmp;
		tmp.num = i;
		cin >> tmp.GE >> tmp.GI;
		for (int j = 0; j < k; j++)
		{
			cin >> tmp.choice[j];
		}
		v.push_back(tmp);
		s[i] = tmp;
	}
	sort(v.begin(), v.end(), cmp);
	vector<int> admit[MAX];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int index = v[i].choice[j];
			if (vacancy[index] >= 1)
			{
				admit[index].push_back(v[i].num);
				vacancy[index]--;
				break;
			}
			else if (vacancy[index] == 0)
			{
				int t = admit[index].back();
				if (s[t].GE + s[t].GI == v[i].GE + v[i].GI && s[t].GE == v[i].GE)
				{
					admit[index].push_back(v[i].num);
					break;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		sort(admit[i].begin(), admit[i].end());
		if (admit[i].size() == 0)
			cout << endl;
		else
		{
			for (int j = 0; j < admit[i].size(); j++)
			{
				if (j == 0)
					cout << admit[i][j];
				else
					cout << " " << admit[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
