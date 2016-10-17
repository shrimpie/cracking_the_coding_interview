// 20.7 Write a program to find the longest word made of other words.

// Question: what does it mean? To find the word that is made of other words 
//           that also has the longest length?


// Idea from the book:
// THe solution below does the following:
// 1. Sort the array by size, putting the longest length word at the front.
// 2. For each word, split it in all possible ways. That is, for "test", split
//    it into {"t", "est"}, {"te", "st"} and {"tes", "t"}.
// 3. Then, for each pairing, check if the first half and the second both exist
//    elsewhere in the array.
// 4. "Short circuit" by returning the first string we find that fits condition
//    #3.

// What is the time complexity of this?
// >> Time to sort array: O(nlogn)
// >> Time to check if first/second half of word exists: O(d) per word, where 
//    d is the average length of a word.
// >> Total complexity: O(nlogn + n*d). Note that d is fixed (probably 5 to 
//    10 characters). Thus, we can guess that for short arrays, the time is 
//    estimated by O(n*d), which also equals O(number of characters in the 
//    array). For longer arrays, the time will be better estimated by O(nlogn).
// >> Space complexity: O(n).


// Optimizations: If we didn't want to use additional space, we could cut out 
// the hash table. This would mean:
// >> Sorting the array in alphabetical order
// >> Rather than looking up the word in a hash table, we would use binary 
//    search in the array
// >> We would no longer be able to short circuit.



