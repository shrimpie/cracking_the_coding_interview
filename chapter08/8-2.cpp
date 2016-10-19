// 8.2 Imagine a robot sitting on the upper left hand corner of an NxN grid. 
//     The robot can only move in two directions: right and down. How many 
//     possible paths are there for the robot?
//     Follow up
//     Imagine certain squares are "off limits", such that the robot can not 
//     step on them. Design an algorithm to get all possible paths for the 
//     robot.


// Idea:
// Assume upper left corner has a coordinates of (N, N).
// NumOfPaths(x,y) = NumOfPaths(x-1, y) + NumOfPaths(x, y-1).
//

// The idea from the book.
// 1. For clarity, we will solve this part assuming an X by Y grid.
// 
//    Each path has (X-1)+(Y-1) steps. Imagine the following paths:
//
//    X X Y Y X (move right -> right -> down -> down -> right)
//    X Y X Y X (move right -> down -> right -> down -> right)
//
//    Each path can be fully represented by the moves at which we move right. 
//    That is, if I were to ask you which path you took, you could simply say 
//    "I moved right on step 3 and 4".
//    
//    Since you must always move right X-1 times, and you have X-1+Y-1 total 
//    steps, you have to pick X-1 times to move right out of X-1+Y-1 choices. 
//    Thus, there are C(X-1, X-1+Y-1) paths (e.g., X-1+Y-1 choose X-`):
//        (X-1 + Y-1)! / ((X-1)! * (Y-1)!)

// 2. We can implement a simple recursive algorithm with backtracking.
// The code provided is misleading, so here it is omitted.

#include <iostream>
#include <vector>

using namespace std;

int fact(int n)
{
	if(n < 0)
		return -1;

	int res = 1;
	for(int i = 2; i <= n; ++i)
		res *= i;

	return res;
}

int num_of_paths(int N, int M)
{
	return fact(N+M-2) / (fact(N-1) * fact(M-1));
}


int num_of_paths_r(int N, int M)
{
	// When arrive at right or bottom border, there is only one way
	if(N == 1 || M == 1)
		return 1;
	return num_of_paths_r(N-1, M) + num_of_paths(N, M-1);
}

int nums_of_paths(vector<vector<int> >& matrix, int N, int M)
{
	// Assume the right lower corner is always reachable.
	if(N == 0 && M == 0)
		return 1;

	int paths = 0;
	// Assume the upper left corner is also reachable.
	if(N > 0 && matrix[N-1][M] == 0)
		paths += nums_of_paths(matrix, N-1, M);
	if(M > 0 && matrix[N][M-1] == 0)
		paths += nums_of_paths(matrix, N, M-1);

	return paths;
}



int main()
{
	int N = 4;
	int M = 4;

	cout << num_of_paths(N, M) << endl;
	cout << num_of_paths_r(N, M) << endl;


	srand(time(NULL));

	vector<vector<int> > mat(N, vector<int>(M));
	cout << "The matrix: " << endl;
	for(int i = N-1; i >=0; --i)
	{
		for(int j = M-1; j >= 0; --j)
		{
			// Make left upper and right lower corner reachable.
			if( i == j )
				mat[i][j] = 0;
			else
				mat[i][j] = (rand() % 10 > 8 ? 1 : 0);

			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << nums_of_paths(mat, N-1, M-1) << endl;

	return 0;
}


























