// 5.7 An array A[1..n] contains all the integers from 0 to n except for one 
//     number which is missing. In this problem, we cannot access an entire 
//     integer in A with a single operation. The elements of A are represented
//     in binary, and the only operation we can use to access them is "fetch 
//     the jth bit of A[i]", which takes constant time. Write code to find the 
//     missing integer. Can you do it in O(n) time?

// Solution:
// 1. Just look at the least significant bits (LSB), if the LSB of the missing 
//    number is a 0, then count(1) >= 0; if it's 1, then count(1) < count(0).
//    From this information, you can determine the LSB of the missing number.
// 2. Repeat for other bits, but each time eliminate the numbers that have 
//    different LSBs of the missing number.


#include <iostream>
#include <vector>
#include <bitset>

#define WIDTH 8


int find_missing(std::vector<std::bitset<WIDTH> >* input, int col)
{
	if(col == WIDTH) // base case
		return 0;

	std::vector<std::bitset<WIDTH> >* odd_indices = 
		new std::vector<std::bitset<WIDTH> >();

	std::vector<std::bitset<WIDTH> >* even_indices = 
		new std::vector<std::bitset<WIDTH> >();

	for(auto bs : *input)
	{
		if(bs[col] == 0)
			even_indices->push_back(bs);
		else
			odd_indices->push_back(bs);
	}

	if(odd_indices->size() >= even_indices->size())
		return (find_missing(even_indices, col+1)) << 1 | 0;
	else
		return (find_missing(odd_indices, col+1)) << 1 | 1;
}


int find_missing(std::vector<std::bitset<WIDTH> >* array)
{
	return find_missing(array, 0);
}




int main()
{
	srand(time(NULL));


	int secret = rand() % (1 << WIDTH);

	std::vector<std::bitset<WIDTH> >* array = 
		new std::vector<std::bitset<WIDTH> >();

	for(int i = 0; i < (1 << WIDTH); ++i)
	{
		if(i != secret)
			array->push_back(std::bitset<WIDTH>(i));
	}

	std::cout << "Secret number in binary format: " << std::bitset<WIDTH>(secret)
	          << std::endl;

	int found = find_missing(array);
	std::cout << "Secret number you found: " << std::bitset<WIDTH>(found)
	          << std::endl;

	return 0;
}















