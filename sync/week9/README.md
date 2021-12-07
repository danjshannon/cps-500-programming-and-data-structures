# Week 9 Hash Tables
- we want a data-structre that has the ability to look up a key/value pair quickly
- Binary search every time per request O(log(n))?
suppose our keys are integers from [0, 100], the we could just create an array with 100 entries.
- What if key values are in the range [0, 2<sup>15</sup>]?
  - of which only 100 will be used?

## has table description
- hash tables consist of:
  - an array of size N
  - a hash function h that maps from the key space to [0:N]
  - typically the key space is much larger than N.

(key space)--hash function-->table (array)

## Functions
- insert
- delete
- lookup

## has function selection
- hash function maps from key space to table space (array size)
- in general the table space is much smaller than the key
- this means that for some pairs of keys: a, b
> h(a)=h(b)

## Collision Avoidance
- in general we want to avoid collisions (not 100% possible)
- Consider the hash function
> h(x)=0
- bad!

## Simple uniform distribution
- all tables indices are equally likely
- remember we may now know the key space

## Perfect Hashing
- no collions
- prior knowledge of keyspace

## Table size matters
- typicallt the size N comes into play to ensure that the indices the hash function creates are in the right range
- h(x)=g(x)%N
- dynamically sized arrays
- elaborate on why %N is used

## Load Factor
- the load factor &alpha;=m/n
  - m number of objects indexed
  - n size of table

## Collision handling 
### Option 1: Chaining
- each index is a list, if a collision occurs, check the list
#### Performance
- insert
  - O(1)
- lookup and deletion
  - O(n) worst case (basically a linked list)
- average case for insert/delete
  - average O(&alpha;), if m&n are on the same order O(1)

### Options 2: Open Addressing
- keep everything in the table, no lists
- if a collision occures, start probing

#### Has Function Extension
- The has function needs to be extended.

#### Open-address Deletion
- can be problematic
- shift over all values?
- tombstone the entry (mark as empty)
  - a lot easier

#### Probe Sequences
- linear
- quadratic

#### Linear Probing
- in linear probin we use a simple version fo the ahs key and then just add i to the reault modulo by N
> h(k,i)=(h(k)+i)%n
- primary clustering

#### Quadratic Probing
- quadradic probing uses a hash function with two constants, c1 and c2
> h(k,i)=(h(k)+c<sub>1</sub>i+c<sub>2</sub>i<sup>2</sup>)
- secondary clustering

##### how to choose c1 and c2
- you can pick constants where you never pick a node
- set N=2<sup>k</sup>
- let c1=c2=1/2

#### Double hashing
- double hashing uses two distinct hash functions (h1,h2) and combines the results linearly:
> h(k,i)=(h1(k)+i *h2(k))%m
- this way if h(k1,0)=h(k2,0), h(k1,1)&ne;h(k2,1)

## Problem solving with Hash Tables
- 
 