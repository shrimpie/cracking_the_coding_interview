// 20.5 You have a large text file containing words. Given any two words, find 
//      the shortest distance (in terms of number of words) between them in the
//      file. Can you make the searching operation in O(1) time? What about the
//      space complexity for your solution?


// Idea:
// We can do a linear search and find all the positions of all words stored in
// a hashtable, and find the minimum difference in the positions


// The answer given by the book
#include <iostream>
#include <vector>

using namespace std;

int shortest_word_difference(vector<string> words, string word1, string word2)
{
	int min = INT_MAX / 2;
	int word1_pos = -min;
	int word2_pos = -min;

	for(int i = 0; i < words.size(); ++i)
	{
		string cur = words[i];
		if(cur == word1)
		{
			word1_pos = i;

			int distance = word1_pos - word2_pos;
			if(min > distance)
				min = distance;
		}
		else if(cur == word2)
		{
			word2_pos = i;
			int distance = word2_pos - word1_pos;
			if (min > distance)
				min = distance;
		}
	}

	return min;
}


int main()
{
	srand(time(NULL));

	vector<string> vs;
	vs.push_back("5");

	for(int i = 0; i < 20; ++i)
		vs.push_back(to_string(rand() % 20));

	vs.push_back("17");

	for(int i = 0; i < vs.size(); ++i)
		cout << vs[i] << " ";
	cout << endl;

	cout << shortest_word_difference(vs, "5", "17") << endl;

	return 0;
}

// More from the book
// To solve this problem in less time (but more space), we can create a hash 
// table with each word and the locations where it occurs. We just need to 
// find the minimum (arithmetic) difference in the locations (e.g., 
// abs(word0.loc[1] - word2.loc[5])).

// To find the minimum arithmetic difference, we take each location for word1 
// (e.g., 0, 3) and do a modified binary search for it in word2's location 
// list, returning the closest number. Our search for 3, for example, in (2, 7,
// , 9) would return 1. The minimum of all these binary searches is the closest
// distance.












