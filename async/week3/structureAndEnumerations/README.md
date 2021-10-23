# 3.4 Structures and Enumerations

## Structures
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

## Typedef

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

## Declaring an instance
- the general syntax to initialze a structure variable is given as follows:
```C
Studen sam = {"Sam","Biology",4.0};
```
- We can also assign a struct to another struct, which copies over the data:
```C
Student sam = {"Sam", "Cybersecurity",4.0};
Student jen = sam;
```

## Accessing Members
- A structure member variable is generally accessed using a "." (dot operator)
- **syntax** struct_var.member_name
- **example**
```C
Student sara;
sara.gpa=4.0;
```

## Accessing Members via Pointers
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

## Structures and Functions
- like all other types in C, strutures are passed by value by default
- this will create a copy of the structure being passed.
- the code given below passes a structure to the function using the call-by-value method.
- _Passing by pointer is often used to avoid making copies._
_structuresFunctions.c_
```C
#include <stdio.h>

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

## Enumerations
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

## Enumerations and Integers
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
[_enumerations.c_](https://github.com/danjshannon/cps-500-programming-and-data-structures/edit/main/async/week3/structureAndEnumerations/README.md) - cannot get this to compile!
- depending on your comipler, you may need to explicitly cast in the other direction.

```C
int x=1;
Direction d = (Direction)x;
```
