// 4.4 Given a binary tree, design an algorithm which creates a linked list of 
//     all the nodes at each depth (eg, if you have a tree with depth D, you'll
//     have D linked list).

// Idea:

// Level traversal, with a slight modification of the breadth-frist traversal.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
	TreeNode * root;

public:

	Tree() : root(NULL)
	{
	}

	TreeNode* get_root()
	{
		return root;
	}

	void inorder_traverse(TreeNode* root)
	{
		if(root)
		{
			inorder_traverse(root->left);
			cout << root->value << " ";
			inorder_traverse(root->right);
		}
	}

	// Add nodes from a sorted list of values.
	TreeNode* add_to_tree(vector<int> values, int start, int end)
	{
		if(end < start)
			return NULL;
		int mid = (start + end) / 2;
		TreeNode* node = new TreeNode(values[mid]);
		node->left = add_to_tree(values, start, mid-1);
		node->right = add_to_tree(values, mid+1, end);
		return node;
	}

	void create_minimum_height_tree(vector<int> values)
	{
		root = add_to_tree(values, 0, values.size()-1);
	}

	vector<vector<TreeNode*>* >* find_level_linked_list()
	{
		if (root == NULL)
			return NULL;

		int level = 0;
		vector<vector<TreeNode*> *>* result = 
			new vector<vector<TreeNode*>* >();

		vector<TreeNode*>* list = new vector<TreeNode*>();
		list->push_back(root);
		result->push_back(list);

		while(true)
		{
			list = new vector<TreeNode*>();
			int size = (*result)[level]->size();
			// cout << "level size: " << size << endl;
			for(int i = 0; i < size; ++i)
			{
				TreeNode* n = (*(*result)[level])[i];
				// cout << "n->value: " << n->value << endl;
				if(n)
				{
					if(n->left)
						list->push_back(n->left);
					if(n->right)
						list->push_back(n->right);
				}
			}
			if(list->size() > 0)
				result->push_back(list);
			else
				break;
			++level;
		}
		return result;
	}

};


int main()
{
	vector<int> vs;
	for(int i=0; i<10; ++i)
		vs.push_back(i);

	Tree t;
	t.create_minimum_height_tree(vs);
	t.inorder_traverse(t.get_root());
	cout << endl;

	auto result = t.find_level_linked_list();
	int count = 0;
	for(auto i : *result)
	{
		++count;
		cout << "level " << count << ": ";
		for(auto j : *i)
			cout << j->value << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}