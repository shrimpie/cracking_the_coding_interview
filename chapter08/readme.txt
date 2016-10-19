

Recursion


How to recognize
----------------

While there is a wide variety of recursive problems, many recursive problems 
follow similar patterns. A good hint that problem is recursive is that it 
appears to be built off sub-problems.

When you hear a problem beginning with the following, it's often (though not 
always) a good candidate for recursion: "Design an algorithm to compute the nth
..."; "Write code to list the first n..."; "Implement a method to compute all 
..."; etc.

Again, practice makes perfect! The more problems you do, the easier it will be 
to recognize recursive problems.


How to Approach
---------------

Recursive solutions, by definition, are built off solutions to sub-problems. 
Many times, this will mean simply to compute f(n) by adding something, 
removing something, or otherwise changing the solution for f(n-1). In other 
cases, you might have to do something more complicated. Regardless, we 
recommend the following approach:
1. Think about what the sub-problem is. How many sub-problems deos f(n) 
   depend on? That is, in a recursive binary tree problem, each part will 
   likely depend on two problems. In a linked list problem, it'll probably be 
   just one.
2. Solve for a "base case". That is, if you need to compute f(n), first compute
   it for f(0) or f(1). This is usually just a hard-coded value.
3. Solve for f(2).
4. Understand how to solve for f(3) using f(2) (or previous solutions). That is
   , understand the exact process of translating the solutions for sub-problems
   into the real solutions.
5. Generalize for f(n).

This "bottom-up recursion" is often the most straight-forward. Sometimes, 
though, it can be useful to approach problems "top down", where you essentially
jump directly into breaking f(n) into its sub-problems.


Things to watch out for
-----------------------

1. All problems that can solved recursively can also be solved iteratively 
   (though the code may be much more complicated). Before diving into a 
   recursive code, ask yourself how hard it would be to implement this 
   algorithm iteratively. Discuss the trade-offs with you interviewer.
2. Recursive algorithms can be very space inefficient. Each recursive call adds
   a new layer to the stack, which means that if your algorithm has O(n) 
   recursive calls then it uses O(n) memory. Ouch! This is one reason why an 
   iterative algorithm may be better.
   
















