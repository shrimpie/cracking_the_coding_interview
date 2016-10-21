Arrays and Strings


Hash Tables
-----------

While not all problems can be solved with hash tables, a shocking number of 
interview problems can be. Before your interview, make sure to practice both 
using and implementing hash tables.

    public HashMap<Integer, Student> buildMap(Student[] students)
    {
    	HashMap<Integer, Student> map = new HashMap<Integer, Student>();
    	for(Student s : students) map.put(s.getId(), s);
    	return map;
    }


ArrayList (Dynamically Resizing Array):
---------------------------------------

An ArrayList, or a dynamically resizing array, is an array that resizes itself 
as needed while still providing O(1) access. A typical implementation is that 
when a vector is full, the array doubles in size. Each doubling takes O(n) 
time, but happens so rarely that its amortized time is still O(1).

    public ArrayList<String> merge(String[] words, String[] more)
    {
    	ArrayList<String> sentence = new ArrayList<String>();
    	for(String w : words) sentence.add(w);
    	for(String w : more) sentence.add(w);
    	return sentence;
    }


StringBuffer / StringBuilder
----------------------------

Question: What is the running time of this code?

    public String makeSentence(String[] words)
    {
    	StringBuffer sentence = new StringBuffer();
    	for(String w : words) sentence.append(w);
    	return sentence.toString();
    }

Answer: O(n^2), where n is the number of letters in sentence. Here's why: each 
time you append a string to sentence, you create a copy of sentence and run 
through all the letters in sentence to copy them over. If you have to iterate 
through up to n characters each time in the loop, and you're looping at least 
n times, that gives you an O(n^2) run time. Ouch!

With StringBuffer (or StringBuilder) can help you avoid this problem.

    public String makeSentence(String[] words)
    {
    	StringBuffer sentence = new StringBuffer();
    	for(String w : words) sentence.append(w);
    	return sentence.toString();
    }

Well, the above two snippets are exactly the same, how is the first one O(n^2)?

Changed the first one to below:

	public String makeSentence(String[] words)
    {
    	String sentence = new String();
    	
    	/* String assignment creates a new string each time. */
    	for(String w : words) sentence += w;

    	return sentence.toString();
    }




















