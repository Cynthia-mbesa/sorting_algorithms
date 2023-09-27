#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: points to the head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;


	while (curr != NULL)
	{
		listint_t *temp = curr->next;
		listint_t *prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			if (curr->next != NULL)
				curr->next->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = curr;

			prev->next = curr->next;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;
			print_list(*list);
			prev = curr->prev;
		}
		curr = temp;
	}
}
