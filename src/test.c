# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

int	main(void)
{
	int			fd;
	char 		*binaryPath = "/bin/wc";
  	char 		*args[] = {binaryPath, "-l", "-w", "-m", "infile.txt", NULL};
	 char *const env[] = {NULL};
	 pid_t	p;

	fd = open("./tmp", O_WRONLY | O_CREAT);
	dup2(fd, STDOUT_FILENO);
	printf("test test");
	p = fork() ;
	if (p < 0)
	{
		fprintf(stderr, "fork Failed");
        return 1;
	}
	if (p == 0)
	{

		execve(binaryPath, args, env);

	}
	else
	{
		wait(NULL);
		close(fd);
		close(STDOUT_FILENO);
	}
	
	/*binaryPath = "/bin/ls";
	args[1] = "-l";
	args[2] = "./";*/

  return 0;
}