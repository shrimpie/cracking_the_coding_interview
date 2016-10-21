// 3.5 Implement a MyQueue class which implements a queue using two stacks.



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

	bool is_full()
	{
		return top == size;
	}

	int get_top()
	{
		return top;
	}

	int get(int index)
	{
		if(index >= 0 && index < size)
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


class MyQueue
{
	Stack* s1;
	Stack* s2;
	int size;
public:
	MyQueue(int s=100) : size(s)
	{
		s1 = new Stack(size);
		s2 = new Stack(size);
	}

	int get_size()
	{
		return s1->get_top() + s2->get_top();
	}

	void enqueue(int val)
	{
		if(!s1->is_full())
		{
			s1->push(val);
			return;
		}
		else
		{
			while(!s1->is_empty() && !s2->is_full())
				s2->push(s1->pop());
			s1->push(val);
		}
	}

	int dequeue()
	{
		if(!s2->is_empty())
			return s2->pop();
		else
		{
			while(!s1->is_empty())
				s2->push(s1->pop());
			return s2->pop();
		}
	}

	int peek()
	{
		if(!s2->is_empty())
			return s2->peek();
		else
		{
			while(!s1->is_empty())
				s2->push(s1->pop());
			return s2->peek();
		}

	}

};

int main()
{
	MyQueue mq;
	mq.enqueue(1);
	mq.enqueue(2);
	mq.enqueue(3);

	cout << mq.peek() << endl;
	cout << mq.dequeue() << endl;
	cout << mq.dequeue() << endl;

	mq.enqueue(4);
	mq.enqueue(5);
	mq.enqueue(6);

	cout << mq.peek() << endl;
	cout << mq.dequeue() << endl;
	cout << mq.dequeue() << endl;

	return 0;
}