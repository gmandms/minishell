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

int		whatisit(char *name)
{
	struct stat	wit;

	if (lstat(name, &wit) == -1)
		return (-1);
	if (S_IFDIR == (wit.st_mode & S_IFMT))
		return (1);
	if (S_IFREG == (wit.st_mode & S_IFMT))
		return (2);
	if (S_IFSOCK == (wit.st_mode & S_IFMT))
		return (3);
	if (S_IFLNK == (wit.st_mode & S_IFMT))
		return (4);
	if (S_IFBLK == (wit.st_mode & S_IFMT))
		return (5);
	if (S_IFCHR == (wit.st_mode & S_IFMT))
		return (6);
	if (S_IFCHR == (wit.st_mode & S_IFMT))
		return (7);
	return (0);
}

char	**cr_prmtrs(char **tmp_line, int size)
{
	char	**prmtrs;
	int		i;

	i = -1;
	prmtrs = malloc(sizeof(char*) * (size + 1));
	prmtrs[size] = NULL;
	while (tmp_line[++i])
	{
		prmtrs[i] = ft_strdup(tmp_line[i]);
		free(tmp_line[i]);
	}
	free(tmp_line);
	return (prmtrs);
}

void	free_runcmd(char *cmd, char **prmtrs)
{
	int i;

	i = -1;
	while (prmtrs[++i])
		free(prmtrs[i]);
	free(prmtrs);
	free(cmd);
}

void	for_fttrim(char *c_l, int *i, int *size)
{
	if (is_space(c_l[*i]))
		*i = forspace(c_l, *i, size);
	else if (c_l[*i] == '"')
		*i = forquote(c_l, *i, size);
	else if (c_l[*i] == '\0')
		*size += 1;
}
