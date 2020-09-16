#include "minishell.h"

char	**cr_prmtrs(char **tmp_line, int size)
{
	char	**prmtrs;
	int		i;

	i = -1;
	prmtrs = malloc(sizeof(char*) * size + 1);
	prmtrs[size] = NULL;
	while (tmp_line[++i])
	{
		prmtrs[i] = ft_strdup(tmp_line[i]);
		free(tmp_line[i]);
	}
	free(tmp_line);
	return (prmtrs);
}

void	free_runcmd(char *cmd, char **prmtrs)
{
	int i;

	i = -1;
	while (prmtrs[++i])
		free(prmtrs[i]);
	free(prmtrs);
	free(cmd);
}

void	for_fttrim(char *c_l, int *i, int *size)
{
	if (is_space(c_l[*i]))
		*i = forspace(c_l, *i, size);
	else if (c_l[*i] == '"')
		*i = forquote(c_l, *i, size);
	else if (c_l[*i] == '\0')
		*size += 1;
}
