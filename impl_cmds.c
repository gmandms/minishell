#include "minishell.h"

void	cd(char **prmtrs, char **env)
{
	char	*pwd;

	if (size_dac(prmtrs) > 2)
	{
		ft_printf("cd: lot arguments\n");
		return ;
	}
	if (ft_strcmp(prmtrs[0], "cd") == 0)
	{
		if (chdir(prmtrs[1]) == 0)
		{
			pwd = cr_pwd(NULL);
			ch_env(env, pwd, "PWD");
			free(pwd);
			return ;
		}
		else
			ft_printf("cd: 4to-to TToLLlo He Tak\n");
	}
}

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
	else if (ch == 4)
		ft_setenv(envp, prmtrs);
	else if (ch == 5)
		ft_unsetenv(envp, prmtrs);
}

int 	impl_cmd(char *cmd_name)
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

void	my_exe(char *cmd, char **prmtrs, char **env)
{
	char	**paths;
	int 	i;
	char	*rlcmd;

	paths = rec_env_paths(env);
	i = -1;
	if (access(cmd, 0) == 0)
	{
		if (access(cmd, 1) == 0)
		{
			execve(cmd, prmtrs, env);
			return ;
		}
	}
	while (paths[++i])
	{
		rlcmd = path_cmd(cmd, paths[i]);
		if (access(rlcmd, 0) == 0)
		{
			if (access(rlcmd, 1) == 0)
			{
				execve(rlcmd, prmtrs, env);
				return ;
			}
		}
	}
	ft_printf("Permission denied or file not found\n");
}
