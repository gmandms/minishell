#include "minishell.h"

void	for_trim(char const *cmd_line, char ***tmp_line, int size)
{
	int		i;
	int 	j;

	tmp_line[0] = malloc(sizeof(char*) * size + 1);
	tmp_line[0][size] = NULL;
	i = 0;
	j = 0;
	size = 0;
	while (i <= ft_strlen(cmd_line))
	{
		if (cmd_line[i] == ' ' || cmd_line[i] == '\0')
		{
			tmp_line[0][j] = ft_strnew(size);
			ft_strncpy(tmp_line[0][j], &cmd_line[i - size], size);
			size = 0;
			j++;
		}
		if (cmd_line[i] != ' ' && cmd_line[i] != '\0' && cmd_line[i] != '\r')
			size++;
		i++;
	}
}

int		ft_trim(char const *cmd_line, char ***tmp_line)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == ' ' || cmd_line[i + 1] == '\0')
			size++;
		i++;
	}
	if (size > 0)
		for_trim(cmd_line, tmp_line, size);
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

int 	run_cmd(char *cmd_line, char ***envp)
{
	char	*cmd;
	char	**prmtrs;
	char	**tmp_line;
	int		size;
	int		i;

	size = ft_trim(cmd_line, &tmp_line);
	if (size == 0)
		return (1);
	cmd = ft_strdup(tmp_line[0]);
	i = -1;
	if (size == 1 && ft_strcmp(cmd, "exit") == 0)
		return (0);
	prmtrs = malloc(sizeof(char*) * size + 1);
	prmtrs[size] = NULL;
	while (tmp_line[++i])
		prmtrs[i] = ft_strdup(tmp_line[i]);
	if (impl_cmd(cmd))
		choice(cmd, prmtrs, envp);
	else if (fork() != 0)
		wait(NULL);
	else
		my_exe(cmd, prmtrs, envp[0]);
	return (1);
}
