// 20.1 Write a function that adds two numbers. You should not use + or any 
//      arithmetic operators.

// Idea: 
// To investigate this problem, let's start off by gaining a deeper 
// understanding of how we add numbers. 
// In binary:
// 1. If I add two binary numbers together but forget to carry, bit[i] will be 
//    0 if bit[i] in a and b are both 0 or both 1. This is an XOR.
// 2. If I add two numbers together, but only carry, I will have a 1 in bit[i] 
//    if bit[i-1] in a and b are both 1's. This is an AND, shifted.
// 3. Now, recurse until there is nothing to carry.

// Observations and suggestions: (very important)
// The approach: there are a couple of suggestions for figuring out this 
// problem:
// 1. Our first instinct in problems like these should be that we're going to
//    have to work with bits. Why? Because when you take away the + sign, what
//    other choice do we have? Plus, that's how computers do it.
// 2. Our next thought in problems like these should be to really, really 
//    understand how you add. Walk through an addition problem to see if you 
//    can understand something new - some pattern - and then see if you can 
//    replicate that with code.

#include <iostream>

int add_no_arithm(int a, int b)
{
	if(b == 0) return a;
	int sum = a ^ b; // Add without carrying
	int carry = (a & b) << 1; // Carry, but don't add
	return add_no_arithm(sum, carry);
}


int main()
{
	std::cout << "Sum of 2468 and 8392 is " << add_no_arithm(2468, 8392) 
	          << std::endl;
	          
	return 0;
}