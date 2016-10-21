// 1.1 Implement an algorithm to determine if a string has all unique 
//     characters.
//     What if you cannot use additional data structure?


// Idea:
// For simplicity, assume ASCII char set.

// We can reduce our space usage a little bit by using a bit vector, same 
// logic.

// Alternatively, you can the following:
// 1. Check every char of the string with every other char of the string for 
//    duplicate occurences. This will O(n^2) time and no additional space.
// 2. If you are allowed to destroy the input string, you could sort the string
//    in O(nlogn) time and then linearly check the string for neighboring chars
//    that are identical. Careful, though - many sorting algorithms take up 
//    extra space.
// 

#include <iostream>

using namespace std;

bool has_unique_chars(string str)
{
	// Use a flag array to determine if you met a certain char.
	bool flag[256] = {false};

	// For each char, if its flag is false, set true.
	// If its flag is true, then the string has duplicates.
	for(int i = 0; i < str.length(); i++)
	{
		int val = str[i];
		if(flag[val])
			return false;
		flag[val] = true;
	}
	return true;
}

int main()
{
	string str1 = "this is a string with not unique characters.";
	string str2 = "abcdefghijklmnopqrstuvwxyz";
	cout << "str1 has unique chars? " 
	     << (has_unique_chars(str1) ? "True" : "False") << endl;
	cout << "str2 has unique chars? " 
	     << (has_unique_chars(str2) ? "True" : "False") << endl;
	return 0;
}
