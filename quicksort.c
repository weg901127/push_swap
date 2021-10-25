#include "push_swap.h"

static int	partition(int A[], int start, int end)
{
	int	pivot;
	int	i;
	int	index;
	int	temp;

	pivot = A[end];
	index = start;
	i = start;
	while (i < end)
	{
		if (A[i] <= pivot)
		{
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
		i++;
	}
	temp = A[index];
	A[index] = pivot;
	A[end] = temp;
	return (index);
}

void	quicksort(int A[], int start, int end)
{
	int	index;

	if (start < end)
	{
		index = partition(A, start, end);
		quicksort(A, start, index - 1);
		quicksort(A, index + 1, end);
	}
	else
		return ;
}
