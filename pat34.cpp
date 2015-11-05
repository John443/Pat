/*
One way that the police finds the head of a gang is to check people's phone calls. If there 
is a phone call between A and B, we say that A and B is related. The weight of a relation is 
defined to be the total time length of all the phone calls made between the two persons. A 
"Gang" is a cluster of more than 2 persons who are related to each other with total relation 
weight being greater than a given threshold K. In each gang, the one with maximum total weight 
is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive 
numbers N and K (both less than or equal to 1000), the number of phone calls and the weight 
threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the 
length of the call. A name is a string of three capital letters chosen from A-Z. A time 
length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, 
print in a line the name of the head and the total number of the members. It is guaranteed 
that the head is unique for each gang. The output must be sorted according to the alphabetical 
order of the names of the heads.
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, vector<string>> list;
map<string, int> weight;
map<string, int> visited;
map<string, int> gang;
int cnt;
int sum;
string head;

void DFS(string str)
{
	visited[str] = 1;
	cnt++;
	sum += weight[str];
	if (weight[head] < weight[str])
		head = str;
	else if (weight[head] == weight[str] && str < head)
		head = str;
	vector<string>::iterator it;
	for (it = list[str].begin(); it != list[str].end(); it++)
	{
		if (visited[*it] == 0)
			DFS(*it);
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string name1, name2;
		int time;
		cin >> name1 >> name2 >> time;
		list[name1].push_back(name2);
		list[name1].push_back(name1);
		visited[name1] = visited[name2] = 0;
		weight[name1] += time;
		weight[name2] += time;
	}
	map<string, int>::iterator it;
	for (it = visited.begin(); it != visited.end(); it++)
	{
		if (visited[it->first] == 0)
		{
			cnt = 0;
			sum = 0;
			head = it->first;
			DFS(head);
			if (cnt > 2 && sum / 2 > k)
				gang[head] = cnt;
		}
	}
	if(!gang.size())
		cout << gang.size() << endl;
	else
	{
		cout << gang.size() << endl;
		map<string, int>::iterator it;
		for (it = gang.begin(); it != gang.end(); it++)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}
