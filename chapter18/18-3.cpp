// 18.3 Implement a singleton design pattern as a template such that, for any 
//      given class Foo, you can call Singleton::instance() and get a pointer 
//      to an instance of a singleton of type Foo. Assume the existence of a 
//      class Lock which has acquire() and release() methods. How could you 
//      make your implementation thread safe and exception free?

// The code

#include <iostream>
#include <mutex>
// #include "18-3.h"

/* place holder for thread synchronization lock 
 * Use c++ mutex for testing.
 */
class Lock
{
private:
	std::mutex* mtx;

public:
	Lock() { mtx = new std::mutex(); }
	~Lock() { delete mtx; }
	void acquire_lock() { mtx->lock(); }
	void release_lock() { mtx->unlock(); }
};


/* Singleton class with a method that creates a new instance of the class of 
 * the type of the passed in template if it does not already exist. */
template <class T> class Singleton
{
private:
	static Lock lock;
	static T* obj;

protected:
	Singleton() {};

public:
	static T* instance();
};

class Foo {};

template<class T>
Lock Singleton<T>::lock;

template<class T>
T* Singleton<T>::obj;

// Without above declaration, g++ keeps spitting "Undefined symbols errors"

template<class T>
T* Singleton<T>::instance()
{
	/* If the object is not initialized, acquire lock */
	if(obj == NULL)
	{
		lock.acquire_lock();
		// If two threads simultaneously check and pass the first "if" 
		// condition, then only the one who acquire the lock first should 
		// create the instance 
		if(obj == NULL)
			obj = new T();
		lock.release_lock();
	}
	return obj;
}

template class Singleton<Foo>;

int main()
{
	Foo* singleton_foo = Singleton<Foo>::instance();
	std::cout << "singleton_foo:  " << singleton_foo << std::endl;

	Foo* singleton_foo2 = Singleton<Foo>::instance();
	std::cout << "singleton_foo2: " << singleton_foo2 << std::endl;

	return 0;
}















