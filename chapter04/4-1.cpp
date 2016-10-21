// 4.1 Implement a function to check if a tree is balanced. For the purposes 
//     of this question, a balanced tree is defined to be a tree such that no 
//     two leaf nodes differ in distance from the root by more than one.

//     Idea:
//     The idea is very simple: the difference of min depth and max depth 
//     should not exceed 1, since the difference of the min and max depth is 
//     the maximum distance difference possible in the tree.

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
	TreeNode* root;

	void add_node(int v, TreeNode* n)
	{
		if(v <= n->value)
		{
			if(n->left)
				add_node(v, n->left);
			else
				n->left = new TreeNode(v);
		}
		else
		{
			if(n->right)
				add_node(v, n->right);
			else
				n->right = new TreeNode(v);
		}

	}

public:

	Tree() : root(NULL)
	{
	}

	TreeNode* get_root()
	{
		return root;
	}

	// This one iteratively finds the position to insert node.
	// But not so elegant.
	void add_node(int v)
	{
		// If the first node, 
		if(!root)
			root = new TreeNode(v);
		else
		{
			TreeNode* tmp = root;

			while(tmp->left || tmp->right)
			{
				if(v < tmp->value)
				{
					if(tmp->left)
						tmp = tmp->left;
					else break;
				}
				else if(v >= tmp->value)
				{
					if(tmp->right)
						tmp = tmp->right;
					else break;
				} 
			}
			// cout << "tmp: " << tmp << endl;
			// cout << "tmp value: " << tmp->value << endl;

			if(tmp && v < tmp->value && tmp->left == NULL)
			{
				// cout << "Insert left.\n";
				tmp->left = new TreeNode(v);

			}
			else if(tmp && v >= tmp->value && tmp->right == NULL)
			{
				// cout << "Insert right.\n";
				tmp->right = new TreeNode(v);
			}
		}
	}

	void add_node2(int v)
	{
		if(!root)
			root = new TreeNode(v);
		else
			add_node(v, root);
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

	~Tree()
	{
		free_node(root);
	}

	void free_node(TreeNode* leaf)
	{
		if(leaf)
		{
			free_node(leaf->left);
			free_node(leaf->right);
			delete leaf;
		}
	}

	int max_depth(TreeNode* root)
	{
		if(!root)
			return 0;
		return 1 + max(max_depth(root->left), max_depth(root->right));
	}

	int min_depth(TreeNode* root)
	{
		if(!root)
			return 0;
		return 1 + min(min_depth(root->left), min_depth(root->right));
	}

	bool is_balanced()
	{
		return (max_depth(root) - min_depth(root) <= 1);
	}

};


int main()
{
	Tree t;
	int values[] = {12, 9, 20, 11, 7, 13, 26};

	for(int i = 0 ; i < sizeof(values) / sizeof(values[0]); ++i)
		t.add_node2(values[i]);

	cout << "Inorder traverse: ";
	t.inorder_traverse(t.get_root());
	cout << endl;


	cout << "The tree is balanced? " << (t.is_balanced()? "True" : "False") << endl;

	return 0;
}















