#include "sort.h"
#include <stdio.h>

/**
 * partition - partitions the array to be sorted using the Lomuto scheme
 * @array: the array to partition
 * @start: starting index of the section of the array to be partitioned
 * @end: last index of the section of the array to be partitioned
 * @size: total size of the array (used when printing using print_array)
 *
 * Description: The pivot is always selected as the last number of the array
 * in the Lomuto partitioning scheme
 * Return: the index of the pivot (it's correct position in the sorted array)
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start, j = start;
	int pivot = array[end], tmp;

	while (i < end)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
	if (i != j)
	{
		tmp = array[j];
		array[j] = pivot;
		array[i] = tmp;
		print_array(array, size);
	}
	return (j);
}

/**
 * sort - recursively sorts a given array by partitioning around a pivot
 * @array: the array to be sorted
 * @start: starting index of the section of the array being sorted currently
 * @end: ending index of the section of the array being sorted currently
 * @size: total size of the array (to be used for printing using print_array)
 */
void sort(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end, size);
		sort(array, start, pivot_index - 1, size);
		sort(array, pivot_index + 1, end, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
