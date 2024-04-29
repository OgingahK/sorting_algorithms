#include "sort.h"

/**
 * swapped_nodes - two nodes swapped from a doubly-linked list
 * @a: doubly-linked loist pointer
 * @n1: first swapped node pointer
 * @n2: second swapped node
 */

void swapped_nodes(listint_t **a, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*a = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: doubly-linked list pointer
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (currentNode = (*list)->next; currentNode != NULL; currentNode = temp)
	{
		temp = currentNode->next;
		insert = currentNode->prev;
		while (insert != NULL && currentNode->n < insert->n)
		{
			swapped_nodes(list, &insert, currentNode);
			print_list((const listint_t *)*list);
		}
	}
}
