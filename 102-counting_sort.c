#include "sort.h"

/**
 * max_int - gets the maximum int in the array
 * @array: An array of integers
 * @size: the size of the array
 *
 * Return: the maximum integer
 */
int max_int(int *array, int size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
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
	
	if (array == NULL || size < 2)
		return;
	max = max_int(array, size);

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

	free(sorted_array);
	free(counting_array);
}
