#include "minishell.h"

char	*ft_strcdup(const char *str, char c)
{
	char	*r_str;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	r_str = ft_strnew(i);
	i = -1;
	while (str[++i] != '\0' && str[i] != c)
		r_str[i] = str[i];
	return (r_str);
}

char	**ft_strtrim2(char *str, char c)
{
	char	**r_arr;
	int		i;
	int 	j;
	int		size;

	i = -1;
	size = 0;
	while (str[++i] != 0)
	{
		if (str[i] == c)
			size++;
	}
	if (!(r_arr = malloc(sizeof(char*) * size + 1)))
		return (NULL);
	r_arr[size] = NULL;
	i = 4;
	j = 0;
	size = 0;
	while (++i)
	{
		if (str[i] == '\0' || str[i] == c)
		{
			r_arr[size] = ft_strcdup(&str[i - j], c);
			if (str[i] == '\0')
				break ;
			j = 0;
			size++;
		}
		else
			j++;
	}
	return (r_arr);
}

char	**rec_env_paths(char **env)
{
	int		i;
	char	**arr_paths;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	arr_paths = ft_strtrim2(env[i], ':');
	return (arr_paths);
}
