// 19.3 Write an algorithm which computes the number of trailing zeros in n 
//      factorial.

// Idea:
// Trailing zeros come from 2*5, and every 5 has definitely a 2 to pair with it
// So just count how many 5 will suffice.


#include <iostream>

using namespace std;

int num_of_zeros(int num)
{
	int count = 0;
	if(num < 0)
	{
		cout << "Factorial is not defined for negative numbers.\n";
		return 0;
	}
	for(int i = 5; num/i > 0; i *= 5)
	{
		count += num/i;
	}
	return count;
}

long long factorial(int n)
{
	if(n < 0)
	{
		cout << "Factorial is not defined for negative numbers.\n";
		return 0;
	}
	if( n < 2)
		return 1;

	long long res = 1;

	for(int i=2; i<=n; ++i)
		res *=i;

	return res;
}

// Factorial for large numbers
// the number is stored in an array in reverse order.
#define MAX_DIGIT_COUNT 500
// Helper 
int multiply(int x, int res[], int res_size)
{
	int carry = 0;
	// One by one multiply n with individual digits of res[]
	for(int i = 0; i < res_size; ++i)
	{
		int prod = res[i] * x + carry;
		res[i] = prod % 10; // Store last digit of 'prod' in res[]
		carry = prod / 10;  // Put rest in carry
	}

	// Put carry in res and increase result size
	while(carry)
	{
		res[res_size] = carry % 10;
		carry = carry / 10;
		++res_size;
	}

	return res_size;
}

void factorial_large(int n)
{
	int res[MAX_DIGIT_COUNT];
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n!= 1*2*3*...*n
	for(int x = 2; x <= n; ++x)
		res_size = multiply(x, res, res_size);
	
	cout << "Factorial of " << n << " is: ";
	for(int i = res_size-1; i >= 0; --i)
		cout << res[i];
	cout << endl;
}

int main()
{
	factorial_large(100);
	cout << num_of_zeros(100) << endl;

	return 0;
}





