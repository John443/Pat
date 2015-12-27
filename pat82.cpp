/*
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese 
way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san 
Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according 
to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated 
by a space and there must be no extra space at the end of the line.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string d[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string m[] = {"0", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};

int main()
{
	int n;
	cin >> n;
	vector<string> ans;
	vector<int> num;
	if (n == 0)
	{
		cout << "ling" << endl;
		return 0;
	}
	else if (n < 0)
	{
		cout << "Fu ";
		n = -n;
	}
	while (n)
	{
		num.push_back(n % 10);
		n /= 10;
	}
	int e = 0;
	while (e < num.size() && num[e] == 0)
	{
		e++;
	}
	if (e == 8)
	{
		cout << d[num[e]] << " Yi";
	}
	for (int i = e; i < num.size(); i++)
	{
		if (i != 0 && (num[i] != 0 || i == 4 || i == 8))
		{
			ans.push_back(m[i]);
		}
		ans.push_back(d[num[i]]);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		if (i != ans.size() - 1)
			cout << " ";
		int cnt = 0;
		while (i >= 0 && ans[i] == "ling")
		{
			--i;
			++cnt;
		}
		if (cnt != 0 && ans[i] != "Wan")
			cout << "ling ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
