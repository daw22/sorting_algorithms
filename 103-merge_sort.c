#include "sort.h"
#include <stdio.h>

/**
 * merge_arr - sort sub-array
 * @arr: sub-array to be sort
 * @temp: an array to store the sorted ints
 * @start: start index of the sub_array
 * @middle: the middle index of sub-array
 * @last: the last index of the sub-array
 */
void merge_arr(int *arr, int *temp, int start, int middle, int last)
{
	int i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + start, middle - start);
	printf("[right]: ");
	print_array(arr + middle, last - middle);

	for (i = start, j = middle; i < middle && j < last; k++)
		temp[k] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	for (; i < middle; i++)
		temp[k++] = arr[i];
	for (; j < last; j++)
		temp[k++] = arr[j];
	for (i = start, k = 0; i < last; i++)
		arr[i] = temp[k++];
	printf("[Done]: ");
	print_array(arr + start, last - start);
}

/**
 * sort_rec - sorts the array recursively
 * @arr: a subarray of integers
 * @temp: an array to store the sorted ints
 * @start: start index of the sub-array
 * @last: last index of the sub-array
 */
void sort_rec(int *arr, int *temp, int start, int last)
{
	int middle;

	if (last - start > 1)
	{
		middle = start + (last - start) / 2;
		sort_rec(arr, temp, start, middle);
		sort_rec(arr, temp, middle, last);
		merge_arr(arr, temp, start, middle, last);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending
 * order using merge sort algorithm
 * @array: arry to sort
 * @size: size of the array to sort
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	sort_rec(array, temp, 0, size);
	free(temp);
}
