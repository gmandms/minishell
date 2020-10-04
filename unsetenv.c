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

char	**del_var(char **env, int i, int size)
{
	char	**new_env;
	int		j;

	new_env = malloc(sizeof(char*) * (size - 1) + 1);
	new_env[size - 1] = NULL;
	size = 0;
	j = 0;
	while (env[size])
	{
		if (size == i)
			free(env[size++]);
		else
		{
			new_env[j++] = ft_strdup(env[size]);
			free(env[size++]);
		}
	}
	free(env);
	return (new_env);
}

void	ft_unsetenv(char ***env, char **prmtrs)
{
	int		i;
	char	*vr_name;

	i = 0;
	if (size_dac(prmtrs) != 2)
	{
		ft_printf("Используй два парамера [команда] [имя_переменной]\n");
		return ;
	}
	else
		vr_name = ft_strdup(prmtrs[1]);
	while (env[0][i])
	{
		if (ft_strncmp(env[0][i], vr_name, ft_strlen(vr_name)) == 0)
		{
			env[0] = del_var(env[0], i, size_dac(env[0]));
			break ;
		}
		i++;
	}
	free(vr_name);
}
