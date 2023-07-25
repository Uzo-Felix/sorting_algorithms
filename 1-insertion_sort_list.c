#include "sort.h"

/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @x: A pointer to the head of the doubly-linked list.
 * @y: A pointer to the first node to swap.
 * @y2: The second node to swap.
 */
void swap(listint_t **x, listint_t **y, listint_t *y2)
{
	(*y)->next = y2->next;
	if (y2->next != NULL)
		y2->next->prev = *y;
	y2->prev = (*y)->prev;
	y2->next = *y;
	if ((*y)->prev != NULL)
		(*y)->prev->next = y2;
	else
		*x = y2;
	(*y)->prev = y2;
	*y = y2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
