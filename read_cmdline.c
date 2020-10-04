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

void	rec_cmdline(char **cmd_line, int size, char c)
{
	char	*tmp;

	if (size > 1)
	{
		tmp = ft_strdup(cmd_line[0]);
		free(cmd_line[0]);
		cmd_line[0] = ft_strnew(size);
		ft_strncpy(cmd_line[0], tmp, size - 1);
		cmd_line[0][size - 1] = c;
		free(tmp);
	}
	else
	{
		cmd_line[0] = ft_strnew(size);
		cmd_line[0][size - 1] = c;
	}
}

void	read_cmdline(char **cmd_line)
{
	int		size;
	char	c;

	size = 1;
	while (1)
	{
		if (read(0, &c, 1) == -1)
			break ;
		if (c == '\n' && size > 1)
			break ;
		else if (c == '\n' && size == 1)
		{
			cmd_line[0] = NULL;
			break ;
		}
		rec_cmdline(cmd_line, size, c);
		size++;
	}
}
