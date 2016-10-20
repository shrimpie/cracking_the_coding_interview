// 7.1 Design the data structure for a generic deck of cards. Explain how 
//     would you subclass it to implement particular card games.

// Solution:
// The solution is modified to below.


#include <iostream>
using namespace std;


enum Suit
{
	Club, Spade, Heart, Diamond	
};

class Card
{
	int point; // 
	int value; // The value of a card may differ from the point value.
	Suit suit; //

public:

	Card(int p, Suit s) : point(p), value(p), suit(s) {}

	int get_value()
	{
		return value;
	}

	int get_point()
	{
		return point;
	}

	Suit get_suit()
	{
		return suit;
	}

	void set_point(int p)
	{
		point = p;
	}

	void set_value(int v)
	{
		value = v;
	}

	void set_suit(Suit s)
	{
		suit = s;
	}

};


class BlackJackCard : public Card
{
public:
	BlackJackCard(int p, Suit s) : Card(p, s) {}

	int get_value()
	{
		int point = Card::get_point();
		if(point == 1)
			return 11; // aces are 11
		if(point < 10)
			return point;
		return 10;
	}

	bool is_ace()
	{
		return (Card::get_point() == 1);
	}

};


int main()
{
	BlackJackCard bjc(1, Diamond);

	cout << bjc.get_value() << endl;


	return 0;
}














