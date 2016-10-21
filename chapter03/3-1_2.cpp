// 3.1 Solution 2

#include <iostream>
#include <set>
using namespace std;

struct StackNode
{
	int pre;
	int val;
};


class Stack
{
	int stack_size;
	int* stack_pointer;
	int stack_count;
	StackNode* buffer;
	set<int> free_cell;
public:
	Stack(int size, int count)
	{
		stack_size = size;
		stack_count = count;
		stack_pointer = new int[stack_count];
		for(int i = 0; i < stack_count; ++i)
			stack_pointer[i] = -1;

		for(int i = 0 ; i < stack_size * stack_count; ++i)
			free_cell.insert(i);

		buffer = new StackNode[stack_size * stack_count];
	}

	void push(int stack_index, int val)
	{
		int last_index = stack_pointer[stack_index];
		int index = *(free_cell.begin());
		buffer[index].val = val;
		buffer[index].pre = last_index;
		stack_pointer[stack_index] = index;
		free_cell.erase(index);
	}

	int pop(int stack_index)
	{
		int last_index = stack_pointer[stack_index];
		int val = buffer[last_index].val;
		stack_pointer[stack_index] = buffer[last_index].pre;
		free_cell.insert(last_index);
		return val;
	}

	~Stack()
	{
		delete[] buffer;
		delete[] stack_pointer;
	}

	void print_stack(int stack_index)
	{
		cout << "Stack # " << stack_index << endl;
		int start = stack_pointer[stack_index];
		if(start == -1)
			cout << "The stack is empty.\n";
		else
		{
			cout << "The stack contains: ";
			while(start != -1)
			{
				cout << buffer[start].val << " ";
				start = buffer[start].pre;
			}
			cout << endl;
		}
	}
};

int main()
{
	Stack s(300, 3);

	s.push(0, 4);
	s.push(0, 8);
	s.push(0, 90);
	s.push(0, 20);
	s.print_stack(0);

	s.push(1, 6);
	s.push(1, 40);
	s.push(1, 39);
	s.print_stack(1);


	s.pop(0);
	s.pop(1);
	s.pop(0);
	s.pop(1);
	s.print_stack(0);
	s.print_stack(1);

	return 0;
}