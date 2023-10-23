#include "sort.h"

void print_counting_array(int *counting_array, int size);

/**
 * counting_sort - sorts an array of ints using
 * counting sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, j, element;
	int *counting_array, *sorted_array;
	size_t i;
	ssize_t k;

	if (array == NULL || size < 2)
		return;

	/* finds max value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] < 0)
			return;
		if (array[i] > max)
			max = array[i];
	}
	/* creates & initializes counting array */
	counting_array = malloc((max + 1) * sizeof(int));
	if (!counting_array)
		return;

	for (j = 0; j <= max; j++)
		counting_array[j] = 0;

	/* counts occurrence of each element in the input array */
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	/* updates counting array with cumulative counts */
	for (j = 1; j <= max; j++)
		counting_array[j] += counting_array[j - 1];
	/* creates a new sorted array using counting array */
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}
	for (k = size - 1; k >= 0; k--)
	{
		element = array[k];
		counting_array[element]--;
		sorted_array[counting_array[element]] = element;
	}
	/* copy sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	print_counting_array(counting_array, max + 1);

	free(counting_array);
	free(sorted_array);
}

/**
 * print_counting_array - Prints the counting array
 * @counting_array: The counting array to be printed
 * @size: The size of the counting array
 */
void print_counting_array(int *counting_array, int size)
{
	int i;

	printf("Counting array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", counting_array[i]);
		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
