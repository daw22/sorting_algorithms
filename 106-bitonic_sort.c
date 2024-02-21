#include "sort.h"
#include <stdio.h>

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		int dir);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int dir);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		int dir)
{
	size_t i, step = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + step; i++)
		{
			if ((dir == 1 && array[i] > array[i + step]) ||
			    (dir == 0 && array[i] < array[i + step]))
				swap_ints(array + i, array + i + step);
		}
		bitonic_merge(array, size, start, step, dir);
		bitonic_merge(array, size, start + step, step, dir);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t half = seq / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, half, 1);
		bitonic_seq(array, size, start + half, half, 0);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size equal to powers of 2
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
