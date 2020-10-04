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

int		while_myexe(char *cmd, char **prmtrs, char **env, char **pths)
{
	char	*rlcmd;
	int		i;

	i = -1;
	if (cmd[0] == '/' || cmd[0] == '.')
		return (0);
	while (pths[++i])
	{
		rlcmd = path_cmd(cmd, pths[i]);
		if (whatisit(rlcmd) == 2)
		{
			if (access(rlcmd, 0) == 0)
			{
				if (access(rlcmd, 1) == 0)
				{
					execve(rlcmd, prmtrs, env);
					free(rlcmd);
					return (1);
				}
			}
		}
		free(rlcmd);
	}
	return (0);
}
