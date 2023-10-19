#include "sort.h"

/**
 * bubble_sort - Sorts an array of ints in ascending order
 * using Bubble sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap, temp;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0; /*flag to check for swaps */

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;

				print_array(array, size);
			}
		}
		/* if no swaps */
		if (swap == 0)
		{
			break;
		}
	}
}
