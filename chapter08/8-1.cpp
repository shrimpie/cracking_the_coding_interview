// 8.1 Write a method to generate the nth Fibonacci number.

// Idea:
// Very straight-forward, you can do it iteratively, or recursively.

#include <iostream>

// recursively
// For large number n, this algorithm could get really slow, so don't use it.
int fibo_r(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else if(n > 1)
		return fibo_r(n-1) + fibo_r(n-2);
	else
		return -1;
}

// iteratively

int fibo_i(int n)
{
	if(n < 0)
		return -1;
	if(n == 0)
		return 0;
	int a = 1, b = 1;
	for(int i = 3; i <= n; ++i)
	{
		int c = a + b;
		a = b;
		b = c;
	}

	return b;
}

int main()
{
	int n = 40;
	std::cout << fibo_r(n) << std::endl;
	std::cout << fibo_i(n) << std::endl;

	return 0;
}










