/*
Mice and Rice is the name of a programming contest in which each programmer must write a piece of 
code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much 
rice as possible in order to become a FatMouse.

First the playing order is randomly decided for NP programmers. Then every NG programmers are 
grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in 
this turn are ranked the same. Every NG winners are then grouped in the next match until a final 
winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer 
submits his/her code. Given the weights of all the mice and the initial playing order, you are 
supposed to output the ranks for the programmers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: 
NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. 
If there are less than NG mice at the end of the player's list, then all the mice left will be put 
into the last group. The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) 
where each Wi is the weight of the i-th mouse respectively. The third line gives the initial playing 
order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1). 
All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, 
and all the numbers must be separated by a space, with no extra space at the end of the line.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1005
using namespace std;

struct Mice
{
	int weight;
	int rank;
};

Mice m[MAX];

bool cmp(int l, int r)
{
	return m[l].weight > m[r].weight;
}

int main()
{
	int NG, NP;
	cin >> NP >> NG;
	vector<int> ans;
	for (int i = 0; i < NP; i++)
	{
		cin >> m[i].weight;
	}
	for (int i = 0; i < NP; i++)
	{
		int tmp;
		cin >> tmp;
		ans.push_back(tmp);
	}
	while (ans.size() > 1)
	{
		int group = ans.size() % NG == 0 ? ans.size() / NG : ans.size() / NG + 1;
		vector<int> temp;
		int start = 0;
		int end = start + NG;
		while (start < ans.size())
		{
			end = start + NG;
			if (end > ans.size())
				end = ans.size();
			sort(ans.begin() + start, ans.begin() + end, cmp);
			temp.push_back(ans[start]);
			for (int i = start + 1; i < end; i++)
				m[ans[i]].rank = group + 1;
			start = end;
		}
		ans = temp;
	}
	m[ans[0]].rank = 1;
	cout << m[0].rank;
	for (int i = 1; i < NP; i++)
	{
		cout << " " << m[i].rank;
	}
	return 0;
}