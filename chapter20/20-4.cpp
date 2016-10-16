// 20.4 Write a method to count the number of 2s between 0 and n.

// Idea: find the pattern.
// 
// Recursive:
// 1. Define f(n) to be the number of 2s between 0 and n, then

//    For example: f(513) = 5 * f(99) + f(13) + 100
//    >> last two digits repeated 5 times, as add 5 * f(99)
//    >> last two digits in 500 -> 513, so add f(13)
//    >> first digit being 2 between 200 -> 299, so add 100

//    For example: f(279) = 2 * f(99) + f(79) + 79 + 1
//    >> last two digits repeated 2 times, as add 2 * f(99)
//    >> last two digits in 200 -> 279, so add f(79)
//    >> first digit being 2 between 200 -> 279, so add 79 + 1

// Recursive code

#include <iostream>

int count_twos_recursive(int n)
{
	// Base case
	if(n == 0)
		return 0;

	int power = 1;
	while(10 * power < n)
		power *= 10;
	int first = n / power;
	int remain = n % power;

	// Count 2s from first digit
	int num_twos_first = 0;
	if(first > 2)
		num_twos_first += power;
	else if(first == 2)
		num_twos_first += remain + 1;

	// Count 2s from all other digits
	int num_twos_other = first * count_twos_recursive(power - 1) + 
                                 count_twos_recursive(remain);

    return num_twos_first + num_twos_other;
}


// Iterative

// Idea:
// There is also a pattern:
// 1. The number of 2s consists of 2s of regular part and irregular part.
// >> Regular part:
//    f(10) = 1 * 1,
//    f(100) = 10 * f(10) + 10 = 2 * 10,
//    f(1000) = 10 * f(100) + 100 = 3 * 100,
//    
//    For the most significant digit (MSD) n, 
//    Add n * position of n * 10^(position of n - 1)
//    ...
// >> Irregular part:
//    For the digits seen already, 
//    If the MSD is 2, then add #(seen digits) + 1;
//    If MSD is greater than 2, then add 10^(position of MSD).
// 2. Do this from the least significant to the most significant digit.
// 3. Then you are done.

int count_twos_iterative(int num)
{
	int count_of_2s = 0, digit = 0;
	int j = num, seen_digits = 0, position = 0, pow10_pos = 1;

	while(j > 0)
	{
		digit = j % 10;
		int pow10_pos_minus_1 = pow10_pos / 10;
		count_of_2s += digit * position * pow10_pos_minus_1;
		if(digit == 2)
			count_of_2s += seen_digits + 1;
		else if(digit > 2)
			count_of_2s += pow10_pos;

		seen_digits += pow10_pos * digit;
		pow10_pos *= 10;
		++position;
		j /= 10;
	}

	return	count_of_2s;
}


int main()
{
	for(int i = 10; i <= 1000; i += (rand() % 100))
	{
		std::cout << "Number: " << i << std::endl;
		std::cout << "Recursive: " << count_twos_recursive(i) << std::endl;
		std::cout << "Iterative: " << count_twos_iterative(i) << std::endl;
	}

	return 0;
}






























