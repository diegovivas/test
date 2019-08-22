#include "head.h"

int main()
{
	/* Create Proccess*/
	pid_t pid;
	/* getline */
	int gl, i, j, m;
	char *buf = NULL;
	char *line_cmd;
	int size = 1024;
	size_t num_line = 1024;
	/* user */
	char* username = getenv("USER");
/*char curr_path[size];
  char *path = getcwd(curr_path,-1);
*/
	int a , b = 0;
	extern char **environ;
	char  *envp[1];
/* strtok */
	char *cmd;
	const char s[2] = " ";
	char *argv[size];
//char *arg_path[size];
	int status;
//char *args[] =/ {"/bin/ls", "-l",NULL};
	line_cmd = (char *) malloc(size * sizeof(char));
//execve(args[0],args, NULL);
	while (1)
	{
		if (pid == -1)
		{
			perror("Error:");
			exit(0);
		}
		printf("\33[1;31m%s@miniShell\33[0m:$ ", username);
		if ((gl = getline(&buf, &num_line, stdin) == EOF))
		{
			exit(2);
		}
		if(gl == -1)
		{
			perror("Error:");
			exit(3);
			}

		_strcpy(line_cmd, buf);
		cmd = strtok(line_cmd, s);
		b++;
		for(i = 0; cmd != NULL; i++)
		{
			argv[i] = cmd;
			cmd = strtok(NULL, s);
		} 

		if(comparar(argv[0]))
			exit(0);
		env(environ);
		pid = fork();
		if(pid == 0)
		{
                    
			search_env(environ, argv);

			a = execve(argv[0], argv, environ);
			if (a != 1)		
				printf("sh: %d: %s: not found\n", b, argv[0]);

			exit(0);

		}
		else
		{
			wait(&status);
			kill(pid, SIGKILL);
		}
	}
	free(line_cmd);
	return (0);
}

