/*
Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling 
techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate 
with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling 
machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a 
given number of times. It is assumed that the initial status of a card deck is in the following 
order:

S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for 
"Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the 
i-th position is j, it means to move the card from position i to position j. For example, 
suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, 
the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result 
will be: C1, H5, S3, J2, D13.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive 
integer K (<= 20) which is the number of repeat times. Then the next line contains the given 
order. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the shuffling results in one line. All the cards are separated by 
a space, and there must be no extra space at the end of the line.
*/
#include<iostream>
using namespace std;

int main()
{
	int K;
	cin >> K;
	int card[55];
	int temp[55];
	int index[55];
	for (int i = 1; i < 55; i++)
	{
		cin >> index[i];
		card[i] = i;
	}
	while (K--)
	{
		for (int i = 1; i < 55; i++)
		{
			temp[index[i]] = card[i];
		}
		for (int i = 1; i < 55; i++)
		{
			card[i] = temp[i];
		}
	}
	for (int i = 1; i < 55; i++)
	{
		int tag = card[i] - 1;
		if (i > 1)
			cout << " ";
		switch (tag / 13)
		{
			case 0:
				cout << "S" << tag % 13 + 1;
				break;
			case 1:
				cout << "H" << tag % 13 + 1;
				break;
			case 2:
				cout << "C" << tag % 13 + 1;
				break;
			case 3:
				cout << "D" << tag % 13 + 1;
				break;
			case 4:
				if (card[i] % 13 == 1)
					cout << "J1";
				else
					cout << "J2";
				break;
		}
	}
	return 0;
}