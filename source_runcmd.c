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

int		forj(char *c_l, int *i)
{
	int j;

	j = 0;
	if (!is_space(c_l[*i]) && c_l[*i] != '"')
	{
		while (!is_space(c_l[*i]) && c_l[*i] != '"' && c_l[*i] != '\0')
		{
			*i += 1;
			j++;
		}
	}
	return (j);
}

int		nforspace(char *c_l, int i)
{
	while (is_space(c_l[i]))
		i++;
	return (i);
}

int		forspace(char *c_l, int i, int *size)
{
	*size += 1;
	while (is_space(c_l[i]))
		i++;
	return (i);
}

int		forquote(char *c_l, int i, int *size)
{
	int	j;

	i++;
	j = 0;
	while (c_l[i] != '"' && c_l[i] != '\0')
	{
		i++;
		j++;
	}
	if (c_l[i] == '"')
	{
		if (j > 0)
			*size += 1;
		i += 1;
	}
	else
	{
		ft_printf("Unmatched '\"'.\n");
		return (-1);
	}
	return (i);
}

int		for_frtrim(int i, char ***tmp_line, char *c_l)
{
	if (i == -1)
	{
		ft_printf("error - for_trim\n");
		tmp_line[0][0] = NULL;
		return (ft_strlen(c_l));
	}
	return (i);
}
