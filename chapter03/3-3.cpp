// 3.3 Imagine a (literal) stack of plates. If the stack gets too high, it 
//     might topple. Therefore, in real life, we would likely start a new 
//     stack when the previous stack exceeds some threshold. Implement a data 
//     structure SetOfStacks that minics this. SetOfStacks should be composed 
//     of several stacks, and should create a new stack once the previous one 
//     exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should 
//     behave identically to a single stack (that is, pop() should return the 
//     same values as it would if there were just a single stack).
//     FOLLOW UP
//     Implement a function popAt(int index) which performs a pop operation on a
//     specific substack.


#include <iostream>
using namespace std;

#include <vector>

struct Node
{
	int value;
	Node* above;
	Node* below;

	Node(int v)
	{
		value = v;
		above = NULL;
		below = NULL;
	}
};


class Stack
{
	int capacity;

public:
	int size;
	Node* top;
	Node* bottom;

	Stack(int cap) : capacity(cap), size(0), top(NULL), bottom(NULL)
	{
	}

	bool is_full()
	{
		return capacity == size;
	}

	// If add new item, set proper pointers.
	void join(Node* a, Node* b)
	{
		if(b) b->above = a;
		if(a) a->below = b;
	}

	void debug_top_bottom()
	{
		cout << "\n++++++++++++++++ Start +++++++++++++++\n";

		if(top)
		{
			cout << "top->value: " << top->value << endl;
			cout << "top->below: " << top->below << endl;
			cout << "top->above: " << top->above << endl;
		}
		else
			cout << "top is NULL.\n";

		if(bottom)
		{
			cout << "bottom->value: " << bottom->value << endl;
			cout << "bottom->below: " << bottom->below << endl;
			cout << "bottom->above: " << bottom->above << endl;
		}
		else
			cout << "bottom is NULL.\n";

		cout << "++++++++++++++++ End +++++++++++++++++\n";
	}

	// When push new item, 
	bool push(int v)
	{
		if(size >= capacity)
			return false;
		++size;
		Node * n = new Node(v);
		if(size == 1) bottom = n;
		n->below = top;
		if(top) top->above = n;
		top = n;
		return true;
	}

	int pop()
	{
		if(size > 0)
		{
			Node* t = top;
			int value = t->value;
			top = top->below;
			delete t;
			--size;
			return value;
		}
		else
		{
			cout << "Stack empty.\n";
			return -1;
		}
	}

	bool is_empty()
	{
		return size == 0;
	}

	int remove_bottom()
	{
		if(!is_empty())
		{
			Node* b = bottom;
			bottom = b->above;
			if(bottom)
				bottom->below = NULL;
			--size;
			return b->value;
		}
		cout << "Stack empty.\n";
		return -1;
	}
};



class SetOfStacks
{
	vector<Stack*> stacks;

public:
	int capacity;

	SetOfStacks(int cap) : capacity(cap)
	{
	}

	Stack* get_last_stack()
	{
		if(stacks.size() == 0)
			return NULL;
		return stacks[stacks.size()-1];
	}

	void push(int val)
	{
		Stack* last = get_last_stack();
		if(last != NULL && !last->is_full())
			last->push(val);
		else
		{
			Stack* stack = new Stack(capacity);
			stack->push(val);
			stacks.push_back(stack);
		}
	}

	int pop()
	{
		Stack* last = get_last_stack();
		if(last != NULL && !last->is_empty())
		{
			int v = last->pop();
			if(last->size == 0)
				stacks.pop_back();
			return v;
		}
		else
		{
			cout << "Stack empty!\n";
			return -1;
		}
	}

	int pop_at(int stack_index)
	{
		return left_shift(stack_index, true);
	}

	// For the first time, remove the top of the indexed stack.
	// For remaining stacks, remove the bottom and push it to former one.
	// This makes former poped stack's size remain correct.
	int left_shift(int index, bool remove_top)
	{
		if(index >= 0 && index < stacks.size())
		{
			Stack* stack = stacks[index];

			int removed_item;
			if(remove_top)
				removed_item = stack->pop();
			else
				removed_item = stack->remove_bottom();
			if(stack->is_empty())
				stacks.erase(stacks.begin() + index);
			else if(stacks.size() > index + 1)
			{
				int v = left_shift(index+1, false);
				stack->push(v);
			}

			return removed_item;
		}
		else
		{
			cout << "Invalid stack index.\n";
			return -1;
		}
	}
};



int main()
{
	// Stack s(100);

	// s.push(1);
	// s.push(2);
	// s.push(3);
	// cout << s.pop() << endl;
	// s.push(4);
	// cout << s.pop() << endl;
	// s.push(5);
	// s.push(6);
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << "bottom: " << s.remove_bottom() << endl;
	// cout << "bottom: " << s.remove_bottom() << endl;

	// cout << "stack is empty: " << (s.is_empty() ? "True" : "False") << endl;

	SetOfStacks ss(10);

	for(int i = 0; i < 15; i++)
		ss.push(i);
	// cout << ss.pop() << endl;
	// cout << ss.pop() << endl;
	cout << ss.pop_at(0) << endl;
	cout << ss.pop_at(0) << endl;

	for(int i = 0; i < 15; i++)
		cout << ss.pop() << " ";
	cout << endl;

	return 0;
}



