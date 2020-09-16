#include "minishell.h"

void	prompt(char **env)
{
	int		i;
	char	*user_name;
	char	*dir_name;
	char	*home_name;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("USER", env[i], 4) == 0)
			user_name = ft_strdup(env[i] + 5);
		else if (ft_strncmp("HOME=", env[i], 5) == 0)
			home_name = ft_strdup(env[i] + 5);
		else if (ft_strncmp("PWD", env[i], 3) == 0)
			dir_name = cr_pwd(NULL);
		i++;
	}
	if (ft_strcmp(home_name, dir_name) == 0)
	{
		free(dir_name);
		dir_name = ft_strdup("~");
	}
	ft_printf("%s %s $> ", user_name, dir_name);
	free(user_name);
	free(dir_name);
	free(home_name);
}

int		main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	char	**envcp;
	int		i;

	if (argc != 1)
		return (0);
	cr_env(&envcp, envp, argv);
	while (1)
	{
		prompt(envcp);
		read_cmdline(&cmd_line);
		if (!cmd_line)
			ft_printf("");
		else if (ft_strcmp(cmd_line, "\n") != 0 && !run_cmd(cmd_line, &envcp))
			break ;
		free(cmd_line);
	}
	i = 0;
	while (envcp[i])
	{
		free(envcp[i]);
		i++;
	}
	free(envcp);
	return (0);
}
