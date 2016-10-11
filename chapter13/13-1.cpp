// Write a method to print the last K lines of an input file using C++.

// Attempted idea:
// 1. You may want to find '\n', which is to separate lines.
// 2. How do you find the (K+1)th last '\n': can you first locate the file end
//    and go through the file backwards and find the target '\n'?
// Correction: You cannot do the backward counting thing.. Too bad.

// Let's look at the answer.
// One brute force way could be to count the number of lines (N) and then print
// from N-10 to Nth line. But, this requires two reads of the file -- 
// potentially very costly if the file is large. Indeed true.
// We need a solution which allows us to read just once and be able to print
// the last K lines. We can create extra space for K lines and then store each
// set of K lines in the array. So, initially, our array has lines 0 through 9,
// then 2 through 10, then 2 through 11, etc (if K = 10). Each time that we
// read a new line, we purge the oldest line from the array. Instead of
// shifting the array each time (very inefficient), we will use a circular
// array. Tshi will allow us to always find the oldest element in O(1) time.

// Example of inserting elements into a circular array:
//   step 1 (initially): array = { a, b, c, d, e, f }. p = 0;
//   step 2 (insert g): array = { g, b, c, d, e, f }. p = 1;
//   step 3 (insert h): array = { g, h, c, d, e, f }. p = 2;
//   step 4 (insert i): array = { g, b, i, d, e, f }. p = 3;

// The code
#include <fstream>
#include <iostream>
#include <vector>


void print_last_k_lines(std::string file_name, int k)
{
	std::vector<std::string> res(k);
	int lines = 0;
	std::ifstream myfile(file_name);
	if(myfile.is_open())
	{
		// while(getline(myfile, res[lines % k]))
		//     ++lines;
		// Above is the answer from the book, it actually has a bug.
		// The last time getline(,) got an empty string and rewrites res,
		// so previous string is lost.

		std::string tmp;
		while(getline(myfile, tmp))
		{
			if(tmp != "")
				res[lines % k] = tmp;
			++lines;
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file.\n";

	// std::cout << "lines: " << lines << std::endl;

	// If less than K lines were read, print them all
	int start, count;
	if(lines < k)
	{
		start = 0;
		count = lines;
	}
	else
	{
		start = lines % k;
		count = k;
	}

	// for(int i=0; i<k; ++i)
	// 	std::cout << res[i] << std::endl;

	// std::cout << "start: " << start << std::endl;
	// std::cout << "count: " << count << std::endl;

	for(int i=0; i<count; ++i)
		std::cout << res[(start+i) % k] << std::endl;

}

void generate_file(std::string file_name, int line_count)
{
	std::ifstream infile(file_name);

    if(!infile.good())
    {
		std::ofstream myfile(file_name);
		if(myfile.is_open())
		{
			std::string tmp;
			for(int i=0; i<line_count; ++i)
			{
				// 
				tmp = "This is line #" + std::to_string(i+1);
				myfile << tmp << '\n';
			}
			myfile.close();
		}
		else
			std::cout << "Unable to open file.\n";
	}
	// std::cout << "File already exists.\n";
	infile.close();
}




int main()
{
	std::string file_name = "13-1_example_file_long.txt";
	int k = 10;
	int max_lines = 100;

	generate_file(file_name, max_lines);
	print_last_k_lines(file_name, k);


	file_name = "13-1_example_file_short.txt";
	k = 10;
	max_lines = 5;
	generate_file(file_name, max_lines);
	print_last_k_lines(file_name, k);


	return 0;
}




