#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "FT_PRINTF/ft_printf.h"

//void	prompt(void)
//{
//	ft_printf("$> ");
//}

void	read_line(char *str)
{
	int i;
	int	a;
	char c;

	i = 0;
	while (1)
	{
		a = read(0, &c, 1);
		if (a == -1)
		{
			str[0] = 'e' ;
			return ;
		}
		if (c == '\n')
		{
			str[i] = '\0';
			break ;
		}
		str[i] = c;
		i++;
	}
}

//int main( int argc, char **argv, char **envp) {
//	char	str[100];
//	char	cmd[100];
////	char *newenviron[] = { NULL };
//
//	int a;
//
//	a = 0;
//	while (envp[a])
//	{
//		printf("%s\n", envp[a]);
//		a++;
//	}
//	while (1)
//	{
//		prompt();
//		read_line(str);
//		if (fork() != 0) {
//			wait(NULL);
//			printf("%d\n", getpid());
//		}
//		else {
//			printf("%d\n", getpid());
//			ft_strcpy(cmd, "/bin/");
//			ft_strcat(cmd, str);
//			if (ft_strcmp(str, "exit") == 0)
//				break ;
//			execve(cmd, argv, envp);
//			perror("execve");
////			printf("%d\n", getpid());
//		}
//		if (ft_strcmp(str, "exit") == 0)
//			break ;
////		printf("%s", str);
//	}
//}
