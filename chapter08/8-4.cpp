// 8.4 Write a method to compute all permutations of a string.

// Idea:
// For a string of size N, given Perm(N-1) (for the last N-1 characters), insert
// the first letter to each position of each permutation string.

#include <iostream>
#include <vector>
using namespace std;


vector<string>* permutations(string str)
{
	if(str.size() == 0)
		return NULL;
	if(str.size() == 1)
	{
		vector<string>* single = new vector<string>();
		single->push_back(str);
		return single;
	}

	vector<string>* res = new vector<string>();

	if(str.size() > 1)
	{
		for(auto s : (*permutations(str.substr(1))))
		{
			for(int i = 0; i < str.size(); ++i)
			{
				string tmp = s.substr(0, i) + str[0] + s.substr(i);
				res->push_back(tmp);
			}
		}
	}

	return res;
}

void print_vs(vector<string>& vs)
{
	for(int i = 0; i < vs.size(); ++i)
		cout << vs[i] << endl;
}


int main()
{
	string str = "abc";

	print_vs(*permutations(str));

	return 0;
}