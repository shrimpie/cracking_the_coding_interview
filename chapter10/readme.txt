Mathematical

How to approach
---------------

Many of these problems read as brain teasers at first, but can be worked 
through in a logical way. Just remember to rely on the rules of mathematics to 
develop an approach, and then to carefully translate that idea into code.

Example: Given two numbers m and n, write a method to return the first number r
that is divisible by both (e.g., the least common multiple).

The approach: What does it mean for r to be divisible by m and n? It means that
all the primes in m must go into r, and all primes in n must be in r. What if m
and n have primes in common? For example, if m is divisible by 3^5 and n is 
divisible by 3^7, what does this mean about r? It means r must be divisible by 
3^7.
    The rule: For each prime p such that p^a\m (e.g., m is divisible by p^a) 
    and p^b\n, r must be divisible by p^max(a, b).
The algorithm:
    Define q to be 1.
    for each prime number p less than m and n:
        find the largest a and b such that p^a \ m and p^b \ n
        let q = q * p^max(a, b)
    return q

    ...........................................................................
    Note: An alternate solution involves recognizing that gcd(a,b)*lcm(a,b)=ab.
    One could then compute the gcd(a,b) using the Euclidean algorithm. Of 
    course, unless you already know this fact, it's unlikely that this rule 
    would occur to you during an interview.
    ...........................................................................


Things to watch out for:
------------------------

1. Be careful with the difference in precision between floats vs. doubles.
2. Don't assume that a value (such as the slope of a line) is an int unless 
   you've been told so.


Bayes' Rule and Probability
---------------------------
1. If A and B are independent, then P(A and B) = P(A) * P(B).
2. Else (in general), P(A and B) = P(A given B) * P(B)
3. If A and B are mutually exclusive (e.g., if one happens, the other one can't
   ), P(A or B) = P(A) + P(B).
4. Else (in general), P(A or B) = P(A) + P(B) - P(A and B).










