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

void	cr_env(char ***envcp, char **envp, char **argv)
{
	int		size;
	char	*pwd;
	char	*shellarg;
	char	*shellname;

	size = size_dac(envp);
	envcp[0] = malloc(sizeof(char*) * (size + 1));
	envcp[0][size] = NULL;
	size = 0;
	pwd = cr_pwd(NULL);
	shellname = ft_strjoin("/", argv[0]);
	shellarg = ft_strjoin(pwd, shellname);
	while (envp[size])
	{
		envcp[0][size] = ft_strdup(envp[size]);
		if (ft_strncmp(envcp[0][size], "SHELL", 5) == 0)
			ch_enveq(envcp[0], size, shellarg, "SHELL");
		else if (ft_strncmp(envcp[0][size], "SHLVL", 5) == 0)
			ch_envlvl(envcp[0], size, "SHLVL=");
		size++;
	}
	free(shellarg);
	free(shellname);
	free(pwd);
}
