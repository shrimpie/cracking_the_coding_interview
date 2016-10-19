Sorting and Searching

How to Approach
---------------

Understanding the common sorting algorithm is incredibly valuable, as many 
sorting or searching solutions require tweaks of known sorting algorithms. A 
good approach when you are given a question like this is to run through the 
different sorting algorithms and see if one applies particularly well.

Example: You have a very large array of 'Person' objects. Sort the people in 
increasing order of age.

We're given two interesting bits of knowledge here: (1) It's a large array, so
efficiency is very important. (2) We are sorting based on ages, so we know the 
values are in a small range. By scanning through the various sorting algorithms
, we might notice that bucket sort would be a perfect candidate for this 
algorithm. In fact, we can make the buckets small (just 1 year each) and get 
O(n) running time.


Bubble Sort:
Start at the beginning of an array and swap the first two elements if the first
is bigger than the second. Go to the next pair, etc, continuously making sweeps
of the array until sorted. O(n^2).

Selection Sort:
Find the smallest element using a linear scan and move it to the front. Then, 
find the second smallest and move it, again doing a linear scan. Continue doing
this until all the elements are in place. O(n^2).

Merge Sort:
Sort each pair of the elements. Then sort every four elements by merging every 
two pairs. Then, sort every 8 elements, etc. O(nlogn) expected and worst case.

Quick Sort:
Pick a random element and partition the array, such that all numbers that are 
less than it come before all elements that are greater than it. Then do that 
for each half, then each quarter, etc. O(nlogn) expected, O(n^2) worst case.

Bucket Sort:
Partition the array into a finite number of buckets, and then sort each bucket 
individually. This gives a time of O(n+m), where n is the number of items and m
is the number of distinct items.




