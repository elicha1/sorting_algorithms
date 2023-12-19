#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Start with a large gap and reduce it in each iteration */
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        /* Perform gapped insertion sort for this gap size */
        for (i = gap; i < size; i++)
        {
            /* Add a[i] to the elements that have been gap sorted */
            /* Save a[i] in temp and make a hole at position i */
            temp = array[i];

            /* Shift earlier gap-sorted elements up until the correct location for a[i] is found */
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            /* Put temp (the original a[i]) in its correct location */
            array[j] = temp;
        }
        print_array(array, size);
    }
}

