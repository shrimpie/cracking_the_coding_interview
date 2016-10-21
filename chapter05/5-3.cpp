// 5.3 Given an integer, print the next smallest and next largest number that 
//     have the same number of 1 bits in their binary representation.

// Solution:
// 
// 1. Brute force.

// 2. Number properties approach for next number

// Observations:
// >> If we "turn on " a 0, we need to "turn off" a 1
// >> If we turn on a 0 at bit i and turn off a 1 at bit j, the number changes 
//    by 2^i - 2^j.
// >> If we want to get a bigger number with the same number of 1s and 0s, i 
//    must be bigger than j.

// Solutions:
// 1. Traverse from right to left. Once we've passed a 1, turn on the next 0. 
//    We've now increased the number by 2^i. Yikes! Example: xxxxx011100 
//    becomes xxxxx111100.
// 2. Turn off the one that's just to the right side of that. We're now bigger
//    by 2^i - 2^(i-1). Example: xxxxx111100 becomes xxxxx101100.
// 3. Make the number as small as possible by rearranging all the 1s to be as 
//    far right as possible: Example: xxxxx101100 becomes xxxxx100011.
//

// To get the previous one, we do the reverse.
// ...


#include <iostream>

bool get_bit(int n, int index)
{
	return ((n & (1 << index)) > 0);
}

int set_bit(int n, int index)
{
	return (n | (1 << index));
}

int clear_bit(int n, int index)
{
	int mask = ~(1 << index);

	return (n & mask);
}

int get_next_biggest(int n)
{
	if (n <= 0) // We only care about positive numbers now.
		return -1; 

	int index = 0;
	int count_ones = 0;

	// Fine first '1'
	while(!get_bit(n, index))
		++index;

	// Turn on next '0'
	while(get_bit(n, index))
	{
		++index;
		++count_ones;
	}
	n = set_bit(n, index);

	// Turn off previous '1'
	n = clear_bit(n, --index);
	--count_ones;

	// Set 0s
	for(int i = index - 1; i >= count_ones; --i)
		n = clear_bit(n, i);

	// Set 1s
	for(int i = count_ones - 1; i >= 0; --i)
		n = set_bit(n, i);

	return n;
}

int main()
{
	int n = 0x1c;
	std::cout << n << std::endl;
	std::cout << std::bitset<8>(n) << std::endl;

	n = get_next_biggest(n);
	std::cout << n << std::endl;
	std::cout << std::bitset<8>(n) << std::endl;

	return 0;
}
















