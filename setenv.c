#include "minishell.h"

char	*new_var(char *vr_nm, char *vr_arg)
{
	char	*str;
	char	*str2;

	str = ft_strjoin(vr_nm, "=");
	if (vr_arg != NULL)
	{
		str2 = ft_strjoin(str, vr_arg);
		free(str);
		return (str2);
	}
	else
		return (str);
}

char	**new_env(char **env, int size, char *vr_nm, char *vr_arg)
{
	char	**new_env;

	new_env = malloc(sizeof(char*) * (size + 1) + 1);
	new_env[size + 1] = NULL;
	new_env[size] = new_var(vr_nm, vr_arg);
	size = -1;
	while (env[++size])
	{
		new_env[size] = ft_strdup(env[size]);
		free(env[size]);
	}
	free(env);
	return (new_env);
}

char	*new_arg(char *var, char *vr_name, char *vr_arg)
{
	free(var);
	return (new_var(vr_name, vr_arg));
}

void	ft_setenv(char ***env, char **prmtrs)
{
	int		i;
	char	*vr;

	if (size_dac(prmtrs) != 2 && size_dac(prmtrs) != 3)
		ft_printf("Используй 2 или 3 агрумента\n");
	else
	{
		vr = ft_strdup(prmtrs[1]);
		i = 0;
		while (env[0][i] && ft_strncmp(env[0][i], vr, ft_strlen(vr)) != 0)
			i++;
		if (env[0][i] == NULL)
			env[0] = new_env(env[0], i, vr, prmtrs[2]);
		else
			env[0][i] = new_arg(env[0][i], vr, prmtrs[2]);
		free(vr);
	}
}
