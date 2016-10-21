// 2.3 Implement an algorithm to delete a node in the middle of a single linked
//     list, given only access to that node.



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

	
	// Simply copy the next element's data into this middle one, and return true.
	// If the list has less than two elements, return false.
	bool delete_middle_element(Node* n)
	{
		if(n == NULL || n->next == NULL)
			return false;

		Node* next = n->next;
		n->data = next->data;
		n->next = next->next;
		delete next;
		return true;
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


	LinkedList l;
	srand(time(NULL));

	for(int i = 0; i <= 10; i++)
		l.append(new Node(rand() % 10));

	l.print_list();

	Node* mid = l.nth_to_last_element(6);
	cout << mid->data << endl;

	l.delete_middle_element(mid);

	l.print_list();


	return 0;
}










