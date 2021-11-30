# Week 9 Hash Tables
- [Home](/README.md#cps-500-programming-and-data-structures)
- [9.1 Introduciton](#91-Introduction)

## 9.1 Introduction
[top](#Week-9-Hash-Tables)

### Introduction to Hash Tables
- we want a data structure that has the ability to look up a key/value pair quickly
- Binary search every time per request: O(log(N))?
- suppose that our keys are integers from [0,100], then we could just create an array with 100 entries.
- What if key values are in the range [0, 2<sup>15</sup>]
  - Of which only 100 will be used?

### Hash Table Description
- Hash tables consist of :
  - An array of size N
  - A hash function h that maps from the key space to [0,N]
  - A key space that is typically much larger than N

> keyspace --hash function--> 

### Methods
- Hash tables support three basic methods:
  1. Insert(key,value): inserts a key, value into the hash table
  2. Delete(key): deletes a key/value pair frm the hash table
  3. Lookup(key): retrieves a previously stored value by key

### Hash Functions
### Hash Function Selection
- A has function maps from key space to table space (array size).
- In general the table space is much smaller than the key space.
- This means that, for some pair of keys, a,b:
```h(a)=h(b)```
- This is called a **collision**

### Collision Avoidance
- In general we want to avoid collisions (not 100% possible).
- Consider the hash function `h(x)=0 for all x`
  - This is essentially a static function that maps all inputs to 0
  - This is bad, don't do this.

### Simple Uniform Distribution
- We want a hash function that has a uniform distribution.
  - **simple uniform distribution**: all table indices are equally likely
- Remember, we may know the key space (eg student IDs represented as integers)
  - but we won't know which keys our system will use beforehand.

### Perfect Hashing
- **Perfect Hashing** occurs when there are no collisions
  - This is almost impossible to achieve by accident.
  - Typically, it requres advanced knowledge of the key space.

### Table Size Matters
- Typically, the table size N comes into play to ensure that the indices the hash function creates are in the right range.
  - h(x)=g(x)%N
  - g(x) maps key spaces to som e larger integer space
  - example
    - summing the ASCII value of characters in a string key (common)

### Load Factor
- the load factor &alpha;=m/n
  - m=number of objects indexed
  - n=size of the table
- as the load increases, table lookups get slower as collisions increase
- if the load is too high, a larger table can be created and all elements are rehashed.