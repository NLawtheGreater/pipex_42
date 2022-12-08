#include "pipex_bonus.h"

int	count_words(const char *str, char c)
{
	int	count;
	int	trig;

	count = 0;
	trig = 0;
	while (*str)
	{
		if (*str != c && trig == 0)
		{
			trig = 1;
			count++;
		}
		else if (*str == c)
			trig = 0;
		str++;
	}
	return (count);
}

void	bin_p1(char **program)
{
	char	*bin;

	bin = "/bin/";
	/*if (*file_lo)
		free(file_lo);*/
	//*file_lo = ft_strdup(file);
	bin = ft_strjoin(bin, *program);
	free(*program);
	*program = bin;
}

int	main_con(char **argv, char **args, int *pipefd, int argc)
{
	char *env[1];
	pid_t	p;
	
	char	com[100];
	int			out;

	env[0] = 0;
	
	
	ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
	bin_p1(args);
	p = fork();
	if( p < 0)
	{
		unlink("tmp");
		ft_printf("Error: %s\n", strerror(errno)); //check error display
		exit(0);
	}
	else if (p == 0)
	{
		out = dup(STDOUT_FILENO);
		pipefd[90] = open(argv[1], O_RDONLY);
		if (pipefd[90] == -1)
		{
			ft_printf("%s: %s\n", argv[1], strerror(errno)); //check error display
		}
		/*if(access(args[0], R_OK) == -1 || access(argv[1], R_OK)  == -1)
		{
			if (access(argv[1], R_OK)  == -1)
				ft_printf("%s: %s\n", argv[1], strerror(errno));
			else
				ft_printf("%s: command not found\n", com);
		}*/
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(pipefd[90], STDIN_FILENO);
		//close(fd);
		close(pipefd[90]);
		pipefd[95] = 0;
		while(pipefd[95] < 2 * (argc - 4))
		{
			close(pipefd[pipefd[95]]);
			pipefd[95]++;
		}
		if (execve(args[0], args, env) == -1) //execve error not working?
		{
			f_arg(args);
			//ft_printf("Error: %s\n", strerror(errno)); //check error display
			ft_putstr_fd("Error: ", out);
			ft_putstr_fd(strerror(errno), out);
			ft_putstr_fd("\n", out);
			exit(errno);
		}
	}
	f_arg(args);
	return (p);
}


int	main_out(char **argv, char **args, int *pipefd, int argc)
{
	char *env[1];
	pid_t	p;
	
	char	com[100];
	int			out;

	env[0] = 0;
	
	if(access(argv[argc - 1], F_OK) == 0)
		unlink(argv[argc - 1]);
	args = ft_split(argv[argc - 2], ' ');
	ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
	bin_p1(args);
	/*if(access(args[0], R_OK) == -1 || access(argv[4], R_OK)  == -1)
	{
		if (access(argv[4], R_OK)  == -1)
		{
			ft_printf("%s: %s\n", argv[4], strerror(errno));
		}
		else
			ft_printf("%s: command not found\n", com);
	}*/
	/*in = open("tmp", O_RDWR | O_CREAT, 0666);
	if (in == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
	}*/
	p = fork();
	if( p < 0)
	{
		unlink("tmp");
		ft_printf("Error: %s\n", strerror(errno)); //check error display
		exit(0);
	}
	else if (p == 0)
	{
		pipefd[80] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC , 0777);
		if (pipefd[80] == -1)
		{
			ft_printf("%s: %s\n", argv[argc - 1], strerror(errno));
		}
		out = dup(STDOUT_FILENO);
		dup2(pipefd[80], STDOUT_FILENO);
		dup2(pipefd[(argc - 5) * 2], STDIN_FILENO);
		close(pipefd[80]);
		pipefd[95] = 0;
		while(pipefd[95] < 2 * (argc - 4))
		{
			close(pipefd[pipefd[95]]);
			pipefd[95]++;
		}
		//close(in);
		if (execve(args[0], args, env) == -1) //execve error not working?
		{
			f_arg(args);
			unlink("tmp");
			//ft_printf("Error: %s\n", strerror(errno)); //check error display
			ft_putstr_fd("Error: ", out);
			ft_putstr_fd(strerror(errno), out);
			ft_putstr_fd("\n", out);
			exit(errno);
		}
	}
	f_arg(args);
	return (p);
}

int	mid(int argc, char **argv, int pipefd[], int k)
{
	char	*env[1];
	int	p;
	char **args;
	char com[100];
	int	out;

	env[0] = 0;
	args = ft_split(argv[k + 2], ' ');
	ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
	bin_p1(args);
		//ft_printf("%s\n", args[0]);
		//ft_printf("%s\n", args[1]);
	p = fork();
	if( p < 0)
	{
		unlink("tmp");
		ft_printf("Error: %s\n", strerror(errno)); //check error display
		exit(0);
	}
	else if (p == 0)
	{
		out = dup(STDOUT_FILENO);
		dup2(pipefd[(k - 1) * 2], STDIN_FILENO);
		dup2(pipefd[k * 2 + 1], STDOUT_FILENO);
		k = 0;
		while(k < 2 * (argc - 4))
		{
			close(pipefd[k]);
			k++;
		}
		if (execve(args[0], args, env) == -1) //execve error not working?
		{
			f_arg(args);
			//ft_printf("Error: %s\n", strerror(errno)); //check error display
			ft_putstr_fd("Error: ", out);
			ft_putstr_fd(strerror(errno), out);
			ft_putstr_fd("\n", out);
			exit(errno);
		}
	}
	f_arg(args);
	return (p);
}

int	main(int argc, char **argv)
{
	char **args;
	int	pipefd[100];
	int	k;

	if (argc < 5)
	{
		ft_printf("Error: incorrect number of arguments\n"); //check error display
		return (127);
	}
	k = 0;
	while(k < (argc - 4))
	{
		pipe((pipefd + (k * 2)));
		k++;
	}
	args = ft_split(argv[2], ' ');
	pipefd[99] = main_con(argv, args, pipefd, argc);
	k = 1;
	while(k <= (argc - 5))
	{
		pipefd[99 - k] = mid(argc, argv, pipefd, k);
		k++;
	}
	pipefd[99 - k] = main_out(argv, args, pipefd, argc);
	pipefd[60] = 0;
	while(pipefd[60] < 2 * (argc - 4))
	{
			close(pipefd[pipefd[60]]);
			pipefd[60]++;
	}
	while (k >= 0)
	{
		waitpid(pipefd[99 - k], &k, 0);
		k--;
	}
	return (0);
}

void	f_arg(char **args)
{
	int	x;

	x = 0;
	while(args[x])
	{
		free(args[x]);
		x++;
	}
	free(args);
	args = 0;
}