# 3.3 Arrays

- Arrays are a way of holding multiple variables of the same type at a time.
- Instead of having k variables, we have one isngle arary variable with k values.
```
int grade1=100;
int grade2=100;
...
int gradeN=90;
```
vs 

## Array Declaration
**syntax** type name[size];
**example** int array[50];

```
int mark[5]={1,2,3,4,5};
mark[0]==1
mark[1]==2
```

## version of C
- compile differently
- use ascii C notation mostly please (backwards compatible)


## Array Indexing
```
int A[5];
int i = 3;
A[i]=5; //writing
int x=A[i]; //reading
```
- arrays are contiguous in memory
  - When an array is declared, that many bytes are allocated next to eachother in memory.
- Index has to be an integer or evaluate to an integer x+1

## Arrays and Loops
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

## Out of Bounds
- Compiler won't catch array out of bounds errors;
- Program will catch, or depending on compiler, unexpected behavior :/

_example.c_

## Pointers and Arrays
## Arrays and Functions

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

## Pointer Arithmetic
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

## Matrices
## Array Dimensions
- Arrays can have multiple dimensions
  - a one-dimensional array is like a row in a table
  - a two-dimensional array is an entire table
  - a three-dimensional array would be a table where each cell is another one-dimensional array.
- C does not put a limit on the number of dimensions.
- 3 d array - n^3 elements in the matrix bleh

## Two-Dimensional Arrays
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

## Strings
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