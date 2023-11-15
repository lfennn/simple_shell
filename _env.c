#include "main.h"

/**
 * _env - Print environment variables
 */
void _env(void)
{
	char **env_ptr = environ;

	while (*env_ptr)
	{
		_printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
