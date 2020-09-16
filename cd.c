#include "minishell.h"

char	*conc_dir(char *path, char *us_dir)
{
	char	*str;

	str = ft_strjoin(us_dir, &path[1]);
	return (str);
}

char	*user_dir(char **env)
{
	char	*str_dir;
	char	*us_name;
	int		i;
	int		j;

	i = 0;
	while (ft_strncmp("USER=", env[i], 5) != 0)
		i++;
	j = 0;
	while (env[i][j] != '=')
		j++;
	j++;
	us_name = ft_strdup(&env[i][j]);
	str_dir = find_pwd(us_name, env);
	free(us_name);
	return (str_dir);
}

int		home_dir(char **env, char *path, char *old_pwd)
{
	char	*pwd;

	if (chdir(path) == -1)
		return (-1);
	pwd = cr_pwd(NULL);
	ch_env(env, pwd, "PWD");
	free(pwd);
	ch_env(env, old_pwd, "OLDPWD");
	free(old_pwd);
	return (1);
}

void	for_cd(char **prmtrs, char **env)
{
	char	*us_dir;
	int		r;

	us_dir = user_dir(env);
	r = 0;
	if (ft_strcmp(prmtrs[0], "cd") == 0)
	{
		if (size_dac(prmtrs) == 1)
			r = home_dir(env, us_dir, cr_pwd(NULL));
		else if (ft_strcmp("~", prmtrs[1]) == 0)
			r = home_dir(env, us_dir, cr_pwd(NULL));
		else if (ft_strcmp("-", prmtrs[1]) == 0)
		{
			ft_printf("~\n");
			r = home_dir(env, us_dir, cr_pwd(NULL));
		}
		else
			r = fr_else_fcd(prmtrs, us_dir, env);
	}
	if (r == -1)
		ft_printf("cd: no such file or directory\n");
	free(us_dir);
}

void	cd(char **prmtrs, char **env)
{
	if (size_dac(prmtrs) > 2)
	{
		ft_printf("cd: lot arguments\n");
		return ;
	}
	for_cd(prmtrs, env);
}
