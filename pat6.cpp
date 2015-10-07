/*
At the beginning of every day, the first person who signs in the computer room will unlock the door, 
and the last one who signs out will lock the door. Given the records of signing in's and out's, 
you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts 
with a positive integer M, which is the total number of records, followed by M lines, each in the 
format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, 
and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked 
the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier 
than the sign out time for each person, and there are no two persons sign in or out at 
the same moment.
*/
#include<iostream>
#include<Windows.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Person
{
	string in;
	string out;
	string id_num;
};

bool cmp1(Person a, Person b)
{
	return a.in < b.in;
}
bool cmp2(Person a, Person b)
{
	return a.out > b.out;
}

int main()
{
	vector<Person> day;
	int n;
	while (cin >> n)
	{
		Person temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp.id_num >> temp.in >> temp.out;
			day.push_back(temp);
		}
		sort(day.begin(), day.end(), cmp1);
		cout << day[0].id_num << " ";
		sort(day.begin(), day.end(), cmp2);
		cout << day[0].id_num << endl;
	}
	system("pause");
	return 0;
}