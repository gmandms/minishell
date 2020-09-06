#ifndef MINISHELL_MINISHELL_H
# define MINISHELL_MINISHELL_H
# include "FT_PRINTF/ft_printf.h"
# include <sys/wait.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <dirent.h>
# include <limits.h>
# include <signal.h>

void	read_cmdline(char **cmd_line);
int 	run_cmd(char *cmd_line, char ***envp);
void	cr_env(char ***envcp, char **envp, char **argv);
int		size_dac(char **arr);
void	ch_enveq(char **arr, int i, char *varargs, char *varname);
void	ch_env(char **arr, char *varargs, char *varname);
char	*cr_pwd(char *path);
void	ch_envlvl(char **arr, int i, char *varname);
int 	impl_cmd(char *cmd_name);
void	env(char **envp);
void	cd(char **prmtrs, char **env);
void	choice(char *cmd, char **prmtrs, char ***envp);
char	**rec_env_paths(char **env);
char	*path_cmd(char *cmd, char *path);
void	my_exe(char *cmd, char **prmtrs, char **env);
void	ft_setenv(char ***env, char **prmtrs);
void	ft_unsetenv(char ***env, char **prmtrs);

#endif //MINISHELL_MINISHELL_H
