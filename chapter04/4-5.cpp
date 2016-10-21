// 4.5 Write an algorithm to find the next node (eg, in-order successor) of a 
//     given node in a binary search tree where each node has link to its 
//     parent.

//     Idea:
//     If we want to find the successor of node X:
//     1. If X has a right child, then the successor must be on the right side
//        of the X (because of the order in which we visit nodes). Specifically
//        , the left-most child must be the first node visited in the subtree.
//     2. Else, we go to X's parent (call it P).
//     3. If X was a left child, then P is the successor of X.
//     4. If X was a right child, then we have fully visited P, we call 
//        successor(P).
//     Question here:
//     It's not actually suggesting recursion. For the case of which X was a right
//     child, its successor is its first left-child-parent.


// 4.6 Design an algorithm and write code to find the first common ancestor of two
//     nodes in a binary tree. Avoid storing additional nodes in a data structure.
//     Note: This is not necessarily a binary search tree.

//     Idea:
//     1. If the tree is a binary search tree, we could do a modified find
//        on the two nodes and see where the paths diverge.
//     2. If each node has a link to its parent, we could trace p and q's paths up
//        until they intersect.
//     3. 

// 4.7 You have two very large binary trees: T1, with millions of nodes, and T2,
//     with hundreds of nodes. Create an algorithm to decide if T2 is a subtree
//     of T1.

