Java


How to approach:
----------------

While Java related questions are found throughout the book, this chapter deals
with questions about the language and syntax. You generally will not find too
many questions like this at the larger software companies (though they are
sometimes asked), but these questions are very common at other companies.


What do you do when you don't know the answer?
----------------------------------------------

If you don't know the answer to a question about the Java language, try to
figure it out by doing the following: (1) Think about what other languages
do. (2) Create an example of the scenario. (3) Ask yourself how you would
handle the scenario if you were designing the language.
Your interviewer may be equally -- or more -- impressed if you can derive the
answer than if you automatically knew it. Don't try to bluff though. Tell
the interviewer, "I'm not sure I can recall the answer, but let me see if I
can figure it out. Suppose we have this code..."


Classes & Interfaces (Example)
------------------------------

	public static void main(String args[]) { ... }
	interface Foo
	{
		void abc();
	}
	class Foo extends Bar implements Foo { ... }


final:
------

>> Class: can not be sub-classed
>> Method: can not be overriden
>> Variable: can not be changed.


static:
-------

>> Method: class method. Called with Foo.DoIt() instead of f.DoIt()
>> Variable: class variable. Has only one copy and is accessed through the
       class name.


abstract:
---------

>> Class: contains abstract methods. Can not be instantiated.
>> Interface: interfaces are implicitly abstract. This modifier is optional.
>> Method: method without a body. Class must also be abstract.
















