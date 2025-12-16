#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array of integers
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the array
 *
 * Return: final pivot position
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - recursively applies quick sort
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using Quick sort (Lomuto)
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

