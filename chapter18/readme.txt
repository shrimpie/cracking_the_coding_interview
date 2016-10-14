
Threads and Locks


How to Approach
---------------

In a Microsoft, Google or Amazon interview, it's not terribly common to be 
asked to implement an algorithm with threads (unless you're working in a team 
for which this is particularly important skill). It is, however, relatively 
common for interviewers at any company to assess your general understanding of 
threads, particularly your understanding of deadlocks.


Deadlock conditions
-------------------

In order for a deadlock to occur, you must have the following four conditions 
met:
1. Mutual Exclusion: Only one process can use a resource at a given time.
2. Hold and Wait: Processes already holding a resource can request new ones.
3. No Preemption: One process cannot forcibly remove another process' resource.
4. Circular Wait: Two or more processes form a circular chain where each 
   process is waiting on another resource in the chain.


Deadlock prevention
-------------------

Deadlock prevention essentially entails removing one of the above conditions, 
but many of these conditions are difficult to satisfy. For instance, removing 
#1 is difficult because many resources can only be used by one process at a 
time (printers, etc). Most deadlock prevention algorithms focus on avoiding #4:
circular wait.

If you aren't familiar with these concepts, please read 
http://en.wikipedia.org/wiki/Deadlock.


A Simple Java Thread
--------------------

    class Foo implements Runnable
    {
    	public void run()
    	{
    		while(true) beep();
    	}
    }
    Foo foo = new Foo();
    Thread my_thread = new Thread(foo);
    my_thread.start();