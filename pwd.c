#include "minishell.h"

char	*cr_pwd(char *path)
{
	char	*pwd;
	int		size;

	pwd = getcwd(path, PATH_MAX);
	size = ft_strlen(pwd);
	free(pwd);
	pwd = getcwd(path, size);
	return (pwd);
}
