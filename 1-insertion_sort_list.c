#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list via insertion sort
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *start, *tmp, *prev_n;

	tmp = NULL;
	start = *list;
	/* rev = NULL; */

	/* s_val = start->n; */

	if (start)
		if (!start->next)
			return;
	while (start->next)
	{
		tmp = start->next;
		if (start->n <= tmp->n) /* best case scenario */
			start = tmp;
		else /* smaller value encountered */
		{
			while (tmp->n < start->n)
			{
				prev_n = start->prev; /* previous start pointer */

				start->next = tmp->next; /*detach tmp */
				if (tmp->next)
					tmp->next->prev = start;

				tmp->prev = prev_n; /* attach tmp to prev_n */
				tmp->next = start;

				start->prev = tmp;
				if (prev_n)
					prev_n->next = tmp;
				start = prev_n ? prev_n : tmp;
				*list = prev_n ? *list : tmp;
				print_list(*list);
				if (!prev_n)
					break;
			}
		}
	}
}
