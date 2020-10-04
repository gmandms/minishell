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

void	init_fortrim(char ***tmp, int *i, int *sz)
{
	tmp[0] = malloc(sizeof(char*) * (*sz + 1));
	tmp[0][*sz] = NULL;
	*i = 0;
	*sz = 0;
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r')
		return (1);
	else
		return (0);
}

int		frt_space(char *c_l, char ***tmp, int *j, int size)
{
	int	i;

	i = 0;
	tmp[0][*j] = ft_strnew(size);
	ft_strncpy(tmp[0][*j], c_l, size);
	*j += 1;
	while (c_l[i + size] == ' ')
		i++;
	return (i);
}

int		frt_quote2(char *c_l, char ***tmp, int *j)
{
	int	i;

	i = 0;
	while (c_l[i] != '"' && c_l[i] != '\0')
		i++;
	if (c_l[i] != '"')
		return (-1);
	tmp[0][*j] = ft_strnew(i);
	ft_strncpy(tmp[0][*j], c_l, i);
	*j += 1;
	return (i + 2);
}

int		frt_quote(char *c_l, char ***tmp, int *j, int sz)
{
	int	i;
	int	new_sz;

	i = 0;
	new_sz = 0;
	while (c_l[i] != '"' && c_l[i] != '\0')
	{
		i++;
		new_sz++;
	}
	if (new_sz == 0)
		return (-1);
	tmp[0][*j] = ft_strnew(sz + new_sz);
	ft_strncpy(tmp[0][*j], c_l - sz - 1, sz);
	ft_strncpy(tmp[0][*j] + sz, c_l, new_sz);
	*j += 1;
	return (i + 2);
}
