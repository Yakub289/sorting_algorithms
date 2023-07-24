#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
 * insertion_sort_list - Write a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 * @list : linked pointer.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *swap_element, *next_element;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	swap_element = (*list)->next;

	while (swap_element != NULL)
	{
		next_element = swap_element->next;

		while (swap_element->prev != NULL &&
				swap_element->prev->n > swap_element->n)
		{
			swap_element->prev->next = swap_element->next;

			if (swap_element->next != NULL)
			{
				swap_element->next->prev = swap_element->prev;
				swap_element->next = swap_element->prev;
				swap_element->prev = swap_element->next->prev;
				swap_element->next->prev = swap_element;

				if (swap_element->prev == NULL)
				{
					*list = swap_element;
				}
				else
				{
					swap_element->prev->next = swap_element;
				}
				print_list(*list);
			}
		} swap_element = next_element;
	}
}
