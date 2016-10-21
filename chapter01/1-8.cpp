// 1.8 Assume you have a method is_sub() which checks if one word
//     is a substring of another string. Given two strings, s1 and
//     s2, write code to check if s2 is a roation of s1 using only
// 	   one call of is_sub.

// 

#include <iostream>
using namespace std;

// Return if s2 is a substring of s1.
// Iterate from the first to the last possible position.
// Could be better.
bool is_sub(string s1, string s2)
{
	int len_s1 = s1.length();
	int len_s2 = s2.length();

	if(len_s1 < len_s2) return false;

	int last_pos = len_s1 - len_s2;

	for(int i = 0; i < last_pos; ++i)
	{
		int hit_num = 0;
		for(int j = 0; j < len_s2; ++j)
		{
			if(s1[i+j] == s2[j])
			{
				++hit_num;
				if(hit_num == len_s2)
					return true;
			}
			else
				break;
		}
	}
	return false;
}

bool is_rotation(string s1, string s2)
{
	if(s1.length() == s2.length())
	{
		string tmp = s1 + s1;
		return is_sub(tmp, s2);
	}

	return false;
}


int main()
{
	string s1 = "apple";
	string s2 = "pleap";
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s1 is a rotation of s2? " 
	     << (is_rotation(s1, s2) ? "Yes" : "No") << endl;

	return 0;
}














