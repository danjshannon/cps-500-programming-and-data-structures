# Week 3: Memory
- [3.1 Memory](##31-memory)
- [3.2 Pointers](##32-pointers)
- [3.3 Arrays](##33-arrays)
- [3.4 Structures and Enumerations](##34-structures-and-enumerations)

## 3.1 Memory
[top](##week-3-memory)
### Program Memory
- Every program has memory associated with it to store all of its data and program instructions.
- Four areas
  - Stack Segment
  - Heap Segmnet
  - Data Segment (compiler generated address)
  - Text Segment (compiler generated address)

### Stack
1. Local Variables
2. Read/write
3. Area grows with program
4. Stack pointer register keeps track of bottom of stack where new variables are allocated.
5. Also used to store information for program flow to do with functions. 

_stack.c_

### Heap
1. Dynamic memory area
2. Read/write
3. Memory needs to be manually allocated/deallocated (or garbage collected)
4. Area grows/shrinks
5. Typically requires operating system support

```C
int *array = malloc(sizeof(int) *20);
```

### Data
1. Contains static initialzed variables, global varables, static local variables.
2. Data are read/write
3. Size computed at compile time (does not change)

```C
int globalVariable = 10; //different segment of memory
int main(){
    return 0;
}
```

### Text
1. Readonly
2. size doesn't change
3. Contains executable machine instructions
4. Can be shared if running multiple times

- Only instructions go into text segment

```C
add $s1, $s2, $s3
```
(not really in assembly though)

### Variables in Memory
_memory.c_
```C
int N = 10;
int max(int x, int y)
{
    int z = x;
    if (x < y)
    {
        z = y;
    }
    return z;
}

int main()
{
    int a = 5;
    printf("Max: %d", max(a, N));
}
```
a,x,y,z in **stack**
global N in **data**

Argument variables are local variables.

## 3.2 Pointers
[top](##week-3-memory)
### Variables and Addresses
- Every variable in C has a name and a value associated with it.
- When a variale is declared, memory is allocated to hold the value of that variable
- This memory has an address

### Pointers
- A pointer is a type of variable whose value is an address in program memory.
- The "*" indicates that ptr is a pointer variable and the int specifies that it will store the address of an integer variable (4 bytes)
```C
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

### Referencing
- The "&" operator *references* a variable
  - Retrieves the address of the variable
```C
int x = 10;
int *ptr  = &x;
```
- This writes the *address* of variable x into the pointer variable ptr;

### Dereferencing
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
### Pointer example program
*pointer.c*

- multiple pointers can reference the same variable. Change one dereferenced value will update "both" dereferenced values.

### Null Pointers
- A null ponter is a special pointer value that is known to not point anywhere
- This means that a NULL pointer does not point ot any valid memory address,
```C
int *ptr = NULL;//if you don't assign, the value will be GARBAGE
if (ptr == NULL) {
  Statement block;
}
```

### Segmentation Faults
- Cannot dereference a NULL pointer.
- Dereferencing garbage variables will either:
  - Cause a segmentation fault
  - Cause unexpected behavior
    - Change an arbitrary address space - this could be a legitimate value.
You cannot check if a pointer is garbage.

### Void Pointer
- A generic pointer is a pointer variable that has void as its data type.
- The void pointer can be pointed at variables of any data type.
- Notice that all pointer variablesare the same size, as addresses are of fixed size.
```
void* ptr=NULL;
```
*voidPointer.c*

### Pointers to Pointers
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

### Malloc
- recall that local variables are allocated on the stack
- in C, we use malloc to allocate memory on the heap.
- **syntax**: ptr=(cast-type*) malloc(byte-size);
- **example**
  - 100 * sizeof(int):100*number of bytes in an integer=400bytes
```C
int* ptr = (int*)malloc(100*sizeof(int));
```
- _local stack variable assigning the value of an address on the heap_
- can never put a variable on the heap.
- malloc returns a void pointer which is an address that lives in the heap.
- named variables always go in data or stack

### Free
- Local variables on the stack are reclaimed once the function returns
- memory on the heap has to be reclaimed manually using the free method
- **syntax**: free(ptr)
- **example**
```C
int *ptr=malloc(sizeof(int)*10);
// int *ptr is the variable that is holding the address
// malloc(sizeof(int)*10) is the address itself
...
free(ptr); //free the address of the ptr on the heap
```
- calling free on a NULL ptr will crash the program
- calling free on a non-heap-allocated address _may_ crash the program.

**what happens here?**
```C
int *x = malloc(100 * sizeof(int));
x = NULL;
```
## 3.3 Arrays
[top](##week-3-memory)
- Arrays are a way of holding multiple variables of the same type at a time.
- Instead of having k variables, we have one isngle arary variable with k values.
```C
int grade1=100;
int grade2=100;
...
int gradeN=90;
```
vs 

### Array Declaration
**syntax** type name[size];
**example** int array[50];

```C
int mark[5]={1,2,3,4,5};
mark[0]==1
mark[1]==2
```

### version of C
- compile differently
- use ascii C notation mostly please (backwards compatible)


### Array Indexing
```C
int A[5];
int i = 3;
A[i]=5; //writing
int x=A[i]; //reading
```
- arrays are contiguous in memory
  - When an array is declared, that many bytes are allocated next to eachother in memory.
- Index has to be an integer or evaluate to an integer x+1

### Arrays and Loops
_arrayLoop.c_
```C
int A[5];
...
int A[5] = {5, 10, 3, 90, 51};
int min = A[0]; //set min to first element
for (int i = 1; i < 5; i++) //start at i=1
{
    if (min > A[i])
    {
        min = A[i];
    }
    printf("A[%d] = %d\n", i, A[i]);
}
printf("Min of A = %d\n", min);
return 0;
```

### Out of Bounds
- Compiler won't catch array out of bounds errors;
- Program will catch, or depending on compiler, unexpected behavior :/

_example.c_

### Pointers and Arrays
### Arrays and Functions

- Arrays can be passed as arguments to functions
- Potentially need to pass the size of the array

```C
int reverse(int A[],int size){
    for(int i =0;i<size/2;i++){
        int temp = A[i];
        A[i]=A[size-i-1];
        A[size-i-1]=temp;
    }
}
```
- The array itself is the adress of the first element of that array: array = &array[0]
  - We've passed the address of the array by value!
  - This will have an effect outside of the function!

We can also pass arrays as:
```C
//1. Pass an array with unknown size:
int reverse(int A[],int size);
//2. Pass an array as pointer:
int reverse(int* A,int size); //if you derefernce array, it will have an effect outside of the function
//3. Hardcoded array size:
int reverse(int A[10]);
```

### Pointer Arithmetic
- The ++(--) operator can be used to advance(decrease) the pointer by a number of bytes (its type).

_pointerArithmetic.c_
```C
int array[5] = {1, 2, 3, 4, 5};
int *ptr = array; //Recall array = &array[0] - a pointer to the address of the array!
while (ptr != &array[5])
{
    printf("%d\n", *ptr);
    ptr++; //advances pointer 4 bytes(int) to the next address of the allocated memory
}
return 0;
```

### Matrices
### Array Dimensions
- Arrays can have multiple dimensions
  - a one-dimensional array is like a row in a table
  - a two-dimensional array is an entire table
  - a three-dimensional array would be a table where each cell is another one-dimensional array.
- C does not put a limit on the number of dimensions.
- 3 d array - n^3 elements in the matrix bleh

### Two-Dimensional Arrays
- **syntax** data_type array_name[row_size][column_size];
- Elements are accessed using two subscripts (i,j)
- **example** int grades[3][5];

- **initialization**
```C
int grades[2,3]={90,87,78,68,62,71};
int grades[2,3]={{90,87,78}/*row 1*/,{68,62,71}/*row 2*/};
```
- flatten the 2d array to allocate in memory
  - row1 followed by row 2 followed by row n
```C
int main(){
    int arr[2][2]={12,34,56,32};
    for(int i = 0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

### Strings
- A string is a null-terminated character array
- to mark the end of the array, a null character ("\0") is placed at the end to signify the end of the string
- **syntax**: char str[size];
- **example** 
```C
char str[] = "HELLO";
```
- declares a string with six characters:
  - "H" "E" "L" "L" "O" and "\0"

What will be the output from the program below?
_I think they will not match - they live in different address and are two distinct objects_
```C
char a_string[10] = "Hello";
char b_string[10] = "Hello";
if(b_string==a_string){
    printf("the strings match!\n");
}else{
    printf("this strings don't match!\n");
}
```
- the variable name is the pointer to the first element.
  - address won't match
```C
int compareStrings(char* string1, char* string2, int N){
  for(int i = 0; i<N;i++){
      if(string1[i]!= string2[i]){
          return 0;//false
      }
  }
  return 1;//true
}
//what happens if one of the indices is out of bounds??
```

###
- The header file string.h contains several useful methods:
- size_t

## 3.4 Structures and Enumerations
[top](##week-3-memory)
### Structures
- A structure is a user-defined data-type
- **syntax**
```C
struct struct_name{
    data_type_1 var_name_1;
    data_type_2 var_name_2;
}
```

- **example**
```C
struct Student{
    char name[20];
    char course[20];
    float GPA;
}
```
- The structe is just a template that the C compiler uses to lay out memory.
- Memory is allocated for the structure when we declare a variable of the structure:
```C
struct Student sam
```

### Typedef

- The typedef keyword creates a new type definition:
```C
typedef struct student {
    char name[20];
    char course[20];
    float gpa;
} Student;
```
- Declaring a student now is just:
```C
Student sam;
```

### Declaring an instance
- the general syntax to initialze a structure variable is given as follows:
```C
Studen sam = {"Sam","Biology",4.0};
```
- We can also assign a struct to another struct, which copies over the data:
```C
Student sam = {"Sam", "Cybersecurity",4.0};
Student jen = sam;
```

### Accessing Members
- A structure member variable is generally accessed using a "." (dot operator)
- **syntax** struct_var.member_name
- **example**
```C
Student sara;
sara.gpa=4.0;
```

### Accessing Members via Pointers
- if we have a pointer to a struct, the we would first need to dereference the value
- **syntax** (*struct_var).member_name
- to simplify, we use the "->" operator
- **syntax** struct_var->member_name
- **example**
```C
Student* susan;
(*susan).gpa=4.0;
susan->gpa=3.7;
//the previous two lines mean the exact same thing!!
```

### Structures and Functions
- like all other types in C, strutures are passed by value by default
- this will create a copy of the structure being passed.
- the code given below passes a structure to the function using the call-by-value method.
- _Passing by pointer is often used to avoid making copies._
_structuresFunctions.c_
```C
##include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

void display(Point p)
{
    printf("%d, %d\n", p.x, p.y);
}

void displayPtr(Point *p)
{
    printf("%d, %d\n", p->x, p->y);
}

int main()
{
    Point p1 = {2, 3};
    display(p1);
    displayPtr(&p1);
    return 0;
}
```

### Enumerations
- The enumerated data type is a user-defined type based on the standard integer type.
- **syntax** enum enum_name {id_1,id_2,...,id_n};
- **example**
```C
enum Direction {NORTH, EAST, SOUTH, WEST};
enum Direction dir = EAST;
```
- Again, we can use typedef:
```C
typedef enum direction {NORTH, EAST, SOUTH, WEST} directoin;
Direction dir = EAST;
```

### Enumerations and Integers
- Behind the scenes enumarations are just integers
```C
enum Direcatoin {NORTH, EAST, SOUTH, WEST};
//NORTH=0, EAST=1,SOUTH=2,WEST=3
```
- We can manually specify the integer values:
```C
enum Direction {NORTH=1, EAST=3, SOUTH=5, WEST=7};
```

- Enumerated types can be implicitly cast to integers:
```C
enum Direction dir=NORTH;
printf("Dir: %d\n",dir);
```
[_enumerations.c_](https://github.com/danjshannon/cps-500-programming-and-data-structures/blob/main/async/week3/structureAndEnumerations/enumerations.c) - cannot get this to compile!
- depending on your comipler, you may need to explicitly cast in the other direction.

```C
int x=1;
Direction d = (Direction)x;
```
