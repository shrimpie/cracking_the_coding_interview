// 19.11 Design an algorithm to find all pairs of integers within an array 
//       which sum to a specified value.


// Idea: How about sort it and find the pair from both ends to the middle?
// Exactly.


#include <iostream>
#include <vector>


void print_pair_sums(std::vector<int> arr, int sum)
{
	// Sort it first.
	std::sort(arr.begin(), arr.end());

	int first = 0;
	int last = arr.size() - 1;

	while(first < last)
	{
		int s = arr[first] + arr[last];
		if( == sum)
		{
			std::cout << "Found a pair: " << arr[first] << " and " << arr[last]
			          << std::endl;
			++first;
			--last;
		}
		else if(s < sum)
			++first;
		else
			--last;
	}
}


int main()
{
	std::vector<int> arr;
	for(int i=0; i < 100; ++i)
		arr.push_back(rand() % 100);
	print_pair_sums(arr, 59);

	return 0;
}