#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: pointer to the head of the doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	if (list != NULL && *list != NULL)
	{
		listint_t *ptr = (*list)->next, *iter, *tmp;

		while (ptr)
		{
			iter = ptr;
			while (iter->prev != NULL && iter->n < iter->prev->n)
			{
				tmp = iter->prev;
				iter->prev = iter->prev->prev;
				if (iter->prev)
					iter->prev->next = iter;
				tmp->prev = iter;
				tmp->next = iter->next;
				if (tmp->next)
					tmp->next->prev = tmp;
				iter->next = tmp;
				if (!iter->prev)
					*list = iter;
				print_list(*list);
			}
			ptr = ptr->next;
		}
	}
}
