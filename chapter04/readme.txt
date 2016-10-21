Trees and Graphs

How to Approach
---------------

Trees and graphs questions typically come in one of two forms:
1. Implement a tree / find a node / delete a node / other well know algorithm;
2. Implement a modification of a known algorithm.

Either way, it is strongly recommended to understand the important tree 
algorithms prior to your interview. If you're fluent in these, it'll make the 
tougher questions that much easier! We'll list some of the most important.


Warning: Not all binary trees are binary search trees
-----------------------------------------------------

When given a binary tree question, many candidates assume that the interviewer 
means "binary search tree", when the interviewer might only mean "binary tree".
So, listen carefully for that word "search". If you don't hear it, the 
interviewer may just mean a binary tree with no particular ordering on the 
nodes. If you are not sure, ask.


Binary Trees - "Must know" algorithm
------------------------------------

You should be able to easily implement the following algorithms prior to your
interview:

>> In-order: Traverse left node, current node, then right [usually used for 
   search trees]
>> Pre-Order: Traverse current node, then left node, then right node.
>> Post-Order: Traverse left node, then right node, then current node.
>> Insert Node: On a binary search tree, we insert a value v, by comparing it 
   to the root, If v > root, we go right, and else we go left. We do this until
   we hit an empty spot in the tree.

   ............................................................................
   Note: balancing and deletion of binary search trees are rarely asked, but 
   you might want to know some idea how they work. It can set you apart from 
   other candidates.
   ............................................................................


Graph Traversal - "Must Know" Algorithms
----------------------------------------

You should be able to easily implement the following algorithms prior to your 
interview:

>> Depth First Search: DFS involves searching a node and all its children 
   before proceeding to its siblings.
>> Breadth First Search: BFS involves searching a node and its siblings before 
   going to any children.


 









