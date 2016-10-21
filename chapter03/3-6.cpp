// 3.6 Write a program to sort a stack in ascending order. You should not make 
//     any assumptions about how the stack is implemented. The following are 
//     the only functions that should be used to write this program: push, pop,
//     peek, is_empty.

#include <iostream>
#include <stack>

using namespace std;

stack<int>* sort(stack<int>* ori)
{
	stack<int>* res = new stack<int>();

	while(!ori->empty())
	{
		int tmp = ori->top();
		ori->pop();
		while(!res->empty() && res->top() > tmp)
		{
			ori->push(res->top());
			res->pop();
		}
		res->push(tmp);
	}
	return res;
}



int main()
{
	stack<int> s;
	s.push(9);
	s.push(4);
	s.push(2);
	s.push(5);

	stack<int>* res = sort(&s);

	while(!res->empty())
	{
		cout << res->top() << " ";
		res->pop();
	}
	cout << endl;

	return 0;
}
















