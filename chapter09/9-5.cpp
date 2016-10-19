// 9.5 Given a sorted array of strings which is interspersed with empty strings
//     , write a method to find the location of a given string.
//     Example: 
//     find "ball" in ["at", "", "", "", "ball", "", "", "car", "", "", "dad", 
//     "", ""] will return 4
//     Find "ballcar" in ["at", "", "", "", "", "ball", "car", "", "", "dad", 
//     "", ""] will return -1.

// Idea:
// Binary search again.

#include <iostream>
#include <vector>

using namespace std;

int search(vector<string> strs, string str, int first, int last)
{
	while(first < last)
	{
		// Ensure there is something at the end.
		while(first <= last && strs[last] == "")
			--last;
		if(last < first)
			return -1; // This block was empty, so fail

		int mid = (first + last) >> 1;
		while(strs[mid] == "")
			++mid; // will always find one, because of the last
		if(strs[mid] == str)
			return mid;
		else if(strs[mid] < str)
			first = mid + 1;
		else
			last = mid - 1;
	}

	return -1;
}

int search(vector<string> strs, string str)
{
	if(strs.size() == 0)
		return -1;
	if(str == "")
	{
		for(int i = 0; i < strs.size(); ++i)
			if(strs[i] == "")
				return i;
		return -1;
	}
	return search(strs, str, 0, strs.size()-1);
}

int main()
{
	const char* strs[] = { "at", "", "", "", "ball", "", "", "car", "", "", 
					     "dad", "", "" };
	vector<string> vs(strs, strs + sizeof(strs) / sizeof(strs[0]));

	cout << search(vs, "ball") << endl;
	cout << search(vs, "ballcar") << endl;
	cout << search(vs, "") << endl;

	return 0;
}

















