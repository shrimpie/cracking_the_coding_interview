// 16.5 Write a program to find whether a machine is big endian or little 
//      endian.

// Idea:
// Find the first byte of a integer.

#include <iostream>

int test_byte_order()
{
	short int word = 0x0001;
	char * byte = (char*) &word;

	return (byte[0] ? 1 : 0);
}

int main()
{
	std::cout << (test_byte_order() ? "Little " : "Big ") << "endian"
	          << std::endl;

	return 0;
}