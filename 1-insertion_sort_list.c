#include "sort.h"

/**
 * swap_head - swaps a node at the beggining of the list
 * @list: Doubly linked list with nodes to sort acording to number n.
 * @aux: auxiliar node to compare
 */
void swap_head(listint_t **list, listint_t *aux)
{
	aux->prev->next = aux->next;
	if (aux->next)
		aux->next->prev = aux->prev;
	aux->next = aux->prev;
	aux->prev = aux->prev->prev;
	aux->next->prev = aux;
	*list = aux;
}

/**
 * swap_middle - swaps a node at the middle of the list
 * @aux: auxiliar node to compare
 */
void swap_middle(listint_t *aux)
{
	aux->prev->next = aux->next;
	aux->next->prev = aux->prev;
	aux->prev->prev->next = aux;
	aux->next = aux->prev;
	aux->prev = aux->next->prev;
	aux->next->prev = aux;
}

/**
 * swap_tail - swaps a node at the end of the list
 * @aux: auxiliar node to compare
 */
void swap_tail(listint_t *aux)
{
	aux->prev->next = aux->next;
	aux->next = aux->prev;
	aux->prev->prev->next = aux;
	aux->prev = aux->next->prev;
	aux->next->prev = aux;
}

/**
 * insertion_sort_list - sorting algorithm
 * @list: Doubly linked list with nodes to sort acording to number n.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL;
	int i = 0, j = 0;

	if (!list || !(*list)->next)
		return;
	aux = (*list)->next;
	while (aux)
	{
		i++;
		while (aux->prev)
		{
			if (aux->prev->n > aux->n)
			{
				if (!aux->prev->prev)
					swap_head(list, aux);
				else if (aux->prev->prev && aux->next)
					swap_middle(aux);
				else if (!aux->next)
					swap_tail(aux);
				print_list(*list);
			}
			else
				aux = aux->prev;
		}
		while (j <= i)
		{
			aux = aux->next;
			j++;
		}
		j = 0;
	}
}
