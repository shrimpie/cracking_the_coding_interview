Bit Manipulation


How to Approach
---------------

Bit Manipulation can be a scary thing to many candidates, but it doesn't need 
to be. If you're shaky on bit manipulation, we recommend doing a couple of 
arithmetic-like problems to boost your skills. Compute the following by hand:

    1010 - 0001    1010 + 0110    1100 ^ 1010
    1010 << 1      1001 ^1001     1001 & 1100
    1010 >> 1      0xFF - 1       0xAB + 0x11

If you're still uncomfortable, examine very carefully what happeds when you do 
subtraction, addition, etc in base 10. Can you repeat that work in base 2?


Things to watch out for
-----------------------

>> It's really easy to make mistakes on these problems, so be careful! When you
   are writing code, stop and think about what you're writing every couple of 
   lines - or, better yet, test your code mid-way through! When you're done, 
   check through your entire code.

>> If you're bit shifting, what happens when the digits get shifted off the 
   end? Make sure to think about this case to ensure that you're handling it 
   correctly.

   And (&):    0 & 0 = 0 | 1 & 0 = 0 | 0 & 1 = 0 | 1 & 1 = 1
   Or  (|):    0 | 0 = 0 | 1 | 0 = 1 | 0 | 1 = 1 | 1 | 1 = 1
   Xor (^):    0 ^ 0 = 0 | 1 ^ 0 = 1 | 0 ^ 1 = 1 | 1 ^ 1 = 0


Left shift
----------

x << y means x shifted y bits to the left. If you start shifting and you run 
out of space, the bits just "drop off". For example:

    00011001 << 2 = 01100100
    00011001 << 4 = 10010000


Right shift
-----------

x >> y means x shifted y bits to the right. If you start shifting and you run 
out of space, the bits just "drop off" the end. Example:

	00011001 >> 2 = 00000110
    00011001 >> 4 = 00000001

















