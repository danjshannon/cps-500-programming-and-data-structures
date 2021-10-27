# Sync Lectures

## Memory
### Pogram Memory
- *BSS - Block Started by Symbol
- *Data Segment
- *ROData Segment
- *Text Segment
- *** Compiler generated
- Heap
  - Generally more stable in size
- Stack
  - Constantly changes, 
  - grows when you enter a function
  - shrinks when you leave
- Unused (much larger than what you're using in general)

## Pointers
- Pointer varaibles hold memory locations
- * indicates a pointer
  - int* A
- & refrerence a variable
  - Returns the memory address of a variable.
  - int X;
  - int* A=&X;
- * dereferences a value.
- Not using the *value* in a pointer variable to do something
- (*intPointer) allows you to access x without referencing x;

## NULL, Void, and Double Pointers
- NULL indicates a pointe ris empty
  - Pointers are initiated to **garbage** and must be set to NULL
  ```C
  int* x=NULL;
  if(x==NULL){...};
  ```
- void pointer can point to any data type
  - malloc returns a void pointer
  - Adress sizes are all equal, independent of data type stored.
  - void pointers must be cast when using, but not during assignment
  ```C
  int A;
  void* X = &A;
  (int*)X=6;
  ```
- pointers can point to pointers.
- The only way to change a value passed by value to a function is to pass a pointer.

## Dynamic Memory
- malloc - Memory Allocation
  - int* xp = (int*)malloc(*#items* * sizeof(int))
    - Goes onto the heap from the unused area.
  - ...
  - xp=NULL;
- free - releases memory
  - very important to avoid memory leaks
  - free(xp);

## Arrays
```C
int arr[5];
```
- int arr is a pointer to the first memory address.
- compiler knows they size of the datatype and can allocate that many memory blocks.
- when you go to the index of an array, the program jumps to the first block then can jump to the datatype size X the length

## Arrays, Functions, and Pointers
- Arrays can be passed to functions as arrays or pointers
- Arrays are always passed by reference becauase they are pointers.

## Strings
- NULL terminated character array
  - always make the array one larger than the largest size of the string
- use string.h functions for operating with string
  - strlen
  - strncpy
  - strncmp
  - ...more!

```C
function compare(char first[],char second[], int n){
int same = 1;
for(int x = 0; x<n && same==1;x++){
    if(first[x]!=second[x])
        same=0;
}
return same;
}
```

## Structures and Typedef
- Collections of different data types
```C
struct carType{
    char make[31];
    char model[31];
    int year;
}
struct carType carVar;
```

```C
typedef struct carType{
    char make[31];
    char model[31];
    int year;
} Car
 Car carVar;
```

## access structure members
- Nomral accessing (Car carVar)
```C
carVar.year=2019;
carVar.make="Audi";
```
- Pointer accessing (Car* carVar)
```C
(*carVar).year;
carVar->year;
```

## Enumerations
```C
enum Direction{North, South, East, West};
typedef enum direction{...}Direction;
```
- Just integer values
```C
typedef enum direction {North=0,South=0,East=5,West=8} Direction;
```