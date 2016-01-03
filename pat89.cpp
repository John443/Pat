/*
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output 
list. Each iteration, insertion sort removes one element from the input data, finds the location it 
belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element 
(a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce 
new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several 
iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N 
(<=100). Then in the next line, N integers are given as the initial sequence. The last line contains 
the partially sorted sequence of the N numbers. It is assumed that the target sequence is always 
ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the 
method used to obtain the partial result. Then run this method for one more iteration and output in 
the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. 
All the numbers in a line must be separated by a space, and there must be no extra space at the end 
of the line.
*/
#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;

int original[MAXN], target[MAXN], ans[MAXN];
int n;

bool IsEqual(int a[], int b[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void Output(int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << a[i];
		else
			cout << " " << a[i];
	}
}

bool Insert()
{
	for (int i = 2; i <= n; i++)
	{
		sort(ans, ans + i);
		if (IsEqual(ans, target))
		{
			sort(ans, ans + i + 1);
			cout << "Insertion Sort" << endl;
			Output(ans);
			return true;
		}
	}
	return false;
}

bool Merge()
{
	bool tag = false;
	int j;
	for (int i = 2; i <= n; i = i * 2)
	{
		for (j = 0; j + i <= n; j = j + i)
		{
			if (IsEqual(original, target))
				tag = true;
			sort(original + j, original + j + i);
		}
		sort(original + j, original + n);
		if (IsEqual(original, target))
			tag = true;
		if (tag && !IsEqual(original, target))
		{
			cout << "Merge Sort" << endl;
			Output(original);
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> original[i];
		ans[i] = original[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> target[i];
	}
	if (!Insert())
		Merge();
	return 0;
}
