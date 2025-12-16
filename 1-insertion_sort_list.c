#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @left: first node
 * @right: second node
 */
static void swap_nodes(listint_t **list,
		listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                        in ascending order using Insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		insert = current;
		current = current->next;

		while (insert->prev && insert->n < insert->prev->n)
		{
			swap_nodes(list, insert->prev, insert);
			print_list(*list);
		}
	}
}

