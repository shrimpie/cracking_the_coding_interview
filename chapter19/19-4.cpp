// 19.4 Write a method which finds the maximum of two numbers. You should not 
//      use if-else or any other comparison operator.


// Idea:
// Reword this problem as follows:
// 1. if a > b, return a; else, return b.
// 2. if (a - b) is negative, return b; else, return a.
// 3. if (a - b) is negative, let k=1; else, let k=0. Return a - k*(a-b).
// 4. Let c = a - b. Let k = the most significant bit of c. Return a - k*c.

#include <iostream>


int get_max(int a, int b)
{
	int c = a - b;
	int k = (c >> 31) & 0x1;
	int max = a - k * c;
	return max;
}

int main()
{
	std::cout << get_max(3, 10) << std::endl;

	return 0;
}