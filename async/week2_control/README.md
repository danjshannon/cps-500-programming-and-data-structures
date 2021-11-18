# Week 2: Control
- [Home](https://github.com/danjshannon/cps-500-programming-and-data-structures#cps-500-data-structures)
- [2.1 Control](#21-Control)
- [2.2 Functions](#22-Functions) 
- [2.3 Loops](#23-Loops)
- [2.4 Scope](#24-Scope)
- [2.5 Header Files](#25-header-files)
## 2.1 Control
[top](#week-2-control)
- [continue.c](./continue.c)
- [control.c](./control.c)

## 2.2 Functions
[top](#week-2-control)
- [callByValue.c](./callByValue.c)
- [functionsQ.c](./functionsQ.c)
- [min.c](./min.c)
- [square.c](./square.c)

## 2.3 Loops
[top](#week-2-control)
- [dowhile.c](./dowhile.c)
- [for.c](./for.c)
- [goto.c](./goto.c)
- [iterativeQ2.c](./iteraticeQ2.c)
- [loop.c](./loop.c)
- [nesetedfor.c](./nestedfor.c)
- [while.c](./while.c)

## 2.4 Scope
[top](#week-2-control)
- [globalScope.c](./globalScope.c)
- [static.c](./static.c)
- [staticGlobal.c](./staticGlobal.c)

## 2.5 Header Files
[top](#week-2-control)
- [main.c](./headerFiles/main.c)
- [min.c](./headerFiles/min.c)
- [min.h](./headerFiles/min.h)
### Option 1
- gcc min.c main.c // compiles both files to ./a.out
### Option 2
- gcc -c min.c // compiles but not link min.c
- gcc -c main.c // compiles but not link main.c
- gcc main.o min.o -o exec // creates an executable file "exec" from .o files