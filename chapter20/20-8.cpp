// 20.8 Given a string s and an array of smaller strings T, design a method to 
//      search s for each small string in T.

// Idea:
/*
// First, create a suffix tree for s. For example, if your word were bibs, you 
// would create the following tree:
//                       +
//                      /|\
//                     B I S
//                    /\ \ 
//                   I  S B
//                  /      \
//                 B        S
//                /
//               S
*/
// Then, all you need to do is search for each string in T in the suffix tree.
// Note that if "B" were a word, you would come up with two locations.

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class SuffixTreeNode
{
	map<char, SuffixTreeNode*>* children; // to record each branch
	char value;           // store each char met, temporarily usage
	vector<int>* indexes; // to record which index pass through this branch

public:
	SuffixTreeNode()
	{
		children = new map<char, SuffixTreeNode*>();
		indexes = new vector<int>();
	}

	void insert_str(string s, int index)
	{
		indexes->push_back(index);
		if(s.size() > 0)
		{
			value = s[0];
			SuffixTreeNode* child = NULL;
			if(children->find(value) != children->end())
				child = children->at(value); // branch to met chars
			else
			{
				child = new SuffixTreeNode();
				children->insert(pair<char, SuffixTreeNode*>(value, child));
				// Add new node and pointing to child
			}
			string remain = s.substr(1);
			child->insert_str(remain, index);
		}
	}

	vector<int>* get_indexes(string s)
	{
		if(s.size() == 0)
			return indexes;
		else
		{
			char first = s[0];
			if(children->find(first) != children->end())
			{
				string remain = s.substr(1);
				return children->at(first)->get_indexes(remain);
			}
		}

		return NULL;
	}

	// Test use
	void print_indexes()
	{
		cout << "indexes: ";
		for(int i = 0; i < indexes->size(); ++i)
			cout << (*indexes)[i] << " ";
		cout << endl;
	}

	// Test use
	void print_children()
	{
		for (const auto &p : (*children))
		{
		    std::cout << "children[" << p.first << "] = " 
		    << (p.second)->value << '\n';
		}
	}

};

class SuffixTree
{
	SuffixTreeNode* root;

public:
	SuffixTree(string s)
	{
		root = new SuffixTreeNode();
		for(int i = 0; i < s.size(); ++i)
		{
			string suffix = s.substr(i);
			cout << "Suffix: " << suffix << endl;
			cout << "Index: " << i << endl;
			root->insert_str(suffix, i);
		}
	}

	vector<int>* get_indexes(string s)
	{
		return root->get_indexes(s);
	}
};


int main()
{
	// string test_str = "mississippi";
	// string string_list[] = { "is", "sip", "hi", "sis" };
	string test_str = "bibs";
	string string_list[] = { "b", "ib", "bs" };
	SuffixTree* tree = new SuffixTree(test_str);

	for(auto s : string_list)
	{
		vector<int>* list = tree->get_indexes(s);
		if(list != NULL)
		{
			cout << s << ": ";
			for(int i = 0; i < list->size(); ++i)
				cout << (*list)[i] << " ";
			cout << endl;
		}
	}

	return 0;
}















