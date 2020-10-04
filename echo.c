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

char	*varname(char *full_name)
{
	char	*name;
	int		i;

	i = ft_strlen(full_name);
	i -= 1;
	if (full_name[1] == '{' && full_name[i] == '}')
	{
		name = ft_strnew(i - 2);
		ft_strncpy(name, full_name + 2, i - 2);
	}
	else
	{
		name = ft_strnew(i);
		ft_strncpy(name, full_name + 1, i);
	}
	return (name);
}

char	*var_arg(char *env_var)
{
	int		i;
	char	*arg;

	i = 0;
	if (env_var == NULL)
		return (NULL);
	while (env_var[i] != '=' && env_var[i] != '\0')
		i++;
	if (env_var[i++] == '\0')
		return (NULL);
	arg = ft_strnew(ft_strlen(env_var) - i);
	ft_strncpy(arg, env_var + i, ft_strlen(env_var) - i);
	return (arg);
}

int		isitvar(char *full_name, char **env)
{
	char	*name;
	int		i;

	if (full_name[0] == '$')
	{
		name = varname(full_name);
		i = 0;
		while (env[i] && ft_strncmp(name, env[i], ft_strlen(name)) != 0)
			i++;
		free(name);
		return (i);
	}
	return (0);
}

void	echo_print(char **prmtrs, char **env, int fl_n)
{
	int		i;
	int		j;
	char	*print_str;

	i = 0;
	while (prmtrs[++i])
	{
		if ((j = isitvar(prmtrs[i], env)) > 0)
		{
			if (!(print_str = var_arg(env[j])))
			{
				ft_printf("\n");
				return ;
			}
		}
		else
			print_str = ft_strdup(prmtrs[i]);
		if (prmtrs[i + 1] == NULL && fl_n == 0)
			ft_printf("%s\n", print_str);
		else if (prmtrs[i + 1] == NULL && fl_n == 1)
			ft_printf("%s", print_str);
		else
			ft_printf("%s ", print_str);
		free(print_str);
	}
}

void	ft_echo(char **prmtrs, char **env)
{
	int		flag_n;

	if (size_dac(prmtrs) < 2)
	{
		ft_printf("мало аргументов\n");
		return ;
	}
	if (ft_strcmp(prmtrs[1], "-n") == 0)
		flag_n = 1;
	else
		flag_n = 0;
	echo_print(prmtrs, env, flag_n);
}
