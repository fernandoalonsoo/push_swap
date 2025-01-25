
#include "../push_swap.h"
#include "./utils/utils.h"

int main(int argc, char const *argv[])
{
	int **a;
	int **b;
	int	n;

	if (argc == 1)
	{
		ft_print_string("Número de argumentos invalido. Uso: ./push_swap <lista de enteros>");
		exit(1);
	}
	n = argc - 1;
	a = malloc(n * sizeof(int *));
	b = malloc(n * sizeof(int *));
	initialise_stacks(a, b, n, argv);
	
	return 0;
}
