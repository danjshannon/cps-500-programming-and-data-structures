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
```
------
|*   |ptr--
------     |
|10  |x<---
------
|    |
```

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
```
------
|*   |ptr--
------     |
|10  |x<---
------
|    |
```
*ptr = 5;
```
------
|*   |ptr--
------     |
|5   |x<---
------
|    |
```
## Pointer example program
*pointer.c*

- multiple pointers can reference the same variable. Change one dereferenced value will update "both" dereferenced values.

## Null Pointers
- A null ponter is a special pointer value that is known to not point anywhere
- This means that a NULL pointer does not point ot any valid memory address,
```
int *ptr = NULL;//if you don't assign, the value will be GARBAGE
if (ptr == NULL) {
  Statement block;
}
```

## Segmentation Faults
- Cannot dereference a NULL pointer.
- Dereferencing garbage variables will either:
  - Cause a segmentation fault
  - Cause unexpected behavior
    - Change an arbitrary address space - this could be a legitimate value.
You cannot check if a pointer is garbage.

## Void Pointer
- A generic pointer is a pointer variable that has void as its data type.
- The void pointer can be pointed at variables of any data type.
- Notice that all pointer variablesare the same size, as addresses are of fixed size.
```
void* ptr=NULL;
```
*voidPointer.c*

## Pointers to Pointers
- Pointers can hold the address of another pointer variable
- To declare pointer to pointers add an * for each level of reference
*pointersToPointers.c*
```
------
|*   |px--- <-   
------     | |
|5   |x<---  |
------       |
|**  |ppx-----
```

## Malloc
- recall that local variables are allocated on the stack
- in C, we use malloc to allocate memory on the heap.
- **syntax**: ptr=(cast-type*) malloc(byte-size);
- **example**
  - 100 * sizeof(int):100*number of bytes in an integer=400bytes
```
int* ptr = (int*)malloc(100*sizeof(int));
```
- _local stack variable assigning the value of an address on the heap_
- can never put a variable on the heap.
- malloc returns a void pointer which is an address that lives in the heap.
- named variables always go in data or stack

## Free
- Local variables on the stack are reclaimed once the function returns
- memory on the heap has to be reclaimed manually using the free method
- **syntax**: free(ptr)
- **example**
```
int *ptr=malloc(sizeof(int)*10);
// int *ptr is the variable that is holding the address
// malloc(sizeof(int)*10) is the address itself
...
free(ptr); //free the address of the ptr on the heap
```
- calling free on a NULL ptr will crash the program
- calling free on a non-heap-allocated address _may_ crash the program.

*what happens here?*
```
int *x = malloc(100 * sizeof(int));
x = NULL;
```
