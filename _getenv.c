#include "shell.h"
#include <stddeff.h>

/**
 * _getenv - Gets an environment variable
 * @name: The variable to be found in the system environment
 * Return: The content of the environment variable
 */

extern char **environ;

char *_getenv(char *name)
{
	size_t i = 0, k = 0;
	char *en_var;

	while (environ[i] != NULL)
	{
		en_var = environ[i];
		while (en_var[k] == name[k] && en_var[k] != '=' && en_var[k] && name[k])
		{
			k++;
		}
		if (name[k] == '\0')
		{
			return (en_var);
			i++;
		}
	}
	return (NULL);
}

