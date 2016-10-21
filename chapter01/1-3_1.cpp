// 1.3 Desing an algorithm and write code to remove the duplicated characters 
//     in a string without using any additional buffer.
//     Note: one or two additional variables are fine. A copy of
// 	   the array is not.


// With additional memory of constant size.

#include <iostream>
using namespace std;

void remove_duplicates(char *str)
{
	if(str == NULL)
		return;
	if(strlen(str) < 2)
		return;
	bool hit[256] = { false };

	hit[str[0]] = true;
	int tail = 1;
	int str_len = strlen(str);
	for(int i = 1; i < str_len; i++)
	{
		if(!hit[str[i]])
		{
			str[tail] = str[i];
			++tail;
			hit[str[i]] = true;
		}
	}
	str[tail] = 0;
}

int main()
{
	char str1[] = "abababsidljlajalgjla";
	char str2[] = "a";
	char* str3 = NULL;

	remove_duplicates(str1);
	remove_duplicates(str2);
	remove_duplicates(str3);
	cout << "str1 after removing duplicates: " << str1 << endl;
	cout << "str2 after removing duplicates: " << str2 << endl;
	cout << "str3 after removing duplicates: " 
	     << (str3 == NULL ? "null" : "not null") << endl;
	return 0;
}
