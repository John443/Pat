/*
Suppose a bank has N windows open for service. There is a yellow line in front of the windows 
which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. 
Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will 
have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are 
two or more lines with the same length, the customer will always choose the window with the smallest 
number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which 
a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside 
the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, 
respectively. At 08:00 in the morning, customer1 is served at window1 while customer2 is served at 
window2. Customer3 will wait in front of window1 and customer4 will wait in front of window2. 
Customer5 will wait behind the yellow line.

At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems 
shorter now. Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally 
customer5 at 08:10.

Input

Each input file contains one test case. Each case starts with a line containing 4 positive 
integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow 
line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the 
time they can have their transactions done. The customers are numbered from 1 to K.

Output

For each of the Q customers, print in one line the time at which his/her transaction is finished, 
in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is 
closed everyday after 17:00, for those customers who cannot be served before 17:00, you must 
output "Sorry" instead.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct Customer
{
	int process;
	int leave;
};

string int2str(int n);

int main()
{
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<Customer> customer(k);
	for (int i = 0; i < k; i++)
	{
		cin >> customer[i].process;
		customer[i].leave = 0;
	}
	vector<queue<int>> line(n);
	vector<int> end(n, 0);
	for (int i = 0; i < k; i++)
	{
		if (i < n*m)
		{
			line[i%n].push(i);
			customer[i].leave = end[i%n] + customer[i].process;
			end[i%n] = customer[i].leave;
		}
		else
		{
			int temp;
			int min = 1000;
			for (int j = 0; j < n; j++)
			{
				int t = line[j].front();
				if (customer[t].leave < min)
				{
					min = customer[t].leave;
					temp = j;
				}
			}
			customer[i].leave = end[temp] + customer[i].process;
			end[temp] = customer[i].leave;
			line[temp].pop();
			line[temp].push(i);
		}
	}
	while(q--)
	{
		int x;
		cin >> x;
		x = x - 1;
		if ((customer[x].leave - customer[x].process) < 540)
		{
			int hour = customer[x].leave / 60 + 8;
			int minu = customer[x].leave % 60;
			cout << int2str(hour) << ":" << int2str(minu) << endl;
		}
		else
			cout << "Sorry" << endl;
	}
	return 0;
}

string int2str(int n)
{
	char t[20];
	int i = 0;
	string s;
	while (n)
	{
		t[i++] = n % 10 + '0';
		n /= 10;
	}
	t[i] = 0;
	while (i)
	{
		s += t[--i];
	}
	if (s.size() == 1)
	{
		s = "0" + s;
	}
	else if (s.size() == 0)
	{
		s = "00";
	}
	return s;
}
