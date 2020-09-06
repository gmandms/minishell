#include "minishell.h"

void	rec_cmdline(char **cmd_line, int size, char c)
{
	char	*tmp;

	if (cmd_line[0])
	{
		tmp = ft_strdup(cmd_line[0]);
		free(cmd_line[0]);
	}
	else if (size == 1)
	{
		cmd_line[0] = ft_strnew(size);
		cmd_line[0][size - 1] = c;
		return ;
	}
	cmd_line[0] = ft_strnew(size);
	ft_strncpy(cmd_line[0], tmp, size - 1);
	cmd_line[0][size - 1] = c;
}

void	read_cmdline(char **cmd_line)
{
	int		size;
	char	c;

	size = 1;
	while (1)
	{
		if (read(0, &c, 1) == -1)
			break ;
		if (c == '\n')
			break ;
		rec_cmdline(cmd_line, size, c);
		size++;
	}
}
