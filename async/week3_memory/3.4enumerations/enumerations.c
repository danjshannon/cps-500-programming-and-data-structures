#include <stdio.h>

int main()
{
    enum Direcation
    {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };
    enum Direction dir = NORTH;
    printf("Dir: %d\n", dir);
    return 0;
}