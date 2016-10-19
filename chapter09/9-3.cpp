// 9.3 Given a sorted array of n integers that has been rotated an unknown 
//     number of times, give an O(logn) algorithm that finds an element in the
//     array. You may assume that the array was orignally sorted in increasing 
//     order.
//     Example:
//     Input: find 5 in array (15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14)
//     Output: 8 (the index of 5 in the array)

// Idea:
// Modified binary search

// Note this algorithm does not give you correct results for array with many 
// duplicates. You might want to do a linear search if that's the case.

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> a, int l, int u, int x)
{
	while(l <= u)
	{
		int m = (l + u) / 2;
		if(x == a[m])
			return m;
		else if(a[l] <= a[m])
		{
			if(x > a[m])
				l = m + 1;
			else if(x >= a[l])
				u = m - 1;
			else
				l = m + 1;
		}
		else if (x < a[m])
			u = m - 1;
		else if(x <= a[u])
			l = m + 1;
		else
			u = m - 1;
	}
	return -1;
}

int main()
{
	int a[] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	int b[] = { 2,2,2,2, 2,2,2,2, 3,2,2,2, 2,2,2,2, 2,2,2 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));

	cout << search(va, 0, va.size() - 1, 5) << endl;
	// It won't find the 3.
	cout << search(vb, 0, vb.size() - 1, 3) << endl;
	return 0;
}






