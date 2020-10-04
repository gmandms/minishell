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

#ifndef MINISHELL_MINISHELL_H
# define MINISHELL_MINISHELL_H

# include "FT_PRINTF/ft_printf.h"
# include <stdio.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <limits.h>
# include <sys/stat.h>

int		fr_dash(char **env);
int		whatisit(char *name);
void	ch_envlvl(char **arr, int i, char *varname);
void	ch_env(char **arr, char *varargs, char *varname);
void	read_cmdline(char **cmd_line);
int		run_cmd(char *cmd_line, char ***envp);
char	*path_cmd(char *cmd, char *path);
int		my_exe(char *cmd, char **prmtrs, char **env);
void	choice(char *cmd, char **prmtrs, char ***envp);
void	ft_echo(char **prmtrs, char **env);
void	cr_env(char ***envcp, char **envp, char **argv);
void	ch_enveq(char **arr, int i, char *varargs, char *varname);
char	*cr_pwd(char *path);
void	ft_setenv(char ***env, char **prmtrs);
int		size_dac(char **arr);
char	**rec_env_paths(char **env);
void	ft_unsetenv(char ***env, char **prmtrs);
int		impl_cmd(char *cmd_name);
void	cd(char **prmtrs, char **env);
char	*var_arg(char *env_var);
char	*find_pwd(char *us_name, char **env);
int		home_dir(char **env, char *path, char *old_pwd);
char	*conc_dir(char *path, char *us_dir);
int		fr_else_fcd(char **prmtrs, char *us_dir, char **env);
void	free_dac(char **arr);
int		forj(char *c_l, int *i);
int		forspace(char *c_l, int i, int *size);
int		forquote(char *c_l, int i, int *size);
int		nforspace(char *c_l, int i);
int		frt_space(char *c_l, char ***tmp, int *j, int size);
int		frt_quote(char *c_l, char ***tmp, int *j, int sz);
int		frt_quote2(char *c_l, char ***tmp, int *j);
int		is_space(char c);
int		while_myexe(char *cmd, char **prmtrs, char **env, char **pths);
void	init_fortrim(char ***tmp, int *i, int *sz);
int		for_frtrim(int i, char ***tmp_line, char *c_l);
void	for_fttrim(char *c_l, int *i, int *size);
void	free_runcmd(char *cmd, char **prmtrs);
char	**cr_prmtrs(char **tmp_line, int size);

#endif
