// 20.9 Numbers are randomly generated and passed to a method. Write a program 
//      to find and maintain the median value as new values are generated.


// Idea: interesting one.
// One solution is to use two priority heaps: a max heap for the values below
// the median, and a min heap for the values above the median. The median will 
// be the largest value of the max heap. When a new value arrives it is placed 
// in the below heap if the value is less than or equal to the median, 
// otherwise it is placed into the above heap. The heap sizes can be equal or 
// the below heap has one extra. This constraint can easily be restored by 
// shifting an element from one heap to the other. The median is available in 
// constant time, so updates are O(logn).

#include <iostream>
#include <functional>
#include <queue>


class GetMedian
{
	std::priority_queue<int>* max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int> >* min_heap;

public:

	GetMedian()
	{
		max_heap = new std::priority_queue<int>();
		min_heap = new 
			std::priority_queue<int, std::vector<int>, std::greater<int> >();
	}

	void add_new_number(int num)
	{
		if(min_heap->size() == max_heap->size())
		{
			if(!min_heap->empty() && num > min_heap->top())
			{
				max_heap->push(min_heap->top());
				min_heap->pop();
				min_heap->push(num);
			}
			else
				max_heap->push(num);
		}
		else
		{
			if(num < max_heap->top())
			{
				min_heap->push(max_heap->top());
				max_heap->pop();
				max_heap->push(num);
			}
			else
				min_heap->push(num);
		}
	}

	int get_median()
	{
		if(max_heap->empty())
			return min_heap->top();
		else if(min_heap->empty())
			return max_heap->top();
		if(max_heap->size() == min_heap->size())
			return (min_heap->top() + max_heap->top())/2;
		else if(max_heap->size() > min_heap->size())
			return max_heap->top();
		else
			return min_heap->top();
	}
};






int main()
{
	GetMedian gm;

	srand(time(NULL));
	for(int i = 0; i < 11; ++i)
	{
		int value = rand() % 10;
		gm.add_new_number(value);
		std::cout << value << " ";
	}
	std::cout << std::endl;

	std::cout << gm.get_median() << std::endl;

	return 0;
}










