#include "minishell.h"

int		while_myexe(char *cmd, char **prmtrs, char **env, char **pths)
{
	char	*rlcmd;
	int		i;

	i = -1;
	while (pths[++i])
	{
		rlcmd = path_cmd(cmd, pths[i]);
		if (access(rlcmd, 0) == 0)
		{
			if (access(rlcmd, 1) == 0)
			{
				execve(rlcmd, prmtrs, env);
				free(rlcmd);
				return (1);
			}
		}
		free(rlcmd);
	}
	return (0);
}
