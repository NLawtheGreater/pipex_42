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

void	main_con(char **argv, char **args, int fd)
{
	char *env[1];
	pid_t	p;
	char	com[100];
	int			out;
	int			in;

	env[0] = 0;
	in = open(argv[1], O_RDONLY);
	if (in == -1)
	{
		ft_printf("Error: program error\n"); //check error display
		unlink("tmp");
		exit(1);
	}
	out = dup(STDOUT_FILENO);
	p = fork();
	if( p < 0)
	{
		unlink("tmp");
		ft_printf("Error: test\n"); //check error display
		exit(0);
	}
	else if (p == 0)
	{
		dup2(fd, STDOUT_FILENO);
		dup2(in, STDIN_FILENO);
		close(fd);
		close(in);
		if (execve(args[0], args, env) == -1) //execve error not working?
		{
			f_arg(args , fd);
			//ft_printf("Error: %s\n", strerror(errno)); //check error display
			ft_putstr_fd("Error: ", out);
			ft_putstr_fd(strerror(errno), out);
			ft_putstr_fd("\n", out);
			unlink("tmp");
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		//ft_printf("Error: test\n"); //check error display
		//if(access(argv[4], F_OK) == 0)
		//	unlink(argv[4]);
		fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC , 0777);
		if (fd == -1)
		{
			f_arg(args, fd);
			unlink("tmp");
			exit(1);
		}
		f_arg(args, fd);
		args = ft_split(argv[3], ' ');
		ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
		bin_p1(&args[0]);
		/*ft_printf("test0:%s\n", args[0]);
	ft_printf("test1:%s\n", args[1]);
	ft_printf("test2:%s\n", args[2]);*/
		if(access(args[0], R_OK) == -1 || access(argv[4], R_OK)  == -1)
		{
			f_arg(args, fd);
			if (access(argv[4], R_OK)  == -1)
				ft_printf("%s: %s\n", argv[4], strerror(errno));
			else
				ft_printf("%s: command not found\n", com);
			unlink("tmp");
			exit(0);
		}
		p = fork();
		if( p < 0)
		{
			f_arg(args, fd);
			unlink("tmp");
			ft_printf("Error: test\n"); //check error display
			exit(0);
		}
		else if (p == 0)
		{
			//ft_putstr_fd("test1\n", fd);
			/*ft_putstr_fd("test2", in);*/
			in = open("tmp", O_RDWR | O_CREAT, 0666);
			if (in == -1)
			{
				ft_printf("Error: program error\n"); //check error display
				unlink("tmp");
				exit(0);
			}
			dup2(fd, STDOUT_FILENO);
			dup2(in, STDIN_FILENO);
			close(fd);
			close(in);
			//ft_putstr_fd("test3\n", STDOUT_FILENO);
			/*ft_putstr_fd("test4", STDIN_FILENO);*/
			if (execve(args[0], args, env) == -1) //execve error not working?
			{
				f_arg(args, fd);
				unlink("tmp");
				//ft_printf("Error: %s\n", strerror(errno)); //check error display
				ft_putstr_fd("Error: ", out);
				ft_putstr_fd(strerror(errno), out);
				ft_putstr_fd("\n", out);
				exit(0);
			}
		}
		else
		{

			wait(NULL);
			close(fd);
			close(in);
			unlink("tmp");
			f_arg(args, fd);
		}
	}
}

int	main(int argc, char **argv)
{
	char **args;
	int			fd;
	char		com[100];

	if (argc != 5)
	{
		ft_printf("Error: incorrect number of arguments\n"); //check error display
		return (0);
	}
	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		ft_printf("Error: program error\n"); //check error display
		unlink("tmp");
		exit(0);
	}
	
	args = ft_split(argv[2], ' ');
	ft_strlcpy(com, args[0], ft_strlen(args[0]) + 1);
	bin_p1( &args[0]);
	
	/*ft_printf("test0:%s\n", args[0]);
	ft_printf("test1:%s\n", args[1]);
	ft_printf("test2:%s\n", args[2]);*/
	if(access(args[0], R_OK) == -1 || access(argv[1], R_OK)  == -1)
	{
		f_arg(args, fd);
		unlink("tmp");
		if (access(argv[1], R_OK)  == -1)
			ft_printf("%s: %s\n", argv[1], strerror(errno));
		else
			ft_printf("%s: command not found\n", com);

		return (0);
	}
	//ft_printf("Error: program error\n"); //check error display
	main_con(argv, args, fd);
	
	return (0);
}

void	f_arg(char **args, int fd)
{
	int	x;

	x = 0;
	fd = x + fd;
	while(args[x])
	{
		free(args[x]);
		x++;
	}
	free(args);
	args = 0;
}