// 19.7 You are given an array of integers (both positive and negative). Find 
//      the continuous sequence with the largest sum. Return the sum.
//      Example:
//      Input: [2, -8, 3, -2, 4, -10]
//      Output: 5 (i.e., [3, -2, 4])


// Idea:
// Keep track of current subsequence sum, if the sum becomes negative, then it 
// will not contribute to the subsequent maximum subsequence.

#include <iostream>

int get_max_sum(int a[], int size)
{
	int max_sum = 0;
	int sum = 0;
	for(int i=0; i < size; ++i)
	{
		sum += a[i];
		if(max_sum < sum)
			max_sum = sum;
		else if(sum < 0)
			sum = 0;
	}
	return max_sum;
}


int main()
{
	int test_arr[6] = { 2, -8, 3, -2, 4, -10 };

	std::cout << get_max_sum(test_arr, 6) << std::endl;



	return 0;
}