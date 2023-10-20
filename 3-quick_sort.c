#include "sort.h"

/**
 * quick_sort - sorts an array of ints in ascending
 * order using quick sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - recursive function for quick sort
 * @array: the array to be sorted
 * @low: the index of the low element of the partition
 * @high: the index of the high element of the partition
 * @size: size of the array
 */
void quick_sort_recursion(int array[], int low, int high,
		size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_idx - 1, size);
		quick_sort_recursion(array, pivot_idx + 1, high, size);
	}

}
/**
 * lomuto_partition - implements lomuto partition scheme
 * for quick sort
 * @array: the array to be sorted
 * @low: the index of the low element of the partition
 * @high: the index of the high element of the partition
 * @size: the size of the array
 * Return: the index of the pivot element
 */
int lomuto_partition(int array[], int low, int high, size_t size)
{
	/* choose the last element as the pivot */
	int pivot = array[high];
	/* initialize the index of the smaller element */
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	/* swap the pivot element with element at (i + 1) */
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	/* return the position of the pivot element */
	return (i + 1);
}

/**
 * swap - swaps two integers in an array
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
