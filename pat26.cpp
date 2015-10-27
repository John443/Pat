/*
A table tennis club has N tables available to the public. The tables are numbered from 1 to 
N. For any pair of players, if there are some tables open when they arrive, they will be 
assigned to the available table with the smallest number. If all the tables are occupied, 
they will have to wait in a queue. It is assumed that every pair of players can play for at 
most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number 
of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables 
for their VIP members. When a VIP table is open, the first VIP pair in the queue will have 
the priviledge to take it. However, if there is no VIP in the queue, the next pair of 
players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP 
table is available, they can be assigned as any ordinary players.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer 
N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 
times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a 
pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed 
that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is 
assumed that no two customers arrives at the same time. Following the players' info, there 
are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP 
tables. The last line contains M table numbers.

Output Specification:

For each test case, first print the arriving time, serving time and the waiting time for 
each pair of players in the format shown by the sample. Then print in a line the number of 
players served by each table. Notice that the output must be listed in chronological order 
of the serving time. The waiting time must be rounded up to an integer minute(s). If one 
cannot get a table before the closing time, their information must NOT be printed.
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

struct Player
{
	int arrive;
	int vip;
	int play;
};

struct Table
{
	int ID;
	int vip;
	int num;
	int free;
};

bool cmpP(Player p1, Player p2)
{
	return p1.arrive < p2.arrive;
}

bool cmpT(Table t1, Table t2)
{
	if (t1.free != t2.free)
		return t1.free < t2.free;
	else
		return t1.ID < t2.ID;
}

bool cmp(Table t1, Table t2)
{
	return t1.ID < t2.ID;
}

void Output(int timer, int arrive)
{
	cout << setfill('0') << setw(2) << arrive / 3600 << ":";
	cout << setfill('0') << setw(2) << (arrive % 3600) / 60 << ":";
	cout << setfill('0') << setw(2) << arrive % 60 << " ";
	cout << setfill('0') << setw(2) << timer / 3600 << ":";
	cout << setfill('0') << setw(2) << (timer % 3600) / 60 << ":";
	cout << setfill('0') << setw(2) << timer % 60 << " ";
	cout << (timer - arrive + 30) / 60 << endl;
}

int main()
{
	vector<Player> p;
	vector<Player> wait;
	Table t[105];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Player tmp;
		int h, m, s;
		char c[2];
		cin >> h >> c[0] >> m >> c[1] >> s >> tmp.play >> tmp.vip;
		tmp.arrive = h * 3600 + m * 60 + s;
		if (tmp.play > 120)
			tmp.play = 120;
		tmp.play *= 60;
		if (tmp.arrive >= 21 * 3600 || tmp.arrive < 8 * 3600)
			continue;
		p.push_back(tmp);
	}
	int k, m;
	cin >> k >> m;
	for (int i = 1; i <= k; i++)
	{
		t[i].ID = i;
		t[i].vip = 0;
		t[i].num = 0;
		t[i].free = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int tag;
		cin >> tag;
		t[tag].vip = 1;
	}
	sort(p.begin(), p.end(), cmpP);
	sort(t + 1, t + 1 + k, cmpT);
	int timer = 0;
	int cur = 0;
	while (timer < 21 * 3600)
	{
		for (; cur < p.size(); cur++)
		{
			if (p[cur].arrive <= timer)
				wait.push_back(p[cur]);
			else
				break;
		}
		if (!wait.size())
		{
			if (cur < p.size())
			{
				timer = p[cur].arrive;
				for (int i = 1; i <= k; i++)
				{
					if (t[i].free < timer)
						t[i].free = timer;
				}
				wait.push_back(p[cur++]);
			}
			else
				break;
		}
		vector<Player>::iterator it;
		for (it = wait.begin(); it != wait.end(); it++)
			if (it->vip)
				break;
		int vipplayer = 0;
		if (it != wait.end())
			vipplayer = 1;
		int viptable = -1;
		for (int i = 1; i <= k; i++)
		{
			if (t[i].free == timer)
			{
				if (t[i].vip)
				{
					viptable = i;
					break;
				}
			}
		}
		if (vipplayer && viptable >= 1)
		{
			int arrive = it->arrive;
			Output(timer, arrive);
			t[viptable].free = timer + it->play;
			t[viptable].num++;
			wait.erase(it);
		}
		else
		{
			int arrive = wait[0].arrive;
			Output(timer, arrive);
			t[1].free = timer + wait[0].play;
			t[1].num++;
			wait.erase(wait.begin());
		}
		sort(t + 1, t + 1 + k, cmpT);
		timer = t[1].free;
	}
	sort(t + 1, t + 1 + k, cmp);
	for (int i = 1; i <= k; i++)
	{
		if (i == k)
			cout << t[k].num;
		else
			cout << t[i].num << " ";
	}
	return 0;
}
