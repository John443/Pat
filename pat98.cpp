/*
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output 
list. Each iteration, insertion sort removes one element from the input data, finds the location it 
belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the 
unsorted region by extracting the largest element and moving that to the sorted region. it involves 
the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several 
iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer 
N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains 
the partially sorted sequence of the N numbers. It is assumed that the target sequence is always 
ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the 
method used to obtain the partial result. Then run this method for one more iteration and output 
in the second line the resuling sequence. It is guaranteed that the answer is unique for each test 
case. All the numbers in a line must be separated by a space, and there must be no extra space at 
the end of the line.
*/
#include <iostream>
#include <algorithm>
#include <functional>
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

bool HeapSort()
{
	bool tag = false;
	for (int i = n; i >= 2; i--)
	{
		if (tag && !IsEqual(original, target))
		{
			cout << "Heap Sort" << endl;
			Output(original);
			return true;
		}
		make_heap(original, original + i);
		pop_heap(original, original + i);
		if (IsEqual(original, target))
		{
			tag = true;
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
		HeapSort();
	return 0;
}
