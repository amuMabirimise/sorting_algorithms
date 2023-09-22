#include <stdio.h>
#include "sort.h"

/**
 * swap_int - Swaps two integer elements in an array.
 * @c: Pointer to the first element.
 * @d: Pointer to the second element.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
	if (array[j] <= pivot)
	{
		i++;
		swap_int(&array[i], &array[j]);
		if (i != j)
		printf("Swap: %d <--> %d\n", array[i], array[j]);
	}
	}
	swap_int(&array[i + 1], &array[high]);
	if ((i + 1) != high)
	printf("Swap: %d <--> %d\n", array[i + 1], array[high]);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
	int pivot_idx = partition(array, low, high);

	quick_sort_recursive(array, low, pivot_idx - 1);
	quick_sort_recursive(array, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	return;

	quick_sort_recursive(array, 0, size - 1);
}
