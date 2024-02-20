#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps places of two nodes of a doubly linked list
 * @list: pointer to a pointer to the first node of the list
 * @n1: pointer to first of the nodes to swap
 * @n2: pointer to second of the nodes to swap
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	n1->next = n2->next;
	if (n1->next)
		n1->next->prev = n1;
	n2->next = n1;
	n2->prev = n1->prev;
	if (n2->prev)
		n2->prev->next = n2;
	n1->prev = n2;
	if (!(n2->prev))
		*list = n2;
}


/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order of the n
 * value of the nodes using the cocktail sorting algorithm
 * @list: pointer to a pointer to the first node of the list
 */
void cocktail_sort_list(listint_t **list)
{
	size_t size = 0, i, j, swapped;
	listint_t *ptr = *list, *iter;

	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	iter = *list;
	j = 0;
	for (i = 0; i < size; i++)
	{
		swapped = 0;
		while (j < size - 1 - i)
		{
			if (iter->n > iter->next->n)
			{
				swap_nodes(list, iter, iter->next);
				print_list(*list);
				swapped = 1;
			}
			else
				iter = iter->next;
			j++;
		}
		iter = iter->prev;
		while (j > (i + 1))
		{
			if (iter->n < iter->prev->n)
			{
				swap_nodes(list, iter->prev, iter);
				print_list(*list);
				swapped = 1;
			}
			else
				iter = iter->prev;
			j--;
		}
		iter = iter->next;
		if (!swapped)
			break;
	}
}
