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

int		fr_dash(char **env)
{
	char	*old_dir;
	int		i;
	char	*pwd;

	i = 0;
	while (ft_strncmp(env[i], "OLDPWD=", 7) != 0)
		i++;
	if (env[i] == NULL)
		return (-1);
	pwd = cr_pwd(NULL);
	old_dir = var_arg(env[i]);
	if (chdir(old_dir) == -1)
	{
		free(old_dir);
		free(pwd);
		return (-1);
	}
	ft_printf("%s\n", old_dir);
	ch_env(env, old_dir, "PWD");
	free(old_dir);
	ch_env(env, pwd, "OLDPWD");
	free(pwd);
	return (1);
}

int		fr_else_fcd(char **prmtrs, char *us_dir, char **env)
{
	char	*pwd;
	int		r;

	if (prmtrs[1][0] == '~')
		pwd = conc_dir(prmtrs[1], us_dir);
	else
		pwd = ft_strdup(prmtrs[1]);
	r = home_dir(env, pwd, cr_pwd(NULL));
	free(pwd);
	return (r);
}
