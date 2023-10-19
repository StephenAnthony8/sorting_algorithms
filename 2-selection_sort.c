#include "sort.h"

/**
 * selection_sort - sorts an array of ints in
 * ascending order using selection sort
 * @size: size of the array
 * @array: the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			/* swap */
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			/* print after each swap */
			print_array(array, size);
		}
	}
}
