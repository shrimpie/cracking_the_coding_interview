// 8.8 Write an algorithm to print all ways of arranging eight queens on a 
//     chess board so that none of them share the same row, column or diagnal.

// Idea:
// The classic eight-queens problem.
// The gist is to efficiently check that no conflicts occur when adding new 
// queen.


// The idea from the book
// We will use a backtracking algorithm. For each row, the column where we want
// to put the queen is based on checking that it does not violate the required 
// condition.

// 1. For this, we need to store the column of the queen in each row as soon as
//    we have finianlized it. Let column_for_row[] be the array which stores 
//    the column number for each row.

// 2. The checks that are required for the three given conditions are:
//    >> On same column: column_for_row[i] == column_for_row[j]
//    >> On same diagnal: ((column_for_row[i] - column_for_row[j] == (i-j) or 
//       (column_for_row[j] - column_for_row[i] == (i-j))

// 
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void print_board(vector<int>& column_for_row, int count)
{
	string separator(column_for_row.size() - 2, '-');
	cout << endl << separator << ' ' << count << ' ' << separator << endl;
	for(int i = 0; i < column_for_row.size(); ++i)
	{
		int tgt = column_for_row[i];
		for(int j = 0; j < column_for_row.size(); ++j)
			cout << (j != tgt ? ". " : "* ");
		cout << endl;
	}
}


bool check(int row, vector<int>& column_for_row)
{
	for(int i = 0; i < row; ++i)
	{
		int diff = abs(column_for_row[i] - column_for_row[row]);
		if(diff == 0 || diff == row - i)
			return false;
	}
	return true;
}

void place_queen(int row, vector<int>& column_for_row, int& count)
{
	if(row == column_for_row.size())
	{
		++count;
		print_board(column_for_row, count);
		return;
	}
	for(int i = 0; i < column_for_row.size(); ++i)
	{
		column_for_row[row] = i;
		if(check(row, column_for_row))
			place_queen(row+1, column_for_row, count);
	}
}


int main()
{
	int size = 9;
	vector<int> column_for_row(size);

	int count = 0;
	place_queen(0, column_for_row, count);

	return 0;
}


















