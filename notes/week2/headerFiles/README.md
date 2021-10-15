gcc min.c main.c //compiles both files to /.a.out

gcc -c min.c // compiles but not link min.c
gcc -c main.c // compiles but not link main.c
gcc -c main.o min.o -o exec // creates an executable file "exec" from .o files
