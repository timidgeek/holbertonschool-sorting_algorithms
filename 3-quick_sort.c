#include "sort.h"

/**
 * partition - sort the selected section
 * @array: Array of data to be sorted
 * @low: Beggining of the selected list
 * @high: End of the selected list
 * @size: Size of the array
 * Return: index increased from low if there is a swap
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], tmp = 0, i = low - 1, j = low;

	while (j <= high - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	i++;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}

/**
 * quick - recursively sorts
 * @array: Array of data to be sorted
 * @low: Beggining of the selected list
 * @high: End of the selected list
 * @size: Size of the array
 */
void quick(int *array, int low, int high, size_t size)
{
	int p = 0;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quick(array, low, p - 1, size);
		quick(array, p + 1, high, size);
	}
}

/**
 * quick_sort - recursively sorts
 * @array: Array of data to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick(array, 0, size - 1, size);
}
