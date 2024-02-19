#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers using the shell sort algorithm with
 * the Knuth sequence to generate the gaps/intervals
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	int gap = 0, i, j, k, curr, tmp;

	while (gap < (int) size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = 0; i < gap; i++)
		{
			j = i;
			while (j < (int) size)
			{
				k = j;
				curr = array[j];
				while ((k - gap) >= 0 && array[k - gap] > curr)
				{
					tmp = array[k - gap];
					array[k - gap] = curr;
					array[k] = tmp;
					k -= gap;
				}
				j += gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
