#include "sort.h"

/**
 * swapped_ints - swap two integers in an array
 * @a: integer to be swapped
 * @b: integer to be swapped
 */

void swapped_ints(int *x, int *z)
{
	int temp;

	temp = *x;
	*x = *z;
	*z = temp;
}

void selection_sort(int *array, size_t size)
{
	int *minPtr;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		minPtr = array + a;
		for (b = a + 1; b < size; b++)
			minPtr = (array[b] < *minPtr) ? (array + b) : minPtr;

		if ((array + a) != minPtr)
		{
			swapped_ints(array + a, minPtr);
			print_array(array, size);
		}
	}
}
