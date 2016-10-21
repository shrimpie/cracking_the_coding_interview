// 1.2 Write code to reverse a C-style string.
//     (C-style string means that "abcd" is represented as five characters,
//     including the null character.)

#include <iostream>
using namespace std;

void reverse(char *str)
{
	char * end = str;
	char tmp;

	if(str)
	{
		while(*end)
			++end;
		--end;
		while(str < end)
		{
			tmp = *end;
			*end-- = *str;
			*str++ = tmp;
		}
	}
}

int main()
{
	char str1[] = "abcdefghijklmnopqrstuvwxyz";
	char str2[] = "abcddcba";
	reverse(str1);
	reverse(str2);

	cout << "Reversed: " << str1 << endl;
	cout << "Reversed: " << str2 << endl;
	return 0;
}