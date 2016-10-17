// 20.11 Imagine you have a square matrix, where each cell is filled with 
//       either black or white. Design an algorithm to find the maximum 
//       subsquare such that all four borders are filled with black pixels.
//


// Idea: 
// Iterate from left column to right, for each consecutive black boxes, test 
// if it can form a square, and if so, record its size.

// The method from the book:
// Assume square is of size N * N.
// This algorithm does the following:
// 1. Iterate through every (full) column from left to right.
// 2. At each (full) column (call this current_col), look at the subcolumns 
//    (from biggest to smallest).
// 3. At each subcolumn, see if you can form a square with the subcolumn at 
//    the left side. If so, update current_col and go to the next (full) 
//    column.
// 4. If N - current_col <= current_max_size, then break completely. We've 
//    found the largest square possible. Why? At each column, we're trying to 
//    to create a square with that column as the left side. The largest such 
//    square we could possibly create is N - current_col. Thus if n - 
//    current_col <= current_max_size, then we have no need to proceed.

// Time complexity: O(N^2)

#include <iostream>
#include <vector>

using namespace std;

struct SubSquare
{
	int row;
	int col;
	int size;
	SubSquare(int r, int c, int sz) : row(r), col(c), size(sz) {}
};

bool is_square(vector<vector<int> > matrix, int row, int col, int size)
{
	// check top and bottom border
	for(int j = 0; j < size; ++j)
	{
		if(matrix[row][col + j] == 0) // 0 means white
			return false;
		if(matrix[row + size - 1][col + j] == 0)
			return false;
	}

	// check left and right border
	for(int j = 1; j < size - 1; ++j)
	{
		if(matrix[row + j][col] == 0)
			return false;
		if(matrix[row + j][col + size - 1] == 0)
			return false;
	}

	return true;
}


SubSquare* find_subsquare(vector<vector<int> > matrix)
{
	int N = matrix.size();
	int current_max_size = 0;
	SubSquare* sq = NULL;
	int col = 0;

	// Iterate through each column from left to right
	while(N - col > current_max_size)
	{
		for(int row = 0; row < N; ++row)
		{
			// starting from the biggest
			int size = N - (row > col ? row : col);
			while(size > current_max_size)
			{
				if(is_square(matrix, row, col, size))
				{
					current_max_size = size;
					sq = new SubSquare(row, col, size);
					break; // go to next (full) column, current best found
				}
				--size;
			}
		}
		++col;
	}

	return sq;
}




int main()
{
	srand(time(NULL));

	int N = 20;

	vector<vector<int> > matrix;
	for(int i = 0; i < N; ++i)
	{
		vector<int>* row = new vector<int>();
		for(int j = 0; j < N; ++j)
			row->push_back(rand() % 10 > 3 ? 1 : 0);

		matrix.push_back(*row);
	}

	cout << "The matrix: " << endl;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	SubSquare* res = find_subsquare(matrix);

	cout << res->size << endl;


	return 0;
}



















