#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swapped = 0;

	if (array == NULL || size < 2)
		return;

	while (!swapped)
	{
		swapped = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				swapped = 0;
			}
		}
		len--;
	}
}
