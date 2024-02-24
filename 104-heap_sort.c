#include <stddef.h>
#include "sort.h"

/**
 * max_heapify - intrinsically creates a max heap from a given array
 * @array: the array to be heapified
 * @size: size of the array to be heapified
 */
void max_heapify(int *array, size_t size)
{
	int init = (size / 2) - 1, tmp;
	size_t curr, child1, child2, max, swapped;

	while (init >= 0)
	{
		swapped = 1;
		curr = init;
		child1 = (2 * curr) + 1;
		child2 = (2 * curr) + 2;
		while (swapped && (child1 < size || child2 < size))
		{
			swapped = 0;
			max = child1;
			if (child2 < size && array[child2] > array[child1])
				max = child2;
			if (array[curr] < array[max])
			{
				tmp = array[curr];
				array[curr] = array[max];
				array[max] = tmp;
				swapped = 1;
				print_array(array, size);
				curr = max;
				child1 = (2 * curr) + 1;
				child2 = (2 * curr) + 2;
			}
		}
		init--;
	}
}

/**
 * sift_down - sifts down the first element of an array to its place in the
 * intrinsic max heap
 * @array: the array to be modified
 * @unsorted_size: size of the part of the array that remains unsorted
 * @full_size: actual size of the array (used for printing when a swap occurs)
 */
void sift_down(int *array, size_t unsorted_size, size_t full_size)
{
	size_t curr = 0, child1 = 1, child2 = 2, max, tmp, sifted = 1;

	while (sifted && (child1 < unsorted_size || child2 < unsorted_size))
	{
		sifted = 0;
		max = child1;
		if (child2 < unsorted_size && array[child2] > array[child1])
			max = child2;
		if (array[curr] < array[max])
		{
			tmp = array[curr];
			array[curr] = array[max];
			array[max] = tmp;
			sifted = 1;
			curr = max;
			child1 = (2 * curr) + 1;
			child2 = (2 * curr) + 2;
			print_array(array, full_size);
		}
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void heap_sort(int *array, size_t size)
{
	if (array)
	{
		size_t i;
		int tmp;

		max_heapify(array, size);
		for (i = 0; i < size - 1; i++)
		{
			tmp = array[0];
			array[0] = array[size - 1 - i];
			array[size - 1 - i] = tmp;
			print_array(array, size);
			sift_down(array, size - i - 1, size);
		}
	}
}
