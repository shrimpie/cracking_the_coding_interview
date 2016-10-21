// 5.6 Write a program to swap odd and even bits in an integer with as few 
//     instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and 
//     bit 3 are swapped, etc).


// Solution:

// Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them 
// left to put them in the even bits. Then, perform a similar operation for 
// even bits. This takes a total of 5 instructions.


#include <iostream>
#include <bitset>

int swap_odd_even_bits(int x)
{
	return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); 
}

int main()
{
	int x = 0xaaaaaaaa;
	std::cout << std::bitset<32>(x) << std::endl;
	x = swap_odd_even_bits(x);
	std::cout << std::bitset<32>(x) << std::endl;

	return 0;
}
