#include "sort.h"

/**
 * shell_sort - hi
 * @arr: arr
 * @size: size
 */
void shell_sort(int *arr, size_t size)
{
	int n = (int)size, gap = 1, i, tmp, j;

	while (gap < n)
		gap = gap * 3 + 1;
	gap /= 3;
	while (gap)
	{
		for (i = gap; i < n; ++i)
		{
			tmp = arr[i], j = i;
			for (; j - gap >= 0 && tmp < arr[j - gap]; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = tmp;
		}
		gap /= 3;
		print_array(arr, size);
	}
}
