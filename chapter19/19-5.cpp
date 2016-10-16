// 19.5 The game of Master Mind is played as follows:
//      The computer has four slots containing balls that are red(R), yellow(Y)
//      , green(G) or blue(B). For example, the computer might have RGGB.
//      You are trying to guess the solution. You might guess YRGB.
//      When you guess the correct color for the correct slot, you get a 'hit'.
//      If you guess a color that exists but is in the wrong slot, you get a 
//      'pseudo-hit'. For example, the guess YRGB has 2 hits and one pseudo hit.
//      For each guess, you are told the number of hits and pseudo-hits.
//      Write a method that, given a guess and a solution, returns the number of 
//      hits and pseudo hits.


// Straight forward solution:

#include <iostream>


class Result
{
public:
	int hits;
	int pseudo_hits;
};

Result* estimate(std::string guess, std::string solution)
{
	Result* res = new Result();
	int solution_mask = 0;
	for(int i=0; i<4; ++i)
		solution_mask |= (1 << (1+solution[i]-'A'));

	for(int i=0; i<4; ++i)
	{
		if(guess[i] == solution[i])
			++res->hits;
		else if((solution_mask & (1 << (1 + guess[i] - 'A'))) >= 1)
			++res->pseudo_hits;
	}
	return res;
}

int main()
{
	std::string guess = "YRGB";
	std::string solution = "RGGB";

	Result* res = estimate(guess, solution);
	std::cout << "hits: " << res->hits << std::endl;
	std::cout << "pseudo_hits: " << res->pseudo_hits << std::endl;

	return 0;
}












