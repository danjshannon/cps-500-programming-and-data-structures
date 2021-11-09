#include <stdio.h>
#include <stdlib.h>
typedef struct circle
{
    int radius;
    double lineWidth;
    int x;
    int y;
} Circle;

enum RAINBOW
{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET
};

int main()
{
    int i, j;
    for (i = 0, j = 0; i < 10 && j < 20; i++, j++)
    {
        printf("i = % d j = % d\n", i, j);
    }

    Circle circle;
    circle.radius = 5;
    circle.lineWidth = 1;
    circle.x = 0;
    circle.y = 0;

    Circle *circles = malloc(sizeof(Circle) * 20);
    for (int c = 0; c < 20; ++c)
    {
        Circle circle;
        circle.radius = 10;
        circle.lineWidth = 1.5;
        circle.x = 15;
        circle.y = 15;
        circles[c] = circle;
    }

    enum RAINBOW rainbow = BLUE;
    if (rainbow == RED)
    {
        printf("RED\n");
    }
    else if (rainbow == YELLOW)
    {
        printf("YELLOW\n");
    }
    else if (rainbow == ORANGE)
    {
        printf("ORANGE\n");
    }
    else
    {
        printf("UNKNOWN\n");
    }

    int *ptr;
    ptr = NULL;
    int x = 10;
    ptr = &x;
    *ptr = 20;
    printf("%d\n", x);
    return 0;
}

char func(int *ptr);