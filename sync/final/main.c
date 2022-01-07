#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int *array;
    int capacity;
    int size;
} Heap;

int HeapInsert(Heap *heap, int value)
{
    if (heap->size >= heap->capacity)
    {
        return 0;
    }
    int n = heap->size;
    heap->array[n] = value;
    int p = (n - 1) / 2;
    while (n > 0 && heap->array[p] < heap->array[n])
    { // this operator determines min vs max heap
        int temp = heap->array[p];
        heap->array[p] = heap->array[n];
        heap->array[n] = temp;
        n = p;
        p = (n - 1) / 2;
    }
    heap->size++;
    return 1;
}
int c = 0;
int mult(int m, int n)
{
    c++;
    if (m == 1)
    {
        return n;
    }
    return n + mult(m - 1, n);
}

int main()
{
    int m = 5000;
    int n = 7;
    printf("mult(%d,%d)=%d\n", m, n, mult(m, n));
    printf("%d times\n", c);
    return 0;
}