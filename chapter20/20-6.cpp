// 20.6 Describe an algorithm to find the largest 1 million numbers in 1 
//      billion numbers. Assume that the computer memory can hold all one
//      billion numbers.

// Idea: mini-heap

// The solution from the book

// Approach 1: sorting, O(NlogN), N = one billion

// Approach 2: Min Heap, O(NlogM), M = one million

// Approach 3: Selection Rank Algorithm (if you can modify the original array)
// Intro: Selection Rank is a well known algorithm in computer science to find
//        the ith smallest (or largest) element in an array in expected linear
//        time. The basic algorithm for finding the ith smallest elements goes
//        like this:
//        >> Pick a random element in the array and use it as a 'pivot'. Move
//           all elements smaller than that element to one side of the array, 
//           and all elements larger to the other side.
//        >> If there are exactly i elements on the right, then you just find 
//           the largest element on that side.
//        >> Otherwise, if the right side is bigger than i, repeat the 
//           algorithm on the right. If the right side is smaller than i, 
//           repeat the algorithm on the left for i - right.size().
// Given this algorithm, you can either:
// >> Tweak it to use the existing partitions to find the largest i elements 
//    (where i = one million).
// >> Or, once you find the ith largest element, run through the array again 
//    to return all elements greater than or equal to it.

// This algorithm has expected O(n) time.
//

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> arr)
{
	cout << endl;
	for(int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

// First one
vector<int>* find_largest_n_elements_sort(vector<int> arr, int m)
{
	vector<int>* largest_n = new vector<int>();

	sort(arr.begin(), arr.end());

	for(vector<int>::iterator i = arr.end() - m; i != arr.end(); ++i)
		largest_n->push_back(*i);

	return largest_n;
}


// Second

class MiniHeap
{
	vector<int> mini_heap;
	int heap_size;

public:

	MiniHeap(vector<int> arr, int n)
	{
		heap_size = n;

		for(int i = 0; i < n; ++i)
			mini_heap.push_back(arr[i]);

		// print("After copy from arr");
		build_mini_heap();
	}

	int push_heap(int value)
	{
		int top = mini_heap[0];

		if(value > top)
		{
			mini_heap[0] = value;
			mini_heapify(mini_heap, 0, heap_size);
			return top;
		}
		return value;
	}

	void build_mini_heap()
	{
		for(int i = heap_size/2 - 1; i >= 0; --i)
			mini_heapify(mini_heap, i, heap_size);
	}

	void mini_heapify(vector<int>& a, int i, int n)
	{
		int j = 2 * i + 1;
		int temp = a[i];

		while(j < n)
		{
			if(j < n - 1 && a[j+1] < a[j])
				++j;
			if(temp < a[j])
				break;
			else
			{
				a[(j-1)/2] = a[j];
				j = j * 2 + 1;
			}
		}
		a[(j-1)/2] = temp;
	}

	void print(string msg)
	{
		cout << msg << ", the heap contains: ";
		for(int i = 0; i < heap_size; ++i)
			cout << mini_heap[i] << " ";
		cout << endl;
	}

	vector<int>* copy()
	{
		vector<int>* to = new vector<int>();
		for(int i = 0; i < heap_size; ++i)
			to->push_back(mini_heap[i]);
		return to;
	}

};

vector<int>* find_largest_n_elements_mini_heap(vector<int> arr, int m)
{
	MiniHeap mh(arr, m);

	for(int i = m; i < arr.size(); ++i)
		mh.push_heap(arr[i]);

	vector<int>* largest_m = mh.copy();
	return largest_m;
}



int main()
{
	vector<int> arr;

	int arr_size = 10000000;
	int find_size = 100;

	srand(time(NULL));
	for(int i = 0; i < arr_size; ++i)
		arr.push_back(rand() % arr_size);

	vector<int> * largest_m = find_largest_n_elements_sort(arr, find_size);

	for(int i = 0; i < find_size; ++i)
		cout << (*largest_m)[i] << " ";
	cout << endl;
	delete largest_m;

	largest_m = find_largest_n_elements_mini_heap(arr, find_size);
	sort(largest_m->begin(), largest_m->end());

	cout << "-----------------------\n";
	for(int i = 0; i < find_size; ++i)
		cout << (*largest_m)[i] << " ";
	cout << endl;

	delete largest_m;

	return 0;
}





















