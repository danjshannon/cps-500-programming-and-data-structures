## 2.3 Header Files
- [main.c](./headerFiles/main.c)
- [min.c](./headerFiles/min.c)
- [min.h](./headerFiles/min.h)
### Option 1
- gcc min.c main.c // compiles both files to ./a.out
### Option 2
- gcc -c min.c // compiles but not link min.c
- gcc -c main.c // compiles but not link main.c
- gcc main.o min.o -o exec // creates an executable file "exec" from .o files
