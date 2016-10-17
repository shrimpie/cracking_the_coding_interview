// 20.10 Given two words of equal length that are in a dictionary, write a 
//       method to transform one word into another word by changing only one
//       letter at a time. The new word you get in each step must be in the 
//       dictionary.
//       Example:
//       Input: DAMP, LIKE
//       Output: DMAP -> LAMP -> LIMP -> LIME-> LIKE


// Idea from the book
// 
// Though this problem seems tough, it's actually a straightforward 
// modification of breadth-frist-search. Each word in our "graph" branches to 
// all words in the dictionary that are one edit away. The interesting part is 
// how to implement this - should we build a graph as we go? We could, but 
// there's an easier way. We can instead use a "backtrack map". In this 
// backtrack map, if B[v] = w, then you know that you edited v to get w. When 
// we reach our end word, we can use this backtrack map repeatedly to reverse 
// our path. See the code below:

#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;


set<string>* get_one_edit_words(string word)
{
	set<string>* words = new set<string>();
	for(int i = 0; i < word.size(); ++i)
	{
		string tmp = word;
		char t = tmp[i];
		for(char c = 'A'; c <= 'Z'; ++c)
		{
			// if(c! = tmp[i]) // THIS IS A STUPID BUG.
			if(c != t)
			{
				tmp[i] = c;
				words->insert(tmp);
			}
		}
	}

	return words;
}


list<string>* transform_words(string start, string stop, set<string> dict)
{
	transform(start.begin(), start.end(), start.begin(), ::toupper);
	transform(stop.begin(), stop.end(), stop.begin(), ::toupper);

	queue<string>* action_queue = new queue<string>();
	set<string>* visited_set = new set<string>();
	map<string, string>* backtrack_map = new map<string, string>();

	action_queue->push(start);
	visited_set->insert(start);

	while(!action_queue->empty())
	{
		string w = action_queue->front();
		action_queue->pop();
		// For each possible word v from w with one edit operation
		set<string>* one_edit_words = get_one_edit_words(w);

		for(auto v : *one_edit_words)
		{
			if(v == stop)
			{
				// Found our word! Now, back track.
				list<string>* l = new list<string>();
				// Append to list
				l->push_front(v);
				while(backtrack_map->find(w) != backtrack_map->end())
				{
					l->push_front(w);
					w = backtrack_map->at(w);
				}
				return l;
			}
			// If v is a dictionary word
			if(dict.find(v) != dict.end())
			{
				if(visited_set->find(v) == visited_set->end())
				{
					action_queue->push(v);
					visited_set->insert(v); // Mark visited
					backtrack_map->insert(pair<string, string>(v, w));
				}
			}
		}
	}

	return NULL;
}


int main()
{
	set<string> dict = {"DAMP", "LIMP", "LAMP", "LIME", "LIKE" };


	list<string>* res = transform_words("damp", "like", dict);

	if(res != NULL)
	{
		for(auto s : *res)
		cout << s << " ";
		cout << endl;
	}
	else
		cout << endl << "Transform not found.\n";
	

	return 0;
}










