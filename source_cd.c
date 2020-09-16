#include "minishell.h"

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
