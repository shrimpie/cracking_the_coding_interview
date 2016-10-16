// 19.1 Write a function to swap a number in place without temporary variables.

// This is a classic interview question. If you haven't heard this problem 
// before, you can approach it by taking the difference between a and b:

#include <iostream>


void swap(int a, int b)
{
	a = b - a;
	b = b - a;
	a = a + b;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
}

// or you can then optimize it as follows:
void swap_opt(int a, int b)
{
	a = a^b;
	b = a^b;
	a = a^b;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
}


int main()
{
	swap(1, 2);
	swap_opt(1,2);

	return 0;
}