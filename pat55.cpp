/*
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the 
world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the 
people in a certain range of ages. That is, given the net worths of N people, you must find the M 
richest people in a given range of their ages.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: 
N (<=105) - the total number of people, and K (<=103) - the number of queries. Then N lines follow, 
each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), 
and the net worth (integer in [-106, 106]) of a person. Finally there are K lines of queries, each 
contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] 
which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:

For each query, first print in a line "Case #X:" where X is the query number starting from 1. 
Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information 
occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it 
must be in non-decreasing order of the ages. If both worths and ages are the same, then the output 
must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two 
persons share all the same of the three pieces of information. In case no one is found, output 
"None".
*/
#include<iostream>
#include<algorithm>
#include<string>
#define MAX 100005
using namespace std;

struct Richer
{
	string name;
	int age;
	int wealth;
};

int Agecount[105];
int Sort[MAX];

bool cmp(Richer r1, Richer r2)
{
	if (r1.wealth != r2.wealth)
		return r1.wealth > r2.wealth;
	else if (r1.age != r2.age)
		return r1.age < r2.age;
	else
		return r1.name < r2.name;
}

int main()
{
	int N, K;
	cin >> N >> K;
	Richer r[MAX];
	for (int i = 0; i < N; i++)
	{
		cin >> r[i].name >> r[i].age >> r[i].wealth;
	}
	sort(r, r + N, cmp);
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		Agecount[r[i].age]++;
		if (Agecount[r[i].age] < 101)
			Sort[t++] = i;
	}
	for (int i = 1; i <= K; i++)
	{
		int m, Amin, Amax;
		int num = 0;
		cout << "Case #" << i << ":" << endl;
		cin >> m >> Amin >> Amax;
		for (int j = 0; j < t && num < m; j++)
		{
			int age = r[Sort[j]].age;
			if (age >= Amin && age <= Amax)
			{
				cout << r[Sort[j]].name << " " << r[Sort[j]].age << " " << r[Sort[j]].wealth << endl;
				num++;
			}
		}
		if (num == 0)
			cout << "None" << endl;
	}
	return 0;
}