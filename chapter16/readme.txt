Low Level


How to Approach:
----------------

Many candidates find low level problems to be some of the most challenging. Low
level questions require a large amount of knowledge about the underlying
architecture of a system. But just how much do you need to know? The answer to
that depends, of course, on the company. At a typical large software company
where you'd be working on desktop or web applications, you usually only need a
minimum amount of knowledge. However, you should understand the concepts below
very well, as many interview questions are based off this information.


Big vs Little Endian:
---------------------

In big endian, the most significant byte is stored at the memory address
location with the lowest address. This is akin to left-to-right reading order.
Little endian is the reverse: the most significant byte is stored at the 
address with the highest address.


Stack (Memory)
--------------

When a function calls another function which calls another function, this 
memory goes onto the stack. An int (not a pointer to an int) that is created in
a function is stored on the stack.

Heap (Memory)
-------------

When you allocate data with new() or malloc(), this data gets stored on the
heap.


Malloc
------

Memory allocated using malloc is persistent - i.e., it will exist until either
the programmer frees the memory or the program is terminated.

    void * malloc(size_t sz)

Malloc takes input sz bytes of memory and, if it is successful, returns a 
pointer which indicates that it is a pointer to an unknown data type.

    void free(void *p)

Free releases a block of memory previously allocated with malloc, calloc, or 
realloc.



















