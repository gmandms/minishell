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

int		for_size(char *str, char c)
{
	int i;
	int	size;

	i = -1;
	size = 0;
	while (str[++i] != 0)
	{
		if (str[i] == c)
			size++;
	}
	return (size);
}

void	ch_int(int *i, int *j, int *size)
{
	*i = 4;
	*j = 0;
	*size = 0;
}

char	**ft_strtrim2(char *str, char c)
{
	char	**r_arr;
	int		i;
	int		j;
	int		size;

	size = for_size(str, c);
	if (!(r_arr = malloc(sizeof(char*) * size + 1)))
		return (NULL);
	r_arr[size] = NULL;
	ch_int(&i, &j, &size);
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
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] == NULL)
		return (NULL);
	arr_paths = ft_strtrim2(env[i], ':');
	return (arr_paths);
}
