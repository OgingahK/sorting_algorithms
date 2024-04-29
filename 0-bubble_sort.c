#include "sort.h"

/**
 * swap - wap two integers
 * @x: first integer
 * @z: second integer
 */

void swap(int *x, int *z)
{
	int temp;

	temp = *x;
	*x = *z;
	*z = temp;
}

/**
 * bubble_sort - sort array in ascending order
 * @array: sorted array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}
