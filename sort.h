#ifndef _SORT_H_
#define _SORT_H_

/* libraries */

#include <stdio.h>
#include <stdlib.h>

/* structures */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* prototypes */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
int partition(int *array, int low, int high, size_t size);
void array_swap(int *array, int a, int b);
void swap_head(listint_t **list, listint_t *aux);
void swap_middle(listint_t *aux);
void swap_tail(listint_t *aux);
void quick(int *array, int low, int high, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

#endif/* _SORT_H_ */
