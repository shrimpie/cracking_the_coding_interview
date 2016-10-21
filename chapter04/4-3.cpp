// 4.3 Given a sorted (increasing order) array, write an algorithm to create a 
//     binary tree with minimum hegiht.

// Solution:

// We will try to create a binary tree such that for each node, the number of 
// nodes in the lft subtree and the right subtree are equal, if possible.

// Algorithm:
// 1. Insert into the tree the middle element of the array.
// 2. Insert (into the left subtree) the left subarray elements.
// 3. Insert (into the right subtree) the right subarray elements.
// 4. Recurse.



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

	TreeNode* add_to_tree(vector<int> values, int start, int end)
	{
		if(end < start)
			return NULL;
		int mid = (start + end) / 2;
		TreeNode* node = new TreeNode(values[mid]);
		// recurse: assign left node the left tree
		node->left = add_to_tree(values, start, mid-1);
		// recurse: assign right node the right tree
		node->right = add_to_tree(values, mid+1, end);
		return node;
	}

	void create_minimum_height_tree(vector<int> values)
	{
		root = add_to_tree(values, 0, values.size()-1);
	}

};


int main()
{
	vector<int> vs;
	for(int i = 0; i < 10; ++i)
		vs.push_back(i);

	Tree t;
	t.create_minimum_height_tree(vs);
	t.inorder_traverse(t.get_root());
	cout << endl;

	return 0;
}