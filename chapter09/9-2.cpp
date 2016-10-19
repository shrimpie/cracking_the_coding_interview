// 9.2 Write a method to sort an array of strings so that all the anagrams are 
//     next to each other.

// anagrams: words that have the same alphabets but different orders

// Idea:
// Sort each word, and compare.

#include <iostream>
#include <vector>

using namespace std;


bool sort_str(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return (a < b);
}

vector<string> anagram_sort(vector<string> vs)
{
	vector<string> vs2(vs);
	sort(vs2.begin(), vs2.end(), sort_str);
	return vs2;
}


void print_vector(vector<string>& vs)
{
	for(auto s : vs)
		cout << s << ", ";
	cout << endl;
}


int main()
{
	const char* strs[] = { "this", "is", "not", "cool",
	                     "hist", "si", "ton", "looc" };
	vector<string> vs(strs, strs + 8);

	print_vector(vs);

	vector<string> vs_sorted = anagram_sort(vs);

	print_vector(vs_sorted);


	return 0;
}









