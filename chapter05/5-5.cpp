// 5.5 Write a function to determine the number of bits required to convert
//     integer A to integer B.
//     Input: 31, 14
//     Output: 2


// Solution:

// This seemingly complex problem is actually rather straightforward. To 
// approach this, ask yourself how you would figure out which bits in two 
// numbers are different. Simple: with an xor.

// Each 1 in the xor will represent one different bit between A and B. We then 
// simply need to count the number of bit than are 1.

#include <iostream>


int bit_swap_required(int a, int b)
{
	int count = 0;

	for(int c = a ^ b; c != 0; c >>= 1)
		count += c & 1;

	return count;
}


int main()
{
	int a = 31, b = 14;

	std::cout << bit_swap_required(a, b) << std::endl;

	return 0;
}