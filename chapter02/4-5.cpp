// 2.5 Given a circular linked list, implement an algorithm which returns node at the 
//     begining of the loop.
//     Definition:
//     Circular linked list: A (corrupt) linked list in which a node's next pointer
//     points tot an earlier node, so as to make a loop in the linked list.
//    
//     Solution:
//     If we move two pointers, one with speed 1 and another with speed 2, they 
//     will end up meeting if the linked list has a loop. Why? Think about two cars
//     driving on a track -- the faster car will always pass the slower one.
//     The tricky part here is to find the start of the loop. Imagine, as an analogy,
//     two people racing around a track, one running twice as fast as the other. If they
//     start off at the same place, when will they next meet? They will mext meet at the
//     start of the next lap.
//     Now, let's suppose Fast Runner had a head start of k meters on an n step lap.
//     When will they next meet? They will meet k meters before the startof the next lap.
//     (Why? Fast Runner would have made k + 2(n-k) steps, including its head start, and
//     Slow Runner would have made n-k steps. Both will be at k steps before the start of
//     the loop.)
//     Now, going back to the problem, when Fast Runner (n2) and Slow Runner (n1) are moving
//     around our circular linked list, n2 will have a head start on the loop when n1 enters.
//     Specifically, it will have a head start of k, where k is the number of nodes before 
//     the loop. Since n2 has a head start of k nodes, n1 and n2 will meet k nodes before
//     the start of the loop.



#include <iostream>
#include <set>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};


class LinkedList{
public:

	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	void append(Node* node)
	{
		if(head == NULL)
		{
			head = node;
			return;
		}
		else
		{
			Node* p = head;
			while(p)
			{
				if(p->next == NULL)
				{
					p->next = node;
					return;
				}
				p = p->next;
			}
		}
	}

	Node* find_beginning_of_circular_linked_list()
	{
		Node * n1 = head;
		Node * n2 = head;

		while(n2->next)
		{
			n1 = n1->next;
			n2 = n2->next->next;
			if(n1 == n2)
				break;
		}

		if(n2->next == NULL)
			return NULL;

		n1 = head;
		while(n1 != n2)
		{
			n1 = n1->next;
			n2 = n2->next;
		}

		return n2;
	}


	Node* nth_to_last_element(int n)
	{
		if(head == NULL || n < 1)
			return NULL;

		Node* p1 = head;
		Node* p2 = head;

		for(int i=0; i<n; i++)
		{
			if(p2 == NULL)
				return NULL;
			p2 = p2->next;
		}
		while(p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}


	void print_list()
	{
		cout << "The list contains: ";
		Node* n = head;
		while(n != NULL)
		{
			cout << n->data << " ";
			n = n->next;
		}
		cout << endl;
	}

	~LinkedList()
	{
		Node* tmp = head;
		while(tmp)
		{
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
	}

};


int main()
{
	// Create a circular linked list
	LinkedList l;
	for(int i = 0; i < 11; i++)
		l.append(new Node(i));

	Node* tail = l.nth_to_last_element(1);
	Node* n3 = l.nth_to_last_element(8);
	tail->next = n3;

	cout << "Expect: 3 " << endl;

	Node* begin = l.find_beginning_of_circular_linked_list();
	cout << "Get: " << begin->data << endl;

	// Restore the null pointer.
	tail->next = NULL;

	return 0;
}









