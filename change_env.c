#include "minishell.h"

void	ch_envlvl(char **arr, int i, char *varname)
{
	int		lvl;
	char	*var;

	lvl = 0;
	while (arr[i][lvl] != '=')
		lvl++;
	lvl++;
	var = ft_strnew(ft_strlen(arr[i]) - lvl);
	ft_strncpy(var, &arr[i][lvl], ft_strlen(arr[i]) - lvl);
	lvl = ft_atoi(var);
	lvl++;
	free(var);
	var = ft_itoa(lvl);
	free(arr[i]);
	arr[i] = ft_strjoin(varname, var);
	free(var);
}

void	ch_enveq(char **arr, int i, char *varargs, char *varname)
{
	char	*var;
	char	*vn;

	vn = ft_strjoin(varname, "=");
	var = ft_strjoin(vn, varargs);
	free(arr[i]);
	free(vn);
	arr[i] = ft_strdup(var);
	free(var);
}

void	ch_env(char **arr, char *varargs, char *varname)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(varname);
	while (arr[i])
	{
		if (ft_strncmp(arr[i], varname, len) == 0)
		{
			ch_enveq(arr, i, varargs, varname);
			break ;
		}
		i++;
	}
}
