// 20.2 Write a method to shuffle a deck of cards. It must be a perfect shuffle
//      - in other words, each 52! permutations of the deck has to be equally 
//      likely. Assume that you are given a random number generator which is 
//      perfect.


// Idea: randomly choose one and put it in the front of the array, and randomly
//       pick from remaining and put it in the second place, and so on.

#include <iostream>
#include <vector>

void shuffle_array(std::vector<int>& cards)
{
	int tmp = 0;
	int index = 0;
	int size = cards.size();

	srand(time(NULL));

	for(int i = 0; i < size; ++i)
	{
		index = rand() % (size - i) + i;
		tmp = cards[i];
		cards[i] = cards[index];
		cards[index] = tmp;
	}
}

int main()
{

	std::vector<int> cards;

	for(int i = 0; i < 52; ++i)
		cards.push_back(i+1);

	shuffle_array(cards);

	std::cout << "After shuffling: ";
	for(int i = 0; i < 52; ++i)
		std::cout << cards[i] << " ";
	std::cout << std::endl;

	return 0;
}




