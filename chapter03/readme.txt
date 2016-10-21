Stacks and Queues

How to Approach
---------------


Whether you are asked to implement a simple stack / queue, or you are asked to 
implement a modified version of one, you will have a big leg up on other 
candidates if you can flawlessly work with stacks and queues. Practice makes 
perfect! Here is some skeleton code for a Stack and Queue class.


Implementing a Stack
--------------------


    class Stack
    {
    	Node top;
    	Node pop()
    	{
    		if(top != null)
    		{
    			Object item = top.data;
    			top = top.next;
    			return item;
    		}
    		return null;
    	}
    	void push(Object item)
    	{
    		Node t = new Node(item);
    		t.next = top;
    		top = t;
    	}
    }


Implementing a Queue
--------------------

    class Queue
    {
    	Node first, last;
    	void enqueue(Object item)
    	{
    		if(!first)
    		{
    			last = new Node(item);
    			first = last;
    		}
    		else
    		{
    			last.next = new Node(item);
    			last = last.next;
    		}
    	}
    	Node dequeue(Node n)
    	{
    		if(front != null)
    		{
    			Object item = front.data;
    			front = front.next;
    			return item;
    		}
    		return null;
    	}
    }











