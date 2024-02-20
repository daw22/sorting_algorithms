#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * counting sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, max = 0, i, j = 0;

	for (i = 0; (size_t) i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_arr = malloc(sizeof(int) * (max + 1));
	if (count_arr)
	{
		for (i = 0; i <= max; i++)
			count_arr[i] = 0;
		for (i = 0; (size_t) i < size; i++)
			count_arr[array[i]] += 1;
		for (i = 1; i <= max; i++)
			count_arr[i] += count_arr[i - 1];
		print_array(count_arr, max + 1);
		for (i = 0; i <= max; i++)
		{
			while (j < count_arr[i])
			{
				array[j] = i;
				j++;
			}
		}
		free(count_arr);
	}
}
