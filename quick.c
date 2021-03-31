#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void			ft_swap(int* a, int* b, int *cmp)
{
    int			tmp;
	
	tmp = *a;
    *a = *b;
    *b = tmp;
	if (*a != *b)
		(*cmp)++;
	printf("cmp : [ %d ]\n", *cmp);
}

int				partition(int array[], int start, int end, int *cmp)
{
	int			x;
	int			i;
	int			j;

	x = array[end];
	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] <= x)
		{
			i++;
			//printf("------------------------------------------------------\n");
			//printf("array[i] : [ %d ]\n", array[i]);
			//printf("array[j] : [ %d ]\n", array[j]);
			//printf("------------------------------------------------------\n");
			ft_swap(&array[i], &array[j], cmp);
		}
	}
	ft_swap(&array[i + 1], &array[end], cmp);
	return (i + 1);
}

void			quickSort(int array[], int start, int end, int *cmp)
{
	if (start < end)
	{
		int p = partition(array, start, end, cmp);
		quickSort(array, start, p - 1, cmp);
		quickSort(array, p + 1, end, cmp);
	}
}

void			ft_random_nbr(int array[500], int n)
{
	int		cmp;
	int		nbr;

	cmp = 0;
	struct timeval tpstart;
	gettimeofday(&tpstart, NULL);
	srand(tpstart.tv_usec); 
	while (cmp < n)
	{
		nbr = 0;
		nbr = rand() % 800;
		array[cmp] = nbr;
		cmp++;
	}
}

int				main()
{
	int			n;
	int			cmp;
	int			array[500];

	n = 500;
	cmp = 0;
	ft_random_nbr(array, n);
	quickSort(array, 0, n - 1, &cmp);
	for (int i = 0; i < n; i++)
	{
		//printf("array[ %d ] : [ %d ]\n", i, array[i]);
	}
	printf("cmp : [ %d ]\n", cmp);
	return 0;
}