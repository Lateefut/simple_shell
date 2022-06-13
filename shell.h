#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
char *_getenv(const char *name);
char *locate(const char *name);
char *join_paths(const char sep, const char *path1, const char *path2);
int file_exists(const char *filepath);
char *_strdup(const char *str);

#endif
