// 1.4 Write a method to decide if two strings are anagrams or not.


// This one uses std::sort function within <algorithm>

#include <iostream>
#include <algorithm>

using namespace std;

bool anagram(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}



// This one check if two strings have identical counts for each unique char.
bool anagram2(string a, string b)
{
	if(a.size() == 0 || b.size() == 0)
		return false;

	if(a.size() != b.size())
		return false;

	int letters[256] = {0};
	int len_a = a.size();
	int unique_char_a = 0;
	for(int i = 0; i < len_a; i++)
	{
		if(letters[a[i]] == 0)
			++unique_char_a;
		++letters[a[i]];
	}

	int len_b = b.size();
	int num_completed = 0;
	for(int i = 0; i < len_b; i++)
	{
		if(letters[b[i]] == 0)
			return false;
		--letters[b[i]];
		if(letters[b[i]] == 0)
		{
			++num_completed;
			if(num_completed == unique_char_a)
				return true;
		}
	}

	return false;
}



int main()
{
	string a = "abcd";
	string b = "bcad";
	string c = "abnsla";
	string d = "abnsdl";

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << c << endl;

	cout << "a and b anagram? " << (anagram(a, b) ? "true" : "false") << endl;
	cout << "a and c anagram? " << (anagram(a, c) ? "true" : "false") << endl;
	cout << "c and d anagram? " << (anagram(c, d) ? "true" : "false") << endl;

	cout << "a and b anagram? " << (anagram2(a, b) ? "true" : "false") << endl;
	cout << "a and c anagram? " << (anagram2(a, c) ? "true" : "false") << endl;
	cout << "c and d anagram? " << (anagram2(c, d) ? "true" : "false") << endl;


	return 0;
}




