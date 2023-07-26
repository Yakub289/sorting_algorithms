#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
* partition - finds the partition for  quicksort using the Hoare scheme
* @array: array to sort
* @bottom: last index of the partition to sort
* @top: first index of the partition to sort
* @size: size of the array
* Return: index of the partition
*/
size_t partition(int *array, ssize_t bottom, ssize_t top, size_t size)
{
	int swap, pivot;

	pivot = array[top];
	while (bottom <= top)
	{
		while (array[bottom] < pivot)
			bottom++;
		while (array[top] > pivot)
			top--;
		if (bottom <= top)
		{
			if (bottom != top)
			{
				swap = array[bottom];
				array[bottom] = array[top];
				array[top] = swap;
				print_array(array, size);
			}
			bottom++;
			top--;
		}
	}
	return (top);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @bottom: last index of the partition to sort
 * @top: first index of the partition to sort
 * @size: size of the array
 */
void quicksort(int *array, ssize_t bottom, ssize_t top, size_t size)
{
	ssize_t place_holder;

	if (bottom < top)
	{
		place_holder = partition(array, bottom, top, size);
		quicksort(array, bottom, place_holder, size);
		quicksort(array, place_holder + 1, top, size);

	}
}

/**
* quick_sort_hoare - sorts an array of integers in ascending order using the
* Quick sort algorithm
* @array: The array to sort
* @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
