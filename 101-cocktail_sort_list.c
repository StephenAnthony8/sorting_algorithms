#include "sort.h"
/**
 * cocktail_sort_list - sorts unordered lists via cocktail sort algorithm
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *start_p, *end_p = NULL;
	size_t count = 0, i;

	if ((!list) || !(*list) || (!(*list)->next))
		return;

	start_p = start = *list;
	while (start)
	{
		if (start->next != end_p)
		{
			if (start->n < start->next->n)
				start = start->next;
			else/* increasing switch function */
			{
				*list = (swap_node_forward(start) == 1 ? start->prev : *list);
				print_list(*list);
			}
		}
		else if (start->next == end_p)
		{
			end_p = (end_p ? end_p->prev : start);
			while (start->prev && start != start_p)
			{
				if (start->n > start->prev->n)
					start = start->prev;
				else/* decreasing switch function */
				{
					*list = (swap_node_reverse(start) == 1 ? start : *list);
					print_list(*list);
				}
			}
			count++;
		}
		if (start_p == end_p || start_p->next == end_p)
			break;
		start_p = *list;
		for (i = 0; i < count; i++)
			start_p = start_p->next;
	}
}
/**
 * swap_node_forward - swaps current node with next node
 * @list: node to be swapped
 * Return: 1 if the list is at the head or 0 if not
 */
int swap_node_forward(listint_t *list)
{
	listint_t *first_n, *second_n;
	int check = 0;

	if (!list->prev)
		check++;

	first_n = list;
	second_n = list->next;

	if (first_n->prev)
		first_n->prev->next = second_n;
	second_n->prev = first_n->prev;

	if (second_n->next)
		second_n->next->prev = first_n;
	first_n->next = second_n->next;

	first_n->prev = second_n;
	second_n->next = first_n;
	return (check);

}
/**
 * swap_node_reverse - swaps current node with previous node
 * @list: node to be swapped
 * Return: 1 if the list is at the head or 0 if not
 */
int swap_node_reverse(listint_t *list)
{
	listint_t *first_n, *second_n;
	int check = 0;


	first_n = list;
	second_n = list->prev;

	if (first_n->next)
		first_n->next->prev = second_n;
	second_n->next = first_n->next;

	if (second_n->prev)
		second_n->prev->next = first_n;
	first_n->prev = second_n->prev;

	first_n->next = second_n;
	second_n->prev = first_n;

	if (!first_n->prev)
		check++;
	return (check);
}
