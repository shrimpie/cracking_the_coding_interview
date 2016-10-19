// 9.1 You are given two sorted arrays, A and B, and A has a large enough 
//     buffer at the end to hold B. Write a method to merge B into A in 
//     sorted order.


// Idea:
// very straight-forward.

#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& a, vector<int> b, int n, int m)
{
	int k = m + n - 1; // Index of last location of array a
	int i = n - 1;     // Last element of a
	int j = m - 1;     // Last element of b

	// Start from the last and merge
	while(i >= 0 && j >= 0)
	{
		if(a[i] > b[j])
			a[k--] = a[i--];
		else
			a[k--] = b[j--];
	}
	while(j >= 0)
		a[k--] = b[j--];
}

void print_vector(vector<int>& arr, int size)
{
	cout << "The vector contains: ";
	for(int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	vector<int> a(20);
	vector<int> b(10);

	for(int i = 0; i < 10; ++i)
	{
		a[i] = 2 * i;
		b[i] = 2 * i + 1;
	}

	print_vector(a, 10);
	print_vector(b, 10);

	merge(a, b, 10, 10);

	print_vector(a, 20);


	return 0;
}