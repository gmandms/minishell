#include "minishell.h"

void	env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
}

void	choice(char *cmd, char **prmtrs, char ***envp)
{
	int	ch;

	ch = impl_cmd(cmd);
	if (ch == 1)
		env(envp[0]);
	else if (ch == 2)
		cd(prmtrs, envp[0]);
	else if (ch == 3)
		ft_echo(prmtrs, envp[0]);
	else if (ch == 4)
		ft_setenv(envp, prmtrs);
	else if (ch == 5)
		ft_unsetenv(envp, prmtrs);
}

int		impl_cmd(char *cmd_name)
{
	if (ft_strcmp(cmd_name, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "cd") == 0)
		return (2);
	else if (ft_strcmp(cmd_name, "echo") == 0)
		return (3);
	else if (ft_strcmp(cmd_name, "setenv") == 0)
		return (4);
	else if (ft_strcmp(cmd_name, "unsetenv") == 0)
		return (5);
	else
		return (0);
}

int		first_access(char *cmd, char **prmtrs, char **env)
{
	if (access(cmd, 0) == 0)
	{
		if (access(cmd, 1) == 0)
		{
			execve(cmd, prmtrs, env);
			return (1);
		}
	}
	return (0);
}

int		my_exe(char *cmd, char **prmtrs, char **env)
{
	char	**paths;

	if (!(paths = rec_env_paths(env)))
	{
		if (first_access(cmd, prmtrs, env) == 1)
			return (1);
		else
		{
			ft_printf("Permission denied or file not found\n");
			free_runcmd(cmd, prmtrs);
			return (0);
		}
	}
	if (first_access(cmd, prmtrs, env) == 1)
		return (1);
	if (while_myexe(cmd, prmtrs, env, paths) == 1)
		return (1);
	free_dac(paths);
	ft_printf("Permission denied or file not found\n");
	free_runcmd(cmd, prmtrs);
	return (0);
}
