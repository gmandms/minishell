/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:31:11 by sbump             #+#    #+#             */
/*   Updated: 2020/09/16 21:01:59 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		reverse_check(char *str1, char *str2, int size)
{
	int	i;
	int j;

	i = ft_strlen(str1) - 1;
	j = ft_strlen(str2) - 1;
	while (size > 0 && str1[i] == str2[j])
	{
		size--;
		i--;
		j--;
	}
	return (str1[i + 1] - str2[j + 1]);
}

void	rec_arr(char **arr_trim, char *env_arg)
{
	int	i;
	int j;
	int	l;

	i = -1;
	j = 0;
	l = 0;
	while (env_arg[++i] != '\0')
	{
		if (env_arg[i + 1] == ':' || env_arg[i + 1] == '\0')
		{
			j++;
			arr_trim[l] = ft_strnew(j);
			ft_strncpy(arr_trim[l], env_arg + (i + 1 - j), j);
			j = 0;
			l++;
		}
		if (env_arg[i + 1] == ':')
			i++;
		j++;
	}
}

char	**trim_arg(char *env_arg)
{
	int		i;
	int		size;
	char	**arr_trim;

	size = 0;
	i = -1;
	while (env_arg[++i] != '\0')
	{
		if (env_arg[i] == ':')
			size++;
	}
	if (i > 0)
		size++;
	if (size < 1)
		return (NULL);
	arr_trim = malloc(sizeof(char*) * size + 1);
	arr_trim[size] = NULL;
	rec_arr(arr_trim, env_arg);
	return (arr_trim);
}

char	*find_pwd(char *us_name, char **env)
{
	int		i;
	char	*env_arg;
	char	**arr_args;

	i = 0;
	while (ft_strncmp(env[i], "HOME=", 5) != 0)
		i++;
	env_arg = var_arg(env[i]);
	if (!(arr_args = trim_arg(env_arg)))
		return (NULL);
	i = -1;
	free(env_arg);
	while (arr_args[++i])
	{
		if (reverse_check(us_name, arr_args[i], ft_strlen(us_name)) == 0)
			env_arg = ft_strdup(arr_args[i]);
		free(arr_args[i]);
	}
	free(arr_args);
	if (!env_arg)
		return (NULL);
	else
		return (env_arg);
}
