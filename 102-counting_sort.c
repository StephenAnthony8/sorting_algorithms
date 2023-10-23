#include "sort.h"

/**
 * counting_sort - sorts an array of ints using
 * counting sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, i, element;
	int *counting_array, *sorted_array;
	size_t j;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (j = 0; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (!counting_array)
		return;
	for (i = 0; i < (max + 1); i++)
		counting_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		counting_array[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, max + 1);
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		element = array[i];
		sorted_array[counting_array[element - 1]] = element;
		counting_array[element] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
	free(counting_array);
	free(sorted_array);
}
