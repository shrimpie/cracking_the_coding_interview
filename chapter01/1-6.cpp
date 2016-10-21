// 1.6 Given an image represented by a NxN matrix, where each
//     pixel in the image is 4 bytes, write a method to rotate
//     the image by 90 degrees. Can you do this in place?

//   i       n-1-i
//   1 2 3 4 5
//   2 3 4 5 1
//   3 4 5 1 2
//   4 5 1 2 3
//   5 1 2 3 4

// Idea: 
// The key point is to remember for the loop each time
// which column or row remains the same or changes by how much offset.

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> >& matrix)
{
	int n = matrix.size();
	// Outer loop iterates half of matrix size times.
	for(int i = 0; i < n / 2; ++i)
	{
		// Inner loop iterates matrix size times.
		// Record starts, ends of each loop.
		int start = i;
		int end = n - 1 - i;
		for(int j = start; j < end; ++j)
		{
			int offset = j - start;
			// record top
			int tmp = matrix[start][j];

			// left -> top
			matrix[start][j] = matrix[end-offset][start];

			// bottom -> top
			matrix[end-offset][start] = matrix[end][end-offset];

			// left -> bottom
			matrix[end][end-offset] = matrix[j][end];

			// top -> right
			matrix[j][end] = tmp;
		}
	}
}

void print_matrix(vector<vector<int> >& mat)
{
	for(int i = 0; i < mat.size(); ++i)
	{
		for(int j = 0; j < mat[0].size(); ++j)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int dimension = 5;
	vector<vector<int> > mat(dimension, vector<int>(dimension));
	for(int i = 0; i < mat.size(); ++i)
	{
		for(int j = 0; j < mat[0].size(); ++j)
			mat[i][j] = j + 1;
	}


	cout << "Original: " << endl;
	print_matrix(mat);
	rotate(mat);
	cout << "After roation: " << endl;
	print_matrix(mat);
	return 0;
}




