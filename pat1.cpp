#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string int2str(long n);
int main()
{
	long a, b;
	cin >> a >> b;
	long sum = a + b;
	if (sum > 0)
	{
		string s = int2str(sum);
		cout << s;
	}
	else if (sum == 0)
	{
		cout << 0;
	}
	else
	{
		sum = -sum;
		string s = int2str(sum);
		cout << "-" << s;
	}
	return 0;
}
string int2str(long n)
{
	char t[24];
	int i = 0;
	string str = "";
	while (n)
	{
		t[i++] = (n % 10) + '0';
		n /= 10;
	}
	t[i] = 0;
	while (i)
	{
		str += t[--i];
		if (i % 3 == 0 && i != 0)
			str += ",";
	}
	return str;
}