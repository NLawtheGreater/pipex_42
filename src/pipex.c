#include "pipex.h"

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

void	main_con(char **argv, char **args, int in)
{
	char *env[1];
	pid_t	p1;
	pid_t	p2;
	int	pipefd[2];
	char	com[100];
	int			out;
	int			status;

	env[0] = 0;
	pipe(pipefd);
	
	out = dup(STDOUT_FILENO);
	p1 = fork();
	if( p1 < 0)
	{
		unlink("tmp");
		ft_printf("Error: %s\n", strerror(errno)); //check error display
		exit(0);
	}
	else if (p1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(in, STDIN_FILENO);
		//close(fd);
		close(in);
		close(pipefd[0]);
		close(pipefd[1]);
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
	p2 = fork();
	if( p2 < 0)
	{
		unlink("tmp");
		ft_printf("Error: %s\n", strerror(errno)); //check error display
		exit(0);
	}
	else if (p2 == 0)
	{
		close(in);
		if(access(argv[4], F_OK) == 0)
			unlink(argv[4]);
		in = open(argv[4], O_RDWR | O_CREAT | O_TRUNC , 0777);
		if (in == -1)
		{
			ft_printf("%s: %s\n", argv[4], strerror(errno));
		}
		f_arg(args);
		args = ft_split(argv[3], ' ');
		ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
		bin_p1(&args[0]);
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
		dup2(in, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(in);
		close(pipefd[0]);
		close(pipefd[1]);
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
		//wait(NULL);
		//ft_printf("Error: test\n"); //check error display
		
		
		//unlink("tmp");
		close(in);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(p1, &status, 0);
		waitpid(p2, &status, 0);
		f_arg(args);

}


int	main(int argc, char **argv)
{
	char **args;
	int			in;
	char		com[100];

	if (argc != 5)
	{
		ft_printf("Error: incorrect number of arguments\n"); //check error display
		return (127);
	}
	
	args = ft_split(argv[2], ' ');
	ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
	bin_p1( &args[0]);
	in = open(argv[1], O_RDONLY);
	if (in == -1)
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
	//ft_printf("Error: program error\n"); //check error display
	main_con(argv, args, in);
	
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