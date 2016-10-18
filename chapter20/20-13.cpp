// 20.13 Given a dictionary of millions of words, give an algorithm to find the
//       the largest possible rectangle of letters such that each every row 
//       forms a word (reading left to right) and every column forms a word (
//       reading top to bottom).

// Idea:
// Many problems involving a dictionary can be solved by doing some 
// preprocessing. Where can we do preprocessing?
// Well, if we're going to create a rectangle of words, we know that each row 
// must be the same length and each column must have the same length. So, let's
// group the words of the dictionary based on their sizes. Let's call this 
// grouping D, where D[i] provides a list of words of length i.

// Next, observe that we're looking for the largest rectangle. What is the 
// absolute rectangle that could be formed? It's (length of largest word) * (
// length of largest word).

// int max_rectangle = longest_word * longest_word;
// for z = max_rectangle to 1 
// {
//     for each pair of numbers (i,j) where i*j = z
//     {
//          /* attempt to make rectangle. Return if successful. */
//     }
// }

// By iterating in this order, we ensure that the first rectangle we find will
// be the largest.

// Now, for the hard part: make_rectangle. Our approach is to rearrange words
// in list1 into rows and check if the columns are valid words in list2. 
// However, instead of creating, say, a particular 10x20 rectangle, we check if
// the columns created after inserting the first two words are even valid 
// pre-fixes. A trie becomes handy here.

// The code is omitted here.

// As an exercise, implement a trie.

// Trie is an efficient information retrieval data structure. Using trie, 
// search complexities can be brought to optimal limit (key limit). 

// Every node of trie consists of multiple branches. Each branch represents a 
// possible character of keys. We need to mark the last node of every key as 
// leaf node. A trie node field value will be used to distinguish the node as 
// leaf node (there are other uses of the value field). A simple structure to 
// represent nodes of English alphabet can be as following.

// Trie node
// struct TrieNode
// {
//     struct TrieNode * children[ALPHABET_SIZE];
//     // is_leaf is true if the node represents
//     // end of a word
//     bool isLeaf;
// }

// Inserting a key into trie is simple. Every character of input key is 
// inserted as an individual trie node. Note that the children is an array of 
// pointers to next level trie nodes. The key character acts as an index into
// the array children. If the input key is new or an extension of existing key,
// we need to construct non-existing nodes of the key, and mark leaf node. If 
// the input key is prefix of existing key in trie, we simply mark the last 
// node of key as leaf. The key length determines trie depth.

// Searching for a key is similar to insert operation, however we only compare 
// the characters and move down. The search can terminate due to end of string 
// or lack of key in trie. In the former case, if the value field of last node 
// is non-zero then the key exists in trie. In the second case, the search 
// terminates without examining all the characters of key, since the key is not
// present in trie.

// The following picture explains construction of trie using keys given in the 
// example below.
//        root
//       /  \   \
//      t   a    b
//      |   |    |
//      h   n    y
//      |   | \  |
//      e   s  y e
//     /|   |
//    i r   w
//    | |   |
//    r e   e
//          |
//          r
// 
// In the picture, every character is of type trie_node_t. For example, the 
// root is of type trie_node_t, and it children a, b, and t are filled, all 
// other nodes of root will be NULL. Similarly, "a" at the next level is 
// having only one child("n"), all other children are NULL.

// Insert and search costs O(key_length), however the memory requirements of 
// trie is O(ALPHABET_SIZE * key_length * N) where N is the number of keys in
// trie. There are efficient representation of trie ndoes (e.g., compressed 
// trie, ternary search tree, etc.) to minimize memory requirements of trie.



#include <iostream>
#include <vector>

using namespace std;


#define ALPHABET_SIZE 26

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


class Trie
{
	struct TrieNode
	{
		vector<TrieNode*>* children;
		// is_leaf is true if the node represents end of a word
		bool is_leaf;

		TrieNode()
		{
			is_leaf = false;
			children = new vector<TrieNode*>();
			for(int i = 0; i < ALPHABET_SIZE; ++i)
				children->push_back(NULL);
		}
	};

	TrieNode* root;

public:

	Trie()
	{
		root = new TrieNode();
	}

	void insert(string key)
	{
		int length = key.size();
		TrieNode* pn = root;
		int index = 0;

		for(int level = 0; level < length; ++level)
		{
			index = CHAR_TO_INDEX(key[level]);
			if(!(*pn->children)[index])
				(*pn->children)[index] = new TrieNode();
			pn = (*pn->children)[index];
		}
		// Mark last node as leaf
		pn->is_leaf = true;
	}

	bool search(string key)
	{
		int length = key.size();
		TrieNode* pn = root;
		int index = 0;

		for(int level = 0; level < length; ++level)
		{
			index = CHAR_TO_INDEX(key[level]);
			if(!(*pn->children)[index])
				return false;
			pn = (*pn->children)[index];
		}

		return (pn != NULL && pn->is_leaf);
	}
};


int main()
{

	const char* keys[] = { "the", "a", "there", "answer",
	                  "any", "by", "bye", "their"};
	vector<string> vs1(keys, keys + 8);

	Trie* tr = new Trie();
	for(int i = 0; i < vs1.size(); ++i)
		tr->insert(keys[i]);


	const char* keys_to_find[] = { "the", "these", "their", "thaw" };
	vector<string> vs2(keys_to_find, keys_to_find + 4);

	for(int i = 0; i < vs2.size(); ++i)
		cout << keys_to_find[i] << ": "
			 << (tr->search(keys_to_find[i]) ? "" : "Not ")
	         << "found in the trie.\n";

	return 0;
}





































