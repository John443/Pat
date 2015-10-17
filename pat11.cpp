/*
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited 
as the best players from the best teams doing battles for the World Cup trophy in South Africa. 
Similarly, football betting fans were putting their money where their mouths were, by laying all 
 of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: 
first select any three of the games. Then for each selected game, bet on one of the three possible 
results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. 
The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for 
the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 
= 37.98 yuans (accurate up to 2 decimal places).

Input

Each input file contains one test case. Each case contains the betting information of 3 games. 
Each game occupies a line with three distinct odds corresponding to W, T and L.

Output

For each test case, print in one line the best bet of each game, and the maximum profit accurate 
up to 2 decimal places. The characters and the number must be separated by one space.
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double odds[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> odds[i][j];
	}
	int ans[3];
	double mult = 1;
	double max[3];
	for (int i = 0; i < 3; i++)
	{
		max[i] = odds[i][0];
		ans[i] = 0;
		for (int j = 0; j < 3; j++)
		{
			if (max[i] < odds[i][j])
			{
				max[i] = odds[i][j];
				ans[i] = j;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		mult *= max[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (ans[i] == 0)
			cout << "W" << " ";
		if (ans[i] == 1)
			cout << "T" << " ";
		if (ans[i] == 2)
			cout << "L" << " ";
	}
	double money = (mult * 0.65 - 1) * 2;
	cout.setf(ios_base::fixed);
	cout <<  setprecision(2) << money << endl;
	return 0;
}