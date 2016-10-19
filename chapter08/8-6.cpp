// 8.6 Implement the "paint fill" function that one might see on many image 
//     editing programs. That is, given a screen (represented by a 
//     2-dimensional array of colors), a point, and a new color, fill in the 
//     surrounding area until you hit a border of that color.

// Idea:
// Paint pixel by pixel, expand outwards until you hit a pixel that has a 
// different color.

// The code

#include <iostream>
#include <vector>

using namespace std;

enum Color {
	Black, White, Red, Yellow, Green
};

bool paint_fill(vector<vector<Color> >& pic, int x, int y, Color oc, Color nc)
{
	if(x < 0 || x >= pic[0].size() ||
	   y < 0 || y >= pic.size())
		return false;

	if(pic[y][x] == oc)
	{
		pic[y][x] = nc;
		paint_fill(pic, x-1, y, oc, nc); // left
		paint_fill(pic, x+1, y, oc, nc); // right
		paint_fill(pic, x, y-1, oc, nc); // top
		paint_fill(pic, x, y+1, oc, nc); // bottom
	}

	return true;
}


void print_pic(vector<vector<Color> >& pic, string msg)
{
	cout << endl << "The pic " << msg << ": " << endl;
	for(int i = 0; i < pic.size(); ++i)
	{
		for(int j = 0; j < pic[0].size(); ++j)
			cout << (int)(pic[i][j]) << " ";
		cout << endl;
	}
}

int main()
{
	int row = 10;
	int col = 10;
	vector<vector<Color> > pic(row, vector<Color>(col));

	srand(time(NULL));

	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			if(rand() % 5 != 4)
				pic[i][j] = Green;
			else
			{
				int tmp = rand() % 5;
				pic[i][j] = (Color)tmp;
			}			
		}
	}

	print_pic(pic, "initially is");

	pic[row/2-1][row/2-1] = Green;
	paint_fill(pic, row/2-1, col/2-1, Green, Black);

	print_pic(pic, "now becomes");

	return 0;
}








