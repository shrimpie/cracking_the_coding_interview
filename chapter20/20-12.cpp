// 20.12 Given an NxN matrix of positive and negative integers, write code to 
//       find the submatrix with the largest possible sum.


// Idea:
// Similar to the previous one.
// Well, not that similar exactly.
// 
// The solution from the book.
// Brute Force: complexity O(N^6)
// Like many "maximizing" problems, this problem has a straight forward brute 
// force solution. The brute force solution simply iterates through all 
// possible sub-matrixes, computes the sum, and finds the biggest.
// To iterate through all possible sub-matrixes (with no duplicates), we simply
// need to iterate through all order pairing of rows, and then all ordered pair
// of columns.
// This solution is O(N^6), since we iterate through O(N^4) sub-matrixes, and 
// it takes O(N^2) time to compute the area of each.

// Optimized solution: O(N^4)

// Note that the earlier solution is made slower by a factor of O(N^2) simply 
// because computing the sum of a matrix is so slow. Can we reduce the time to
// compute the area? Yes! In fact, we can reduce the time of compute_sum to 
// O(1).

// Consider the following:

// |-----------------------|
// |  A     | C |          |
// |------------|          |
// |  B     | D |          |
// |------------|          |
// |                       |
// |-----------------------|

// If we has the sum of the smaller rectangle (the one including A, B, C, D), 
// we could compute the sum of D as follows: area(D) = area(A through D) - 
// area(A) - area(B) - area(C).
// 
// What if, instead, we have the following:
//  (0,0)      x1  x2
//    |-----------------------|
//    |  A     | C |          |
// y1 |------------|          |
//    |  B     | D |          |
// y2 |------------|          |
//    |                       |
//    |-----------------------|

// with the following values (notice that each Val_* starts at the origin):
// Val_D = area(point(0, 0) -> point(x2, y2))
// Val_C = area(point(0, 0) -> point(x2, y1))
// Val_B = area(point(0, 0) -> point(x1, y2))
// Val_A = area(point(0, 0) -> point(x1, y1))

// With these values, we know the following:
// area(D) = Val_D - area(A union C) - area(A union B) + area(A)
// Or, written another way:
// area(D) = Val_D - Val_B - Val_C + Val_A
// Can we efficiently compute these Val_* values for all points in the matrix?
// yes, by using similar logic:
// Val_(x, y) = Val(x-1, y) + Val(y-1, x) - Val(x-1, y-1)

// We can precompute all such values, and then efficiently find the maximum 
// submatrix. See the following code for this implementation.




#include <iostream>
#include <vector>

#include <iomanip>


using namespace std;

vector<vector<int> >* precompute_matrix(vector<vector<int> > matrix)
{
	int N = matrix.size();
	vector<vector<int> >* sum_matrix = 
		new vector<vector<int> >(N, vector<int>(N));

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if(i == 0 && j == 0) // first cell
				(*sum_matrix)[i][j] = matrix[i][j];
			else if(j == 0)      // cell in first column
				(*sum_matrix)[i][j] = (*sum_matrix)[i-1][j] + matrix[i][j];
			else if(i == 0)      // cell in first row
				(*sum_matrix)[i][j] = (*sum_matrix)[i][j-1] + matrix[i][j];
			else
				(*sum_matrix)[i][j] = (*sum_matrix)[i-1][j] + 
									  (*sum_matrix)[i][j-1] - 
									  (*sum_matrix)[i-1][j-1] + 
									  matrix[i][j];
		}
	}

	return sum_matrix;
}

int compute_sum(vector<vector<int> > smatrix, int i1, int i2, int j1, int j2)
{
	if(i1 == 0 && j1 == 0)
		return smatrix[i2][j2];
	else if(i1 == 0)
		return smatrix[i2][j2] - smatrix[i2][j1-1];
	else if(j1 == 0)
		return smatrix[i2][j2] - smatrix[i1-1][j2];
	else
		return smatrix[i2][j2] - smatrix[i2][j1-1] - smatrix[i1-1][j2] +
	           smatrix[i1-1][j1-1];
}



int get_max_matrix(vector<vector<int> > original)
{
	int max_area = INT_MIN;
	int row_count = original.size();
	int col_count = original[0].size();
	vector<vector<int> >* matrix = precompute_matrix(original);

	// cout << "The sum matrix: " << endl;
	// for(int i=0; i<row_count; ++i)
	// {
	// 	for(int j=0; j < col_count; ++j)
	// 		cout << setw(3) << (*matrix)[i][j];
	// 	cout << endl;
	// }
	// cout << "-----------" << endl;

	for(int row1 = 0; row1 < row_count; ++row1)
	{
		for(int row2 = row1; row2 < row_count; ++row2)
		{
			for(int col1 = 0; col1 < col_count; ++col1)
			{
				for(int col2 = col1; col2 < col_count; ++col2)
				{
					int tmp_sum = compute_sum(*matrix, row1, row2, col1, col2);
					// cout << "tmp sum: " << tmp_sum << endl;
					if(tmp_sum > max_area)
						max_area = tmp_sum;
				}
			}
		}
	}

	return max_area;
}


int main()
{
	srand(time(NULL));

	int N = 4;

	vector<vector<int> > matrix;
	for(int i = 0; i < N; ++i)
	{
		vector<int>* row = new vector<int>();
		for(int j = 0; j < N; ++j)
			row->push_back(rand() % 10 * (rand() % 10 > 4 ? 1 : -1));

		matrix.push_back(*row);
	}

	cout << "The matrix: " << endl;
	
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
			cout << setw(3) << matrix[i][j];
			
		cout << endl;
	}

	cout << get_max_matrix(matrix) << endl;

	return 0;
}











