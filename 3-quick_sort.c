#include "sort.h"

/**
 * swapped_ints - swap two integers from an array
 * @x: integer to be swapped
 * @z: integer to be swapped
 */

void swapped_ints(int *x, int *z)
{
	int temp;

	temp = *x;
	*x = *z;
	*z = temp;
}

/**
 * lomuto_partition - performs lomuto partions to the array
 * @array: array to be sorted
 * @size: size of the array
 * @left: left most element of the array
 * @right: right most element of the array
 *
 * Return: index of the partition
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swapped_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swapped_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - performs quicksort using the lomuto partition
 * @array: array to be sorted
 * @size: size of the array
 * @left: left most element of the array
 * @right: right most element of the array
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - calls quicksort function
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
