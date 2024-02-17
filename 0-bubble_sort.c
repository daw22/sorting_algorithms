#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapped;
	int tmp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
