#include "minishell.h"

int	size_dac(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