// 4.8 You are given a binary tree in which each node contains a value. Design an
//     algorithm to print all paths which sum up to that value. Note that it can
//     be any path in the tree - it does not have to start at the root.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int TWO_NODES_FOUND = 2;
const int ONE_NODE_FOUND = 1;
const int NO_NODES_FOUND = 0;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	TreeNode(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

class Tree
{
	TreeNode * root;

	void add_node(int v, TreeNode* n)
	{
		if(v <= n->value)
		{
			if(n->left)
				add_node(v, n->left);
			else
			{
				TreeNode* leaf = new TreeNode(v);
				n->left = leaf;
				leaf->parent = n;
			}
		}
		else
		{
			if(n->right)
				add_node(v, n->right);
			else
			{
				TreeNode* leaf = new TreeNode(v);
				n->right = leaf;
				leaf->parent = n;
			}
		}
	}


public:

	Tree() : root(NULL)
	{
	}

	void add_node(int v)
	{
		if(!root)
			root = new TreeNode(v);
		else
			add_node(v, root);
	}

	TreeNode* get_root()
	{
		return root;
	}


	TreeNode* find(int val, TreeNode* start)
	{
		if(!start)
			return NULL;
		if(val == start->value)
			return start;
		else if(val < start->value)
			return find(val, start->left);
		else
			return find(val, start->right);
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

	// 4.5 
	TreeNode* inorder_successor(TreeNode* n)
	{
		if(n)
		{
			if(!n->parent || n->right)
			{
				n = n->right;

				if(!n) return NULL;
				while(n->left)
					n = n->left;
				return n;
			}
			else
			{
				TreeNode* p;
				while((p = n->parent))
				{
					if(p->left == n)
						break;
					n = p;
				}
				return p;
			}
		}
		return NULL;
	}

	// 4.6 
	// Checks how many "special" nodes are located under this root.
	int covers(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		int ret = NO_NODES_FOUND;
		if(!root) return ret;
		if(root == p || root == q) ret += 1;
		ret += covers(root->left, p, q);
		if(ret == TWO_NODES_FOUND)
			return ret;
		return ret + covers(root->right, p, q);
	}

	// 4.6
	TreeNode* common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(p == q && (root->left == q || root->right == q))
			return root;

		int nodes_from_left = covers(root->left, p, q);
		if(nodes_from_left == TWO_NODES_FOUND)
		{
			if(root->left == p || root->right == q)
				return root->left;
			else
				return common_ancestor(root->left, p, q);
		}
		else if(nodes_from_left == ONE_NODE_FOUND)
		{
			if(root == p) return p;
			else if(root == q) return q;
		}

		int nodes_from_right = covers(root->right, p, q);
		if(nodes_from_right == TWO_NODES_FOUND)
		{
			if(root->right == p || root->right == q)
				return root->right;
			else
				return common_ancestor(root->right, p, q);
		}
		else if (nodes_from_right == ONE_NODE_FOUND)
		{
			if(root == p) return p;
			else if(root == q) return q;
		}

		if(nodes_from_left == ONE_NODE_FOUND && 
			nodes_from_right == ONE_NODE_FOUND)
			return root;
		else
			return NULL;
	}


	// 4.7
	bool contains_tree(TreeNode* t1, TreeNode* t2)
	{
		if(!t2) return true; // The empty tree is always a subtree
		else return sub_tree(t1, t2);
	}

	// 4.7
	bool sub_tree(TreeNode* r1, TreeNode* r2)
	{
		if(!r1) return false; // big tree empty & subtree still not found
		if(r1->value == r2->value)
		{
			if(match_tree(r1, r2))
				return true;
		}
		return (sub_tree(r1->left, r2) || sub_tree(r1->right, r2));
	}

	// 4.7
	bool match_tree(TreeNode* r1, TreeNode* r2)
	{
		if(!r2 && !r1) return true;
		// nothing left in the subtree

		if(!r1 || !r2) return false;
		// big tree empty & subtree still not found

		if(r1->value != r2->value) return false; // data doesn't match
		return (match_tree(r1->left, r2->left) && 
				match_tree(r1->right, r2->right));
	}


	// 4.8
	void find_sum(TreeNode* head, int sum, vector<int> buffer, int level)
	{
		if(!head) return;
		int tmp = sum;
		buffer.push_back(head->value);
		for(int i = level; i >= 0; --i)
		{
			tmp -= buffer[i];
			if(tmp == 0)
				print_path(buffer, i, level);
		}
		vector<int> c1(buffer);
		vector<int> c2(buffer);

		find_sum(head->left, sum, c1, level+1);
		find_sum(head->right, sum, c1, level+1);
	}

	void print_path(vector<int> buffer, int level, int i2)
	{
		for(int i = level; i <= i2; ++i)
			cout << buffer[i] << " ";
		cout << endl;
	}

};


int main()
{
	int values[] = {4, 6, 1, 3, 5, 9, 7, 8, 2, 0};
	Tree t;
	for(int i = 0; i < 10; ++i)
		t.add_node(values[i]);

	t.inorder_traverse(t.get_root());
	cout << endl;

	// parent tests.
	for(int i=0; i < 10; ++i)
	{
		TreeNode* res = t.find(i, t.get_root());
		if(res->parent)
			cout << i << "'s parent is " << res->parent->value << endl;
		else
			cout << i << " has no parent.\n";
	}

	// successor tests.
	for(int i = 0; i < 10; ++i)
	{
		TreeNode* node = t.find(i, t.get_root());
		TreeNode* succ = t.inorder_successor(node);
		if(succ)
			cout << i << "'s successor is " << succ->value << endl;
		else
			cout << i << " has no successor.\n";
	}

	// covers test
	TreeNode* p = t.find(5, t.get_root());
	TreeNode* q = t.find(3, t.get_root());
	TreeNode* r = t.find(1, t.get_root());
	TreeNode* s = t.find(0, t.get_root());

	cout << "p value: " << p->value << endl;
	cout << "q value: " << p->value << endl;
	cout << "r value: " << r->value << endl;
	cout << "s value: " << s->value << endl;

	cout << t.covers(t.get_root(), p, q) << endl;
	cout << t.covers(r, p, q) << endl;
	cout << t.covers(s, p, q) << endl;

	cout << "Ancestor of 5 and 3: " 
		<< (t.common_ancestor(t.get_root(), p, q)->value) << endl;
	cout << "Ancestor of 5 and 1: " 
		<< (t.common_ancestor(t.get_root(), p, r)->value) << endl;
	cout << "Ancestor of 1 and 0: " 
		<< (t.common_ancestor(t.get_root(), r, s)->value) << endl;


	cout << "Root contains subtree 5: " << 
			(t.contains_tree(t.get_root(), p) ? "True" : "False") << endl;
	cout << "Root contains subtree 3: " << 
			(t.contains_tree(t.get_root(), q) ? "True" : "False") << endl;

	cout << "Root contains subtree 1: " << 
			(t.contains_tree(t.get_root(), r) ? "True" : "False") << endl;

	cout << "Root contains subtree 0: " << 
			(t.contains_tree(t.get_root(), s) ? "True" : "False") << endl;

	cout << "subtree 5 contains subtree 1: " << 
			(t.contains_tree(p, r) ? "True" : "False") << endl;


	vector<int> buffer;
	t.find_sum(t.get_root(), 10, buffer, 0);

	return 0;
}