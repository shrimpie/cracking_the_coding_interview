// 19.10 Write a method to generate a random number between 1 and 7, given a 
//       method that generates a random number between 1 and 5 (i.e., implement
//       rand7() using rand(5)).


// Idea:
// Uniformly generate a larger range than you are looking for and then repeatedly 
// sample until you get a number that is good for you.


#include <iostream>
#include <time.h>


int rand5()
{
	return (rand() % 5 + 1);
}


int rand7()
{
	while(true)
	{
		int num = 5 * (rand5() - 1) + (rand5() - 1);
		if(num < 21)
			return (num % 7 + 1);
	}
}


int main()
{
	srand(time(NULL));

	int trials = 7 * 10000;
	int times[7] = { 0, 0, 0, 0, 0, 0, 0 };
	for(int i=0; i < trials; ++i)
	{
		++times[rand7() - 1];
	}

	for(int i=0; i < 7; ++i)
	{
		std::cout << (i+1) << " occurs " << times[i] << " times." << std::endl;
	}

	std::cout << std::endl;


	return 0;
}