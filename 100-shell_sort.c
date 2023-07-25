#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
 * _swap - swaped 2 values.
 * @array: the array for swap him values.
 * @i: First index
 * @j: Second index
 * Return: Nothing
 */
void _swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * shell_sort - Write a function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the Knuth sequence.
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t s = 0,  i, j;

	if (size < 2)
		return;

	while (s <= size / 3)
		s = s * 3 + 1;

	while (s >= 1)
	{
		for (i = s; i < size; i++)
			for (j = i; j >= s && array[j] < array[j - s]; j -= s)
				_swap(array, j, j - s);
		s /= 3;
		print_array(array, size);
	}
}
