// 1.5 Write a method to replace all spaces in a string wiht '%20'


// Idea:

// 1. Count the number of spaces during the first scan of the string.
// 2. Parse the string again from the end and for each character:
//    >> If a space is encountered, store "%20".
//    >> Else, store the character as it is in the newly shifted location.





#include <iostream>
using namespace std;

char* replace_space(char *str)
{
	// Return an empty string for null string.
	if(str == NULL)
		return NULL;

	int spaces = 0;
	// First count how many spaces and new length.
	for(int i = 0 ; i< strlen(str); ++i)
		if(str[i] == ' ')
			++spaces;

	int tgt_str_len = strlen(str) + 2 * spaces;

	// Second insert from back to front.
	char* res_str = new char[tgt_str_len+1];

	res_str[tgt_str_len] = '\0';

	for(int i = strlen(str) - 1; i >= 0; --i)
	{
		if(str[i] == ' ')
		{
			res_str[tgt_str_len-1] = '0';
			res_str[tgt_str_len-2] = '2';
			res_str[tgt_str_len-3] = '%';
			tgt_str_len -= 3;
		}
		else
		{
			res_str[tgt_str_len-1] = str[i];
			--tgt_str_len;
		}
	}
	return res_str;
}


int main()
{
	char str[] = "I have no idea when to stop.";
	char *res = replace_space(str);

	cout << "Original: " << str << endl;
	cout << "After replace: " << res << endl;
	return 0;
}








