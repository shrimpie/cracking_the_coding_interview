Object Oriented Design

How to approach
---------------


Object oriented design questions are very important, as they demonstrate the 
quality of a candidate's code. A poor performance on this type of question 
raises serious red flags.


Handling ambiguity in an interview
----------------------------------

OOD questions are often intentionally vague to test if you'll assumptions, or 
if you'll ask clarifiying questions. How do you design a class if the 
constraints are vague? Ask questions to eliminate ambiguity, then design the 
classes to handle any remaining ambiguity.


Object oriented design for software
-----------------------------------

Imagine we're designing the objects for a deck of cards. Consider the following
approach:

1. What are you trying to do with deck of cards? Ask your interviewer. Let's 
   assume we want a general purpose deck of cards to implement many different 
   types of card games.
2. What are the core objects - and what "sub types" are there? For example, the
   core items might be: Card, Deck, Number, Suit, PointValue.
3. Have you misses anything? Think about how you'll use that deck of cards to 
   implement different types of games, changing the class design as necessary.
4. Now, get a little deeper: how will the methods work? If you have a method 
   like Card Deck::getCard(Suit s, Number n), think about how it will retrieve 
   the card.


Object oriented design for real world obejct
--------------------------------------------


Real world objects are handled very similarly to software object oriented 
design. Suppose you are designing an object oriented design for a parking lot.

1. What are your goals? For example: figure out if a parking spot is taken, 
   figure out how many cars of each type are in the parking lot, look up 
   handicapped spots, etc.
2. Now, think about the core objects (Car, ParkingSpot, ParkingLot, 
   ParkingMeter, etc - Car has different subclasses, and Parking Spot is also 
   subclassed for handicapped spot).
3. Have we misses anything? How will we represent parking restrictions based on
   time or payment? Perhaps, we'll add a class called Permission which handles 
   different payement systems. Permission will be sub-classes into classes 
   PaidPermission (fee to park) and FreeParking (open parking). ParkingLot will
   have a method called GetPermission which will return the current Permission 
   object based on the time.
4. How will we know whether or not a car is in a spot? Think about how to 
   represent the data so that the methods are most efficient.

   






















