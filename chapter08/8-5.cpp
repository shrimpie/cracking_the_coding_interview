// 8.5 Implement an algorithm to print all valid (e.g., properly opened and 
//     closed) combinations of n-pairs of parentheses.
//     Example:
//     Input: 3 (e.g., 3 pairs of parentheses)
//     Output: ()()(), ()(()), (())(), ((())), (()()).

// Idea:
// We can solve this problem recursively by recursing through the string. On 
// each iteration, we have the index for a particular character in the string.
// We need to select either a left or a right paren. When can we use left, and 
// when can we use a right paren?
// >> Left: as long as we haven't used up all the left parentheses, we can 
//    always insert a left paren.
// >> Right: We can insert a right paren as long as it won't lead to any syntax
//    error. When will we get a syntax error? We will get a syntax error if 
//    there are more right parentheses than left.

// So, we simply keep track of the number of left and right parentheses allowed
// . If there are left parens remaining, we'll insert a left paren and recurse.
// If there are more right parens remaining than left (eg, if there are more 
// left parens used), then we'll insert a right paren and recurse.


#include <iostream>
// #include <vector>


using namespace std;


void print_valid_parens(int l, int r, string str, int count)
{
	if(l < 0 || r < 0) // Invalid states, but why r < 1?
		return;
	if(l == 0 && r == 0)
		std::cout << str << std::endl;
	else
	{
		if(l > 0)
		{
			str[count] = '(';
			print_valid_parens(l-1, r, str, count+1);
		}
		if(r > l)
		{
			str[count] = ')';
			print_valid_parens(l, r-1, str, count+1);
		}
	}
}



int main()
{
	int count = 6;

	string str(2 * count, ' ');

	print_valid_parens(count, count, str, 0);

	return 0;
}














