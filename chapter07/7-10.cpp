// 7.10 Describe the data structures and algorithms that you would use to 
//      implement a garbage collector in C++.

// Solution:
// 
// In C++, garbage collection with reference counting is almost always 
// implemented with smart pointers, which perform reference counting. The main 
// reason for using smart pointers over raw ordinary pointers is the conceptual
// simplicity of implementation and usage.

// With smart pointers, everything related to garbage collection is performed 
// behind the scenes - typically in constructors / destructors / assignment 
// operator / explicit object management functions.

// There are two types of functions, both of which are very simple:

RefCountPointer::type1()
{
	/*
		Implementation depends on reference counting organization.
		There can also be no ref. counter at all (see approach $4).
	*/
	increment_ref_counter();
}

RefCountPointer::type2()
{
	/*
		Implementation depends on reference counting organization.
		There can also be no ref. counter at all (see approach $4).
	*/
	decrement_ref_counter();
	if(reference_counter_is_zero())
		destruct_object();
}


// There are several approaches for reference counting implementation in C++:
// 1. Simple reference counting
struct Object {};
struct RefCount
{
	int count;
};
struct RefCountPtr
{
	Object * pointee;
	RefCount * ref_count;
};

// Advantages: performance.
// Disadvantage: memory overhead because of two pointers.

// 2. Alternative reference counting.
struct Object
{
	/* ... */
};

struct RefCountPtrImpl
{
	int count;
	Object * object;
};

struct RefCountPtr
{
	RefCountPtrImpl * pointee;
};

// Advantages: no memory overhead because of two pointers.
// Disadvantage: performance penalty because of extra level of indirection.

// 3. Intrusive reference counting
struct Object
{
	/* ... */
};

struct ObjectIntrusiveRefCount
{
	Object object;
	int count;
};

struct RefCountPtr
{
	ObjectIntrusiveRefCount * pointee;
};

// Advantages: no previous disadvantages.
// Disadvantages: class for intrusive reference counting should be modified. 
// (Why?)

// 4. Ownership list reference counting:
//    It is an alternative for approach 1 - 3. For 1 - 3 it is only important 
//    to determine the counter is zero - its actual value is not important. 
//    This is the main idea of approach #4.

//    All smart-pointers for given objects are stored in a doubly-linked lists.
//    The constructor of a smart pointer adds the new node to a list, and the 
//    destructor removes a node from the list and checks if the list is empty 
//    or not. If it is empty, the object is deleted.

struct Object
{
	/* ... */
};

struct ListNode
{
	Object * pointee;
	ListNode * next;
};






































