# 3.2 Pointers

## Variables and Addresses
- Every variable in C has a name and a value associated with it.
- When a variale is declared, memory is allocated to hold the value of that variable
- This memory has an address

## Pointers
- A pointer is a type of variable whose value is an address in program memory.
- The "*" indicates that ptr is a pointer variable and the int specifies that it will store the address of an integer variable (4 bytes)
```
int * ptr;
```
memory
------
|*   |ptr--
------     |
|10  |x<---
------
|    |

## Referencing
- The "&" operator *references* a variable
  - Retrieves the address of the variable
```
int x = 10;
int *ptr  = &x;
```
- This writes the *address* of variable x into the pointer variable ptr;

## Dereferencing
- We *dereference* a pointer (refer to the values of the address to which is points) by using unary "*" operator.
```
int x = 10; //x=10
int* ptr = &x; //ptr variable points to x
*ptr = 5; //now x=5, ptr is unchanged
```
memory
------
|*   |ptr--
------     |
|10  |x<---
------
|    |

*ptr = 5;

------
|*   |ptr--
------     |
|5   |x<---
------
|    |

## Pointer example program
*pointer.c*

- multiple pointers can reference the same variable. Change one dereferenced value will update "both" dereferenced values.