#include "main.h"

/**
 * name_prg - print name of prg
 * @argc: num of args
 * @argv: args vector
 * Return: char pointer
*/
char *name_prg(int argc, char *argv[])
{
	char *name = NULL;

	name = argv[argc - 1];
	name++;
	name++;
	return (name);
}
