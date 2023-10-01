#include "sort.h"
/**
 * swap_nodes - swap a node for his previous one
 * @node1: first node to swap
 * @list: node list
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (*list == node1)
		*list = node2;
}
/**
 * cocktail_sort_list - this is a cocktail sort implementation
 * working on a double linked lists
 * @list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end = NULL;
	int swapped;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n) 
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else {
				start = start->next;
			}
		}
		end = start;
		while (start->prev != NULL && start->prev != end)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev,start);
				swapped = 1;
				print_list(*list);
			}
			else {
				start = start->prev;
			}
		}
	}
	while (swapped);
}
