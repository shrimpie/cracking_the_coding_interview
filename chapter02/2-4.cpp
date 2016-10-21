// 2.4 You have two numbers represented by a linked list, where each node contains
//     a single digit. The digits are stored in reverse order, such that the 1's
//     digit is at the head of the list. Write a function that adds the two numbers
//     and returns the sum as a linked list.


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

	void add_front(Node* n)
	{
		if(head != NULL)
			n->next = head;
		head = n;
	}

	LinkedList* add_list(LinkedList* l2)
	{
		if(head == NULL && l2->head == NULL)
			return NULL;
		else if (head == NULL)
			return l2;
		else if(l2->head == NULL)
			return this;

		LinkedList* result = new LinkedList();
		Node* p1 = head;
		Node* p2 = l2->head;

		int carry = 0;
		while(p1 || p2)
		{
			int value = 0;
			value += carry;
			value += (!p1 ? 0 : p1->data) + (!p2 ? 0 : p2->data);
			// cout << "value: " << value << endl;
			Node* tmp = new Node(value % 10);
			carry = (value >= 10 ? 1 : 0);
			// cout << "carry: " << carry << endl;

			result->append(tmp);

			if(p1) p1 = p1->next;
			if(p2) p2 = p2->next;
		}

		return result;
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
	LinkedList l1;
	l1.add_front(new Node(5));
	l1.add_front(new Node(1));
	l1.add_front(new Node(3));
	l1.print_list();

	LinkedList l2;
	l2.add_front(new Node(2));
	l2.add_front(new Node(9));
	l2.add_front(new Node(5));
	l2.print_list();

	LinkedList* l5 = l1.add_list(&l2);
	l5->print_list();

	LinkedList l4;
	l4.add_front(new Node(4));
	l4.add_front(new Node(7));
	l4.print_list();

	LinkedList* l3 = l1.add_list(&l4);
	l3->print_list();


	return 0;
}
