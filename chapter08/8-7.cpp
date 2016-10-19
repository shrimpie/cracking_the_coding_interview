// 8.7 Given an infinite number of quarters (25 cents), dimes (10 cents), 
//     nickels (5 cents), and pennies (1 cent), write code to calculate the 
//     number of ways of representing n cents.

// Idea:
// This is a recursive problem, so let's figure out how to do make_change(n),
// using prior solutions (i.e., sub-problems). Let's say n = 100, so we want to
// compute the number of ways of making change of 100 cents. What's the 
// relationship to its sub-problems?

// We know that make_change(100):
// = make_change(100 using 0 quarters) + make_change(100 using 1 quarter) + 
// make_change(100 using 2 quarters) + make_change(100 using 3 quarters) + 
// make_change(100 using 4 quarters)

// Can we reduce this futher? Yes!
// = make_change(100 using 0 quarters) + make_change(75 using 0 quarter) + 
// make_change(50 using 0 quarter) + make_change(25 using 0 quarter) + 1

// Now what? We've used up all our quarters, so now we can start applying our 
// next biggest denomination: dimes.

// This leads to a recursive algorithm that looks like this:

#include <iostream>

int make_change(int n, int denom)
{
	int next_denom = 0;
	switch(denom)
	{
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1;
	}

	int ways = 0;
	for(int i = 0; i * denom <= n; ++i)
		ways += make_change(n - i * denom, next_denom);
	return ways;
}


int main()
{
	std::cout << make_change(100, 25) << std::endl;

	return 0;
}






