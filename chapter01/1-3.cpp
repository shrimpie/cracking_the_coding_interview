// 1.3 Desing an algorithm and write code to remove the duplicated characters 
//     in a string without using any additional buffer.
//     Note: one or two additional variables are fine. A copy of
// 	   the array is not.
   

// Idea:
// First ask yourself, what does the interviewer mean by an additional buffer? 
// Can we use an additional array of constant size?

// No additional memory:
// 1. For each character, check if it is a duplicate of already found 
//    characters.
// 2. Skip duplicate characters and update the non duplicate characters.


#include <iostream>
using namespace std;

void remove_duplicates(char* str)
{
	// If string is NULL, return
	if(!str) return;

	int str_len = strlen(str);
	if(str_len < 2)
		return;

	// Remember the tail of all unique characters.
	int tail = 1;
	for(int i = 1; i < str_len; i++)
	{
		// Check if met characters with currently
		// found uniques ones.
		int j;
		for(j = 0; j < tail; ++j)
		{
			// If found duplicates, ignore it.
			if(str[i] == str[j])
				break;
		}
		// If not found, record the new one,
		// and increment tail position.
		if(j == tail)
		{
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = '\0';
}


int main()
{
	char str1[] = "abababsidljlajalgjla"; // random string
	cout << "Orginal: " << str1 << endl;
	remove_duplicates(str1);
	cout << "After removing duplicates: " << str1 << endl;
	return 0;
}






