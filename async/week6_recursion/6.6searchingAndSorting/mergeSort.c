#include <stdio.h>

void mergeSort(int[] array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        margeSort(array.middle + 1, right);
        merge(array, left, middle, right);
    }
}

void merge(int[] array, int left, int middle, int right)
{
    int temp[right - left];
    int i = left;
    int j = middle;
    int index = 0;
    while (i < middle && j < right)
    {
        if (array[i] < array[j])
        {
            temp[index] = array[i];
            i++
        }
        else
        {
            temp[index] = array[j];
            j++
        }
        index++;
    }
    while (i < middle)
    {
        temp[index] = array[i];
        i++;
        index++;
    }
    while (j < right)
    {
        temp[index] = array[j];
        j++;
        index++;
    }
    for (int k = 0; k < right - left; k++)
    {
        array[left + k] = temp[k];
    }
}
int main()
{
}