
#include "../push_swap.h"

int	initialise_stacks(int **a, int **b, int n, char const *argv[])
{
	int i;

	if (!*a || !*b)
        return -1;

	i = 0;
	while (i < n)
	{
		a[i] = ft_atoi(argv[i + 1]);
		b[i] = 0;
	}
	
}