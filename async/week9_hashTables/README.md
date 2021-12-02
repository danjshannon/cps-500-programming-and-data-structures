# Week 9 Hash Tables
- [Home](/README.md#cps-500-programming-and-data-structures)
- [9.1 Introduciton](#91-Introduction)
- [9.2 Chained Hash Tables](#92-chained-hash-tables)
- [9.3 Open Addressing](#93-open-addressing)
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

## 9.2 Chained Hash Tables
[top](#week-9-hash-tables)
### Option 1: Chaining
- Chaining is a method for dealing with collisions
- Instead of each entry in the hash table being a single entry, we save a list at each entry.
- When a collision occurs at index i, we siply insert the new entry into the list at index i.
- Seaching now take time relative to the length of the lists.

### Chained Hash Table Implementation
```C
struct HashNode{
    int key;
    int value;
    struct HashNode* next;
};

struct ChainedHashTable{
    HashNode** array; // array of pointers to HashNode*
    int N; // size of table
};
```
- In general our array is a pointer to an array, where every element is a pointer.

### Insertion Algorithm
```C
int insert(ChainedHashTable* table, int key, int value){
    int index=h(key);
    HashNode* front = table->array[index];
    HashNode* prev = NULL;
    while(front!=NULL){
        if(fron->key==key){
            return 0;
        }
        prev=front;
        front=front->next;
    }
    HashNode* node=malloc(sizeof(HashNode));
    node->next=NULL;
    node->key=key;
    node->value=value;
    if(prev==NULL){
        table->array[index]=node;
        return 1;
    }
    prev->next=node;
    return 1;
}
```

### Perfomance
- Inserting into a chained Hashtable is O(1)
- Lookup and deletion in the **worst case**: everything has been hashed to the same key value, and runtime is O(N)
  - Which is the same as if we used an unsorted list.
- What about on average?

### Average Case?
- if we assum simple uniform distribution, then each list is expected to be &alpha; elements long
- searching a list that is &alpha; takes O(&alpha;)
- m is the number of elements we have, n is the size of the table
- recall that 
> &alpha;=m/n
- if n&approx;O(m) (is on the same order as), then:
> O(&alpha;)=O(n/m)=O(m/m)=O(1)

## 9.3 Open Addressing
[top](#week-9-hash-tables)
### Open Addressing
- Another option is to keep everything in the has table (no lists)
- when an indexing collision occurs, the table is **probed** until a free location is found.

### Hash Function Extension
- The has function needs to be extended.
  - h(key, [0:n-1])->{0,...,n-1}
    - \*hashed sequence
  - the probe sequence <h(k,0),h(k,1),...,h(k,n-1)> is some permutation of {0,...,n-1}
  - Problematic when load is high
    - notice that **&alpha;&le;1 as n&le;m**
  - Notice that m&le;n, as the table can't be filled beyond capacity

### Structures fo Probed Hash Table
```C
typedef struct HashNode{
    int key;
    int value;
} HashNode;
typedef struct HashTable{
    HashNode** array;
    int size;
}
```

### Insertion Algorithm
```C
int insert(HashTable* table, int key, int value){
    for(int i=0; i<table->size; i++){
        int index = h(value,i);
        if(array[index]==NULL){
            array[index]=malloc(sizeof(HashNode));
            array[index]->key=key;
            array[index]->value=value;
            return 1;
        }else if(array[key]==key){
            return 0;
        }
    }
    return 0;
}
```

### Open-Address Deletion
- Deletion can be problematic.
- If second value in a key sequence is deleted but the thrid is still valid, what do we do?
  - *Shift over all values?*
  - *Tombstone the entry (mark as empty, but does not stop search)?*

### Probe Sequences
- We assume that the probe sequence for a given key is uniformly distributed over all permutations of M.
  - **uniform hashing**
- there are three commonly used probe sequence methods:
  1. Linear probing
  2. Quadratic probing
  3. Double hashing

### Linear Probing
- in linear probing, we use a simple version of the hash key and then add i to the result modulo by N
  > h(k,i)=(h(k)+i)%N
- modulo by N keeps h(k,i) in [0,N-1]
- linear probing is easy to implement but suffers from **primary clustering**, which is long chaings of occupied slots
  - this hurts average runtimes.

### Linear Probing Example
- insert t the following values
  - 5,15,6,12,3,9
```
|x|x|x|x|x|x|
N=6
h(x)=x%N
-----------------
x=5
h(5,0)=(h(5)+0)%6=5
|x|x|x|x|x|5|

x=15
h(15,0)=(h(15)+0)%6=3
|x|x|x|15|x|5|

x=6
h(6,0)=(h(6)+0)%6=0
|6|x|x|15|x|5|

x=12
h(12,0)=(h(12)+0)%6=0 //collision
h(12,1)=(h(12)+1)%6=1
|6|12|x|15|x|5|

x=3
h(3,0)=(h(3)+0)%6=3 //collision
h(3,1)=(h(3)+1)%6=4
|6|12|x|15|3|5|

x=9
h(9,0)=(h(9)+0)%6=3 //collision
h(9,1)=(h(9)+1)%6=4 //collision
h(9,2)=(h(9)+2)%6=5 //collision
h(9,3)=(h(9)+3)%6=0 //collision
h(9,4)=(h(9)+4)%6=1 //collision
h(9,5)=(h(9)+5)%6=2 
|6|12|9|15|3|5|

```

### Qudradic Probing
- Quadratic probing uses a s hash funcion with two constants, c<sub>1</sub> and c<sub>2</sub>:
> h(k,1)=(h(k) + c<sub>1</sub>i + c<sub>2</sub>i<sup>2</sup>) % m
- It performs better than linear probing in practice, but still suffers from **secondary clustering**.
  - When h'(k<sub>1</sub>)=h'(k<sub>2</sub>), the the sequences are identical.

### Quadratic Probing Example
- insert the following values
  - 5,15,6,12,3,9
```
|x|x|x|x|x|x|
N=6
c1=2
c2=3
h(x)=x%N
-----------------
x=5
h(5,0)=(h(5)+0+0)%6=5
|x|x|x|x|x|5|

x=15
h(15,0)=(h(15)+0+0)%6=3
|x|x|x|15|x|5|

x=6
h(6,0)=(h(6)+0+0)%6=0
|6|x|x|15|x|5|

x=12
h(12,0)=(h(12)+0+0)%6=0 //collision
h(12,1)=(h(12)+2*1+3*1)%6=5 //collision
h(12,2)=(h(12)+2*2+3*4)%6=4 //collision
|6|x|x|15|12|5|

x=3
h(3,0)=(h(3)+0+0)%6=3 //collision
h(3,1)=(h(3)+2*1+3*1)%6=2
|6|x|3|15|12|5|

x=9
h(9,0)=(h(9)+0+0)%6=3 //collision
h(9,1)=(h(9)+2*1+3*1)%6=2 //collision
h(9,2)=(h(9)+2*2+3*4)%6=1 //collision
|6|9|3|15|12|5|
```