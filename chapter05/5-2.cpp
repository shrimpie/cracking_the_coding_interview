// 5.2 Given a (decimal - e.g., 3.72) number that is passed in as a string, 
//     print the binary representation. If the number can not be represented
//     accurately in binary, print "ERROR".


// Solution:
// 1. Two steps: the integer part, and the decimal part.
// 2. For the integer part: keep % 2, and record the bits (in reverse order).
// 3. For the decimal part: keep * 2, if >= 1, add '1', otherwise, add '0'.


#include <iostream>


std::string binary_format(std::string num)
{
	double deci = std::stod(num);
	int int_part = (int)deci;
	double deci_part = deci - int_part;

	std::string int_str = "";

	while(int_part > 0)
	{
		int r = int_part % 2;
		int_part >>= 1;
		int_str = std::to_string(r) + int_str;
	}

	std::string deci_str = "";

	while(deci_part > 0)
	{
		if(deci_str.size() > 32)
		{
			std::cout << "Cannot be represented exactly right.\n";
			break;
		}
		if(deci_part == 1)
		{
			deci_str += '1';
			break;
		}
		double r = deci_part * 2;
		if(r >= 1)
		{
			deci_str += '1';
			deci_part = r - 1;
		}
		else
		{
			deci_str += '0';
			deci_part = r;
		}

	}

	return int_str + "." + deci_str;
}



int main()
{
	std::string number = "3.72";

	std::cout << binary_format(number) << std::endl;


	return 0;
}




















