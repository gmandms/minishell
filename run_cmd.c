#include "minishell.h"

void	for_trim(char *c_l, char ***tmp_line, int size)
{
	int		i;
	int		j;

	init_fortrim(tmp_line, &i, &size);
	while (i < ft_strlen(c_l))
	{
		j = forj(c_l, &i);
		if (j > 0)
		{
			if (is_space(c_l[i]))
				i += frt_space(&c_l[i - j], tmp_line, &size, j);
			else if (c_l[i] == '"')
				i += frt_quote(&c_l[i + 1], tmp_line, &size, j);
			else if (c_l[i] == '\0')
				tmp_line[0][size] = ft_strdup(&c_l[i - j]);
		}
		else
		{
			if (is_space(c_l[i]))
				i = nforspace(c_l, i);
			else if (c_l[i] == '"')
				i += frt_quote2(&c_l[i + 1], tmp_line, &size);
		}
		i = for_frtrim(i, tmp_line, c_l);
	}
}

int		ft_trim(char *c_l, char ***tmp_line)
{
	int		i;
	int		size;
	int		j;

	i = 0;
	size = 0;
	while (c_l[i])
	{
		j = forj(c_l, &i);
		if (j > 0)
			for_fttrim(c_l, &i, &size);
		else
		{
			if (is_space(c_l[i]))
				i = nforspace(c_l, i);
			else if (c_l[i] == '"')
				i = forquote(c_l, i, &size);
		}
		if (i == -1)
			return (0);
	}
	if (size > 0)
		for_trim(c_l, tmp_line, size);
	return (size);
}

char	*path_cmd(char *cmd, char *path)
{
	char *tmp;
	char *str;

	tmp = ft_strjoin("/", cmd);
	str = ft_strjoin(path, tmp);
	free(tmp);
	return (str);
}

int		run_cmd(char *cmd_line, char ***envp)
{
	char	*cmd;
	char	**prmtrs;
	char	**tmp_line;
	int		size;

	size = ft_trim(cmd_line, &tmp_line);
	if (size == 0)
		return (1);
	cmd = ft_strdup(tmp_line[0]);
	if (size == 1 && ft_strcmp(cmd, "exit") == 0)
		return (0);
	prmtrs = cr_prmtrs(tmp_line, size);
	if (impl_cmd(cmd))
		choice(cmd, prmtrs, envp);
	else if (fork() != 0)
		wait(NULL);
	else
	{
		if (!my_exe(cmd, prmtrs, envp[0]))
			return (0);
	}
	free_runcmd(cmd, prmtrs);
	return (1);
}
