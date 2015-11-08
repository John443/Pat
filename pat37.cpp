/*
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed 
on it, meaning that when you use this coupon with a product, you may get N times the value of 
that product back! What is more, the shop also offers some bonus product for free. However, 
if you apply a coupon with a positive N to this bonus product, you will have to pay the shop 
N times the value of the bonus product... but hey, magically, they have some coupons with 
negative N's!

For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} 
(in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply 
coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 
2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply 
coupon 3 to product 4, you will have to pay M$12 to the shop.

Each coupon and each product may be selected at most once. Your task is to get as much money 
back as possible.

Input Specification:

Each input file contains one test case. For each case, the first line contains the number of 
coupons NC, followed by a line with NC coupon integers. Then the next line contains the number 
of products NP, followed by a line with NP product values. Here 1<= NC, NP <= 105, and it is 
guaranteed that all the numbers will not exceed 230.

Output Specification:

For each test case, simply print in a line the maximum amount of money you can get back.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	int NC, NP;
	vector<int> P_NC;
	vector<int> N_NC;
	vector<int> P_NP;
	vector<int> N_NP;
	cin >> NC;
	for (int i = 0; i < NC; i++)
	{
		int k;
		cin >> k;
		if (k > 0)
			P_NC.push_back(k);
		else if (k < 0)
			N_NC.push_back(k);
	}
	cin >> NP;
	for (int i = 0; i < NP; i++)
	{
		int k;
		cin >> k;
		if (k > 0)
			P_NP.push_back(k);
		else if (k < 0)
			N_NP.push_back(k);
	}
	sort(P_NC.begin(), P_NC.end(), greater<int>());
	sort(P_NP.begin(), P_NP.end(), greater<int>());
	sort(N_NC.begin(), N_NC.end());
	sort(N_NP.begin(), N_NP.end());
	long long max = 0;
	int i = 0;
	int j = 0;
	while (i < P_NC.size() && j < P_NP.size())
	{
		max += P_NC[i] * P_NP[j];
		i++;
		j++;
	}
	i = j = 0;
	while (i < N_NC.size() && j < N_NP.size())
	{
		max += N_NC[i] * N_NP[j];
		i++;
		j++;
	}
	cout << max << endl;
	return 0;
}