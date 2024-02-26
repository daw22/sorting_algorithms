#include <stdlib.h>
#include "sort.h"

/**
 * get_max_digit - gets the max number of digits from the numbers in an array
 * @array: the array of integers
 * @size: size of the array
 *
 * Return: The number of digits of the maximum element in the array
 */
size_t get_max_digit(int *array, size_t size)
{
	size_t i, max_digit = 1, curr_digit = 0;
	int max_number = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_number)
			max_number = array[i];
	}
	while (max_number)
	{
		max_number /= 10;
		curr_digit += 1;
	}
	if (curr_digit > max_digit)
		max_digit = curr_digit;
	return (max_digit);
}

/**
 * calc_power - calculates and returns result of exponentiation
 * @base: the base of the exponentiation expression
 * @expt: the exponent
 *
 * Return: base ^ expt
 */
long int calc_power(int base, int expt)
{
	long int result = 1;

	while (expt)
	{
		result *= base;
		expt--;
	}
	return (result);
}

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * radix sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 */
void radix_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
	size_t digits = get_max_digit(array, size), i;
	int *aux_arr = malloc(sizeof(int) * size);
	int *dgt_cnt = malloc(sizeof(int) * 11);

	for (i = 1; i <= digits; i++)
	{
		size_t j;
		long int div = calc_power(10, i);

		for (j = 0; j < 11; j++)
			dgt_cnt[j] = 0;
		for (j = 0; j < size; j++)
		{
			aux_arr[j] = array[j];
			dgt_cnt[1 + ((array[j] % div) / (div / 10))] += 1;
		}
		for (j = 1; j < 11; j++)
			dgt_cnt[j] += dgt_cnt[j - 1];
		for (j = 0; j < size; j++)
		{
			size_t idx = dgt_cnt[(aux_arr[j] % div) / (div / 10)];

			array[idx] = aux_arr[j];
			dgt_cnt[(aux_arr[j] % div) / (div / 10)] += 1;
		}
		print_array(array, size);
	}
	}
}
