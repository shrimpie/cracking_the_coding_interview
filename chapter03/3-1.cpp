// 3.1 Describe how you would use a single array to implement three stacks.

#include <iostream>
using namespace std;


class Stack {

	int stack_size;
	int* buffer;
	int* stack_pointer;
	int stack_count;
public:

	Stack(int size, int count)
	{
		stack_size = size;
		stack_count = count;
		buffer = new int[stack_size * stack_count];
		stack_pointer = new int[stack_count];
		for(int i = 0; i < stack_count; ++i)
			stack_pointer[i] = i * stack_size;
	}

	void push(int stack_index, int val)
	{
		// Find the index of the top element in the array,

		// You forget to check if current stack is full?
		int index = stack_pointer[stack_index] + 1;
		buffer[index] = val;
		++stack_pointer[stack_index];

	}

	int pop(int stack_index)
	{
		if(!is_empty(stack_index))
		{
			int index = stack_pointer[stack_index];
			int value = buffer[index];
			--stack_pointer[stack_index];
			buffer[index] = 0; // This is not necessary, I guess.
			return value;
		}
		cout << "Error: the stack is empty!" << endl;
		exit(-1);
	}

	int peek(int stack_index)
	{
		if(!is_empty(stack_index))
		{
			int index = stack_pointer[stack_index];
			return buffer[index];
		}
		cout << "Error: stack " << stack_index << " is empty!" << endl;
		return -1;
	}


	bool is_empty(int stack_index)
	{
		return stack_pointer[stack_index] == stack_index * stack_size;
	}

	void print_stack(int stack_index)
	{
		if(!is_empty(stack_index))
		{
			cout << "Stack " << stack_index << " contains: ";
			for(int i = stack_pointer[stack_index]; 
				i != stack_index * stack_size; --i)
				cout << buffer[i] << " ";
			cout << endl;
			return;
		}
		cout << "Error: stack " << stack_index << " is empty!" << endl;
		return;
	}

};


int main()
{
	Stack s(300, 3);

	s.push(0, 19);
	s.push(0, 38);
	s.print_stack(0);
	s.pop(0);
	s.print_stack(0);

	cout << "----------" << endl;

	s.push(1, 20);
	s.print_stack(1);
	s.pop(1);
	s.print_stack(1);

	cout << "----------" << endl;
	s.push(2, 58);
	s.print_stack(2);


	return 0;
}







