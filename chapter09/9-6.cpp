// 9.6 Given a matrix in which each row and each column is sorted, write a 
//     method to find an element in it.

// Idea:
// Assumptions:
// >> Rows are sorted left to right in ascending order. Columns are sorted top 
//    to bottom in ascending order.
// >> Matrix is of size MxN.

// This algorithm works by elimination. Every move to the left (--col) 
// eliminates all the elements below the current cell in that column. Likewise,
// every move down eliminates all the elements to the left of the cell in that 
// row.

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Position
{
	int row;
	int col;
	Position(int r, int c) : row(r), col(c) {}
};

Position find_element(vector<vector<int> > mat, int elem, int M, int N)
{
	Position p(0, N-1);
	while(p.row < M && p.col >= 0)
	{
		if(mat[p.row][p.col] == elem)
			return p;
		else if(mat[p.row][p.col] > elem)
			--p.col;
		else
			++p.row;
	}

	return Position(-1, -1);
}

int main()
{
	int M = 4;
	int N = 5;
	vector<vector<int> > mat(M, vector<int>(N));

	cout << "The matrix: " << endl;
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			mat[i][j] = i * j + 1;
			cout << setw(3) << mat[i][j];
		}
		cout << endl;
	}

	Position p = find_element(mat, 9, M, N);
	cout << p.row << ", " << p.col << endl;

	return 0;
}