// 3.2 How would you design a stack which, in addition to push and pop, also 
//     has a function min which returns the minimum element? Push, pop and min
//     should all operate in O(1) time.


#include <iostream>
#include <climits>
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

	~Stack()
	{
		delete[] buffer;
	}

};


class MinStack : public Stack
{
	Stack* m;
public:
	MinStack(int size) : Stack(size)
	{
		m = new Stack(size);
	}

	void push(int val)
	{
		Stack::push(val);

		if(val < min())
		{
			m->push(val);
		}
	}

	int pop()
	{
		int val = Stack::pop();
		if(val == min())
		{
			m->pop();
			// cout << "Debuging: m.mim() returns " << min() << endl;
		}
		return val;
	}

	int min()
	{
		if(m->is_empty())
			return INT_MAX;
		else
			return m->peek();
	}
};



int main()
{
	MinStack ms = MinStack(100);

	ms.push(6);
	cout << "ms.min: " << ms.min() << endl;
	ms.push(5);
	cout << "ms.min: " << ms.min() << endl;
	ms.push(4);
	cout << "ms.min: " << ms.min() << endl;
	ms.push(3);
	cout << "ms.min: " << ms.min() << endl;
	ms.push(2);
	cout << "ms.min: " << ms.min() << endl;
	ms.push(1);
	cout << "ms.min: " << ms.min() << endl;

	cout << "Start poping: " << endl;
	ms.pop();
	cout << "ms.min: " << ms.min() << endl;
	ms.pop();
	cout << "ms.min: " << ms.min() << endl;
	ms.pop();
	cout << "ms.min: " << ms.min() << endl;
	ms.pop();
	cout << "ms.min: " << ms.min() << endl;

	return 0;
}






