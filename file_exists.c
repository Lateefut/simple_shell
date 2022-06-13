#include "shell.h"
#include <sys/stat.h>

/**
 * file_exists - ...
 * @filepath: ...
 * Return: 0 if success
 */

int file_exists(const char *filepath)
{
	struct stat buffer;

	if (stat(filepath, &buffer) == 0)
		return (1);

	return (0);
}
