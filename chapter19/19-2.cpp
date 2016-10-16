// 19.2 Design an algorithm to figure out if someone has won in a game of 
//      tic-tac-toe.


// If has_won() function will be called multiple times:
// There are only 3^9 boards. You can represent the board as an int, and set up
// hashtable in advance with all possible boards as keys, and the values 0, 1, 
// and 2. Then the function is simply this:
// int has_won(int board)
//  {
//       return winnner_hashtable[board];
//  }
// 

// If has_won() is only called once:

#include <iostream>
#include <vector>

using namespace std;


enum Piece { Empty, Red, Blue };
enum Check { Row, Column, Diagonal, ReverseDiagonal };

Piece get_ith_color(vector<vector<Piece> > board, int index, int var, Check ch)
{
	if(ch == Row) return board[index][var];
	else if(ch == Column) return board[var][index];
	else if(ch == Diagonal) return board[var][var];
	else if(ch == ReverseDiagonal) return board[board.size()-1-var][var];

	return Empty;
}

Piece get_winner(vector<vector<Piece> > board, int fixed_index, Check ch)
{
	Piece color = get_ith_color(board, fixed_index, 0, ch);
	if(color == Empty) return Empty;

	for(int var = 1; var < board.size(); ++var)
	{
		if(color != get_ith_color(board, fixed_index, var, ch))
			return Empty;
	}
	return color;
}

Piece has_won(vector<vector<Piece> > board)
{
	int N = board.size();
	Piece winner = Empty;

	// check rows and columns
	for(int i=0; i < N; ++i)
	{
		winner = get_winner(board, i, Row);
		if(winner != Empty)
			return winner;

		winner = get_winner(board, i, Column);
		if(winner != Empty)
			return winner;
	}

	winner = get_winner(board, -1, Diagonal);
	if(winner != Empty)
		return winner;

	winner = get_winner(board, -1, ReverseDiagonal);
	if(winner != Empty)
		return winner;

	return Empty;
}




int main()
{
	vector<Piece> row1;
	row1.push_back(Empty);
	row1.push_back(Red);
	row1.push_back(Blue);

	vector<Piece> row2;
	row2.push_back(Empty);
	row2.push_back(Blue);
	row2.push_back(Red);

	vector<Piece> row3;
	row3.push_back(Blue);
	row3.push_back(Red);
	row3.push_back(Empty);


	vector<vector<Piece> > board;

	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);

	cout << (has_won(board) == Red ? "Red won!" : "Blue Won!") << endl;

	// Blue Won!

	return 0;
}







