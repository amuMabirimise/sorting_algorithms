#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Insertion Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *prev_node;
	if (!list || !(*list) || !(*list)->next)
	return;

	while (current)
	{
		prev_node = current->prev;
		while (prev_node && current->n < prev_node->n)
		{
			if (prev_node->prev)
			prev_node->prev->next = current;
			if (current->next)
			current->next->prev = prev_node;
			prev_node->next = current->next;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			current->next = prev_node;

			if (!current->prev)
			*list = current;

			print_list(*list);
			prev_node = current->prev;
		}
		current = current->next;
	}
}
