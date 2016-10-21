Linked Lists



How to Approach
---------------

Linked list questions are extremely common. These can range from simple (delete
a node in a linked list) to much more challenging. Either way, we advise you to
be extremely comfortable with the easiest questions. Being able to easily 
manipulate a linked list in the simplist ways will make the tougher linked list
questions much less tricky. With that said, we present some "must know" code 
about linked list manipulation. You should be able to easily write this code 
yourself prior to your interview.


Creating a linked list
----------------------

    ...........................................................................
    NOTE: when you're discussing a linked list in an interview, make sure to 
    understand whether it is a single linked list or a doubly linked list.
    ...........................................................................


    class Node
    {
    	Node next = null;
    	int data;
    	public Node(int d) { data = d; }
    	void appendToTail(int d)
    	{
    		Node end = new Node(d);
    		Node n = this;
    		while(n.next != null) {
    			n = n.next;
    		}
    		n.next = end;
    	}
    }


Deleting a node from a singly linked list
-----------------------------------------


    Node deleteNode(Node head, int d)
    {
    	Node n = head;
    	if(n.data == d)
    	{
    		return head.next; /* moved head */
    	}
    	while(n.next != null)
    	{
    		if(n.next.data == d)
    		{
    			n.next = n.next.next;
    			return head; /* head didn't change */
    		}
    		n = n.next;
    	}
    }


















