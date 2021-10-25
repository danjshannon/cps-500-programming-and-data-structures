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