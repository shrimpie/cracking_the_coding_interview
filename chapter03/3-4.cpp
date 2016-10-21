// 3.4 In the classic problem of the Towers of Hanoi, you have 3 rods and N 
//     disks of different sizes which can slide onto any tower. The puzzle 
//     starts with disks sorted in ascending order of size from top to bottom
//     (eg, each disk sits on top of an even larger one). You have the 
//     following constraints.
//     (A) Only one disk can be moved at a time.
//     (B) A disk is slid off the top of one rod onto the next rod.
//     (C) A disk can only be placed on top of a larger disk.
//     Write a program to move the disks from the first rod to the last using 
//     stacks.

#include <iostream>
#include <vector>

using namespace std;


class Stack
{
	int size;
	int * buffer;
	int top;

public:
	Stack(int s)
	{
		top = 0;
		size = s;
		buffer = new int[s];
	}
	void push(int val)
	{
		if( top < size )
		{
			++top;
			buffer[top] = val;
			return;
		}
		cout << "Stack full!" << endl;
		exit(-1);
	}
	int pop()
	{
		int value;
		if(top > 0)
		{
			value = buffer[top];
			--top;
			return value;
		}
		cout << "Error: stack empty!\n";
		exit(-2);
	}

	int peek()
	{
		if(!is_empty())
			return buffer[top];
		cout << "Error: stack empty!\n";
		exit(-2);
	}

	bool is_empty()
	{
		return top == 0;
	}

	int get_top()
	{
		return top;
	}

	int get(int index)
	{
		if(index >=0 && index < size)
			return buffer[index];
		else
		{
			cout << "Invalid index.\n";
			return -1;
		}
	}

	~Stack()
	{
		delete[] buffer;
	}

};


class Tower
{
	Stack* disks;
	int tower_index;

public:
	Tower(int size, int i) : tower_index(i)
	{
		disks = new Stack(size);
	}

	int index()
	{
		return tower_index;
	}

	void add(int d)
	{
		if(!disks->is_empty() && disks->peek() <= d)
			cout << "Error placing disk " << d << endl;
		else
			disks->push(d);
	}

	void move_top_to(Tower* t)
	{
		if(!disks->is_empty())
		{
			int top = disks->pop();
			t->add(top);
			cout << "Move disk " << top << " from " << index()+1 << " to "
		         << t->index()+1 << endl;
		}
		else
			cout << "Cannot move, empty Tower.\n";
	}

	void print()
	{
		cout << "Contents of the Tower " << index() << endl;
		for(int i = disks->get_top(); i > 0; --i)
			cout << disks->get(i) << " ";
		cout << endl;
	}

	void move_disks(int n, Tower* dest, Tower* buf)
	{
		if(n > 0)
		{
			move_disks(n-1, buf, dest);
			move_top_to(dest);
			buf->move_disks(n-1, dest, this);
		}
	}

};


int main()
{
	int n = 5;

	vector<Tower*> towers;

	for(int i = 0; i < 3; ++i)
		towers.push_back(new Tower(10, i));


	for(int i = n; i > 0; --i)
		towers[0]->add(i);

	towers[0]->print();
	towers[0]->move_disks(n, towers[2], towers[1]);
}
