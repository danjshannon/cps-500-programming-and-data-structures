# 3.1 Memory
**Program Memory**
- Every program has memory associated with it to store all of its data and program instructions.
- Four areas
  - Stack Segment
  - Heap Segmnet
  - Data Segment (compiler generated address)
  - Text Segment (compiler generated address)

**Stack**
1. Local Variables
2. Read/write
3. Area grows with program
4. Stack pointer register keeps track of bottom of stack where new variables are allocated.
5. Also used to store information for program flow to do with functions. 

_stack.c_

**Heap**
1. Dynamic memory area
2. Read/write
3. Memory needs to be manually allocated/deallocated (or garbage collected)
4. Area grows/shrinks
5. Typically requires operating system support

```
int *array = malloc(sizeof(int) *20);
```

**Data**
1. Contains static initialzed variables, global varables, static local variables.
2. Data are read/write
3. Size computed at compile time (does not change)

```
int globalVariable = 10; //different segment of memory
int main(){
    return 0;
}
```

**Text**
1. Readonly
2. size doesn't change
3. Contains executable machine instructions
4. Can be shared if running multiple times

Only instructions go into text segment

```
add $s1, $s2, $s3
```
(not really in assembly though)

## Variables in Memory
_memory.c_
```
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
