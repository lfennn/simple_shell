#include "main.h"

/**
 * take_only_cmd - Extract the first command from a string
 * @buffer: input string containing one or more commands
 * @no_exc: number of commands
 * @n_err: number of commands
 * @argc: num of args
 * @argv: vector agrs
 * Return: Pointer to the first command
 */
char *take_only_cmd(char **buffer, int *no_exc, int argc,
		char *argv[], int *n_err)
{
	int i = 0;
	char str_cmd[50], *cmd;

	if (_strlen(*buffer) >= 50)
	{
		perror("command to long\n");
		free(*buffer), exit(1);
	}
	while ((*buffer)[i])
	{
		if ((*buffer)[i] == ' ')
			break;
		str_cmd[i] = (*buffer)[i];
		i++;
	}
	str_cmd[i] = '\0';
	cmd = malloc(_strlen(str_cmd) + 1);
	if (!cmd)
	{
		perror("fail to allocate");
		exit(1);
	}
	strcpy(cmd, str_cmd);
	if (_strcmp(cmd, "cd") == 0)
	{
		*no_exc = 0;
		change_dir(*buffer, cmd, argc, argv, n_err);
	}
	return (cmd);
}

/**
 * ls_check - Check if the command is 'ls' and validate directories
 * @ave: array of command-line arguments
 * @buf: buffer for storing command-line input
 * @only: the name of the command
 */
void ls_check(char *ave[], char *buf, char *only)
{
	const char *dir_path = NULL;
	DIR *dir;
	int index = 1;

	if (_strcmp(only, "ls") == 0 || _strcmp(ave[0], "/usr/bin/ls") == 0 ||
		_strcmp(ave[0], "/bin/ls") == 0)
{
	while (ave[index])
	{
		if (ave[index][0] != '-')
		{
			dir_path = ave[index];
			dir = opendir(dir_path);
			if (!dir)
			{
				fprintf(stderr, "%s: cannot access '%s': No such file or directory\n",
				only, dir_path);
				if (ave[index + 1] == NULL)
					free(buf), free(only), exit(2);
			}
			if (dir)
				closedir(dir);
		}
		index++;
	}
}
}

/**
 * shell_exit - exit program
 *@status: status num to exit
*/

void shell_exit(int status)
{
	if (status == 512)
		exit(status / 256);
	exit(0);
}
