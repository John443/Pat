/*
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 
2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange 
strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital 
English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', 
representing the 4th day in a week; the second common character is the 5th capital letter 'E', 
representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 
0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last 
two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, 
you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 
characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 
3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, 
"WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. 
It is guaranteed that the result is unique for each case.
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 65
using namespace std;

int main()
{
	int i, j;
	char day, hour;
	int minu;
	char s1[MAX], s2[MAX], s3[MAX], s4[MAX];
	cin >> s1 >> s2 >> s3 >> s4;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
		{
			day = s1[i];
			break;
		}
	}
	i++;
	for (; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i] && (s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' && s2[i] <= 'N'))
		{
			hour = s1[i];
			break;
		}
	}
	for (j = 0; s3[j] != '\0' && s4[j] != '\0'; j++)
	{
		if (s3[j] == s4[j] && (s3[j] >= 'a' && s3[j] <= 'z' || s3[j] >= 'A' && s3[j] <= 'Z'))
		{
			minu = j;
			break;
		}
	}
	switch (day)
	{
		case 'A':
			cout << "MON";
			break;
		case 'B':
			cout << "TUE";
			break;
		case 'C':
			cout << "WED";
			break;
		case 'D':
			cout << "THU";
			break;
		case 'E':
			cout << "FRI";
			break;
		case 'F':
			cout << "SAT";
			break;
		case 'G':
			cout << "SUN";
			break;
	}
	if (hour >= '0' && hour <= '9')
		cout << " 0" << hour;
	else
		cout << " " << hour - 'A' + 10;
	printf(":%02d\n", minu);
	return 0;
}