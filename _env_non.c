#include "main.h"

/**
 * _env_non - Print environment variables
 * @no_exc: num to handle continue to fork
 */
void _env_non(int *no_exc)
{
	char **env_ptr = environ;
	*no_exc = 0;
	while (*env_ptr)
	{
		_printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
