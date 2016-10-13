Databases



How to approach:
----------------

You could be asked about databases in a variety of ways: write a SQL query,
design a database to hold certain data, or design a large database. We'll go
through the latter two types here.


Small database design
---------------------

Imagine you are asked to design a system to represent a large, multi-location,
apartment rental company.

What are the key objects?
Property. Building. Apartment. Tenant. Manager.


How do they relate to each other?

Many-to-Many:
>> A property could have multiple managers, and a manager could manange
   multiple properties.

One-to-Many:
>> A building can only be part of one property.
>> An apartment can only be part of one building.

What is the relationship between Tenant and Apartment? An apartment can
obviously have multiple tenants. Can a tenant rent multiple apartments? It
would be very unusual to, but this could actually happen (particularly if
it's national company). Talk to your interviewer about this. There is a
trade-off between simplifying your database and designing it to be flexible. If
you do assume that a Tenant can only rent one apartment, what do you have to do
if this situation occurs?


Large database design
---------------------

When designing a large, scalable database, joins (which are required in the 
above examples), are generally very slow. Thus, you must denormalize your data.
Think carefully about how data will be used - you'll probably need to duplicate
it in multiple tables.






