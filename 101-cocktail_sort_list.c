#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || !list || !(*list))
		return;

	if (node1->prev)
	node1->prev->next = node2;
	if (node2->next)
	node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (!node1->prev)
	*list = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
	swapped = 0;
	current = *list;

	while (current->next != NULL)
	{
		if (current->n > current->next->n)
	{
		swap_nodes(list, current, current->next);
		print_list(*list);
		swapped = 1;
	}
		else
	current = current->next;
	}

	if (!swapped)
	break;

	swapped = 0;
	current = current->prev;

	while (current->prev != NULL)
	{
	if (current->n < current->prev->n)
	{
		swap_nodes(list, current->prev, current);
		print_list(*list);
		swapped = 1;
	}
	else
		current = current->prev;
	}
	} while (swapped);
}

