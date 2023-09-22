#include "sort.h"
#include <stdio.h>

/**
 * swap_int - the two numbers are swapped
 * @c: the array for swap
 * @d: the array for swap
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sort integers in an ascending order
 * @array: pointer to array to sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_value;

	for (i = 0; i < size - 1; i++)
	{
		min_value = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_value])
				min_value = j;
		if (min_value != i)
		{
			swap_int(&array[min_value], &array[i]);
			print_array(array, size);
		}
	}
}
