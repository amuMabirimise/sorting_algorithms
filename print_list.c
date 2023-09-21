#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers.
 * @list: Pointer to the head of the list.
 */
void print_list(const listint_t *list)
{
	const listint_t *current = list;
	int comma_flag = 0;

	while (current != NULL)
	{
	if (comma_flag)
	{
		printf(", ");
	}
		printf("%d", current->n);
		comma_flag = 1;
		current = current->next;
	}
	printf("\n");
}
