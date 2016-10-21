// 5.1 You are given two 32-bit numbers, N and M, and two bit positions, i and 
//     j. Write a method to set all bits between i and j in N eqaul to M (e.g.,
//     M becomes a substring of N located at i and starting at j).
//     Example:
//     Input: N = 100 0000 0000, M = 1 0101, i = 2, j = 6
//     Output: N = 100 0101 0100


// Solution

// 1. If you want to set a sequence of bits to some target bits, you have to first
//    clear the bit to 0s, and OR to the target bits.
// 2. If you want to clear some bits to 0s, you have to AND to a bunch of 0s.
// 3. You can set the mask in two steps:
//    a) First clear the bits from jth to the least significant bit (0th).
//    b) AND to 1s from the ith position to the least significant bit.
// 4. Once you get the mask, you are done.

#include <iostream>
#include <bitset>


int update_bits(int n, int m, int i, int j)
{
	int max = ~0; // All 1s

	// 1s through position j, then 0s
	int left = max - ((1 << (j+1)) - 1);

	// 1s after position i
	int right = ((1 << i) - 1);

	// 1s, with 0s between i and j
	int mask = left | right;

	// clear i through j, then put m in there
	return (n & mask) | (m << i);
}



int main()
{
	int n = 0x400;
	int m = 0x15;

	int tgt = update_bits(n, m, 2, 6);
	std::cout << std::bitset<11>(tgt) << std::endl;

	return 0;
}













