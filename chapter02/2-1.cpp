// 2.1 Write code to remove duplicates from an unsorted linked list.
//     Follow up: How would you solve this problem if a temporary buffer is not
//     allowed.


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

	// 2.1
	void delete_duplicates()
	{
		set<int> s;
		Node* pre = head;
		Node* cur = head;
		while(cur != NULL)
		{
			if(s.find(cur->data) != s.end())
			{
				delete pre->next;
				pre->next = cur->next;
			}
			else
			{
				s.insert(cur->data);
				pre = cur;
			}
			cur = cur->next;
		}
	}
	// 2.1
	void delete_duplicates2()
	{
		if(head == NULL)
			return;

		Node* pre = head;
		Node* cur = pre->next;
		while(cur)
		{
			Node* runner = head;
			while(runner != cur)
			{
				if(runner->data == cur->data)
				{
					Node* tmp = cur->next;
					delete pre->next;
					pre->next = tmp;
					cur = tmp;
					break;
				}
				runner = runner->next;
			}
			if(runner == cur) // no duplicates found
			{
				pre = cur;
				cur = cur->next;
			}
		}
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

	for(int i = 0; i < 10; i++)
		l.append(new Node(rand() % 10));

	l.print_list();

	l.delete_duplicates();

	l.print_list();

	for(int i = 0; i < 10; i++)
		l.append(new Node(rand() % 10));

	l.print_list();

	l.delete_duplicates2();

	l.print_list();


	return 0;
}











