// 20.3 Write a method to randomly generate a set of m integers from an array 
//      of size n. Each element must have equal probability of being chosen.

// Idea: similar to 20.2

#include <iostream>
#include <vector>
using namespace std;


void pick_randomly(vector<int> ori, vector<int>& deck, int m)
{
	srand(time(NULL));

	for(int j = 0; j < m; ++j)
	{
		int index = rand() % (ori.size() - j) + j;
		deck.push_back(ori[index]);
		ori[index] = ori[j];
	}
}

int main()
{
	vector<int> original;
	vector<int> deck;

	for(int i = 0; i < 52; ++i)
		original.push_back(i+1);

	pick_randomly(original, deck, 17);

	std::cout << "The one hand deck: ";
	for(int i = 0; i < 17; ++i)
		std::cout << deck[i] << " ";
	std::cout << std::endl;

	return 0;
}
