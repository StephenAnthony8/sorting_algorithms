#include "sort.h"

/**
 * shell_sort - sorts an array of ints in ascending order
 * using the shell sort algorithm
 * @array: the arry to be soted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{

	size_t gap = 1, i, j;
	int temp;

	/* calculate initial gap using knuth */
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	/* perfom shell sort with decreasing gap */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
