// 1.7 Write an algorithm such that if an element in a MxN matrix is 0, 
// its entire row and column is set 0.

// Idea:
// 

#include <iostream>
#include <vector>

using namespace std;

void set_zero(vector<vector<int> >& mat)
{
	vector<int> row = vector<int>(mat.size());
	vector<int> col = vector<int>(mat[0].size());

	for(int i = 0; i < row.size(); ++i) row[i] = 0;
	for(int i = 0; i < col.size(); ++i) col[i] = 0;

	for(int i = 0; i < row.size(); ++i)
	{
		for(int j = 0; j < col.size(); ++j)
		{
			if(mat[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i = 0; i < row.size(); ++i)
	{
		for(int j = 0; j < col.size(); ++j)
		{
			if((row[i] == 1) || col[j] == 1)
				mat[i][j] = 0;
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
	srand(time(NULL));

	int D = 5;
	vector<vector<int> > mat(D, vector<int>(D));
	for(int i = 0; i < mat.size(); ++i)
	{
		for(int j = 0; j < mat[0].size(); ++j)
			mat[i][j] = rand() % 10;
			// mat[i][j] = (rand() % 10 > 8) ? 0 : rand() % 10;
	}

	cout << "Original: " << endl;
	print_matrix(mat);
	set_zero(mat);
	cout << "After setting zero: " << endl;
	print_matrix(mat);


	return 0;
}





