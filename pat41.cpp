/*
Being unique is so important to people on Mars that even their lottery is designed in a unique 
way. The rule of winning is simple: one bets on a number chosen from [1, 104]. The first one 
who bets on a unique number wins. For example, if there are 7 people betting on 
5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:

Each input file contains one test case. Each case contains a line which begins with a 
positive integer N (<=105) and then followed by N bets. The numbers are separated by a space.

Output Specification:

For each test case, print the winning number in a line. If there is no winner, print "None" 
instead.
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	int num[100005];
	int times[100005];
	for (int i = 0; i < 10005; i++)
		num[i] = times[i] = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		times[num[i]]++;
	}
	bool tag = false;
	int result;
	for (int i = 0; i < N; i++)
	{
		if (times[num[i]] == 1)
		{
			tag = true;
			result = num[i];
			break;
		}
	}
	if (tag)
		cout << result << endl;
	else
		cout << "None" << endl;
	return 0;
}