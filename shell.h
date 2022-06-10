#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/* MACROS TO BE USED */
#define BUFSIZE 1024
#define DELIM "\t\r\n\a"

/*STANDARD LIBRARIES*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <linux/limits.h>

/*STRING FUNCTIONS*/
char *_strok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/** MEMORY MANAGEMENT **/
void prompt(void);
void signal_to_handle(int sig);
char *_getline(void);

/** COMMAND PARSER AND EXTRACTOR **/

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
void _handle_exit(char **u_tokns, char *line);
int execBuiltInCommands(char **u_tokns, char *line);
void frees_get_env(char *env_path);
void frees_tokens(char **tokns);
void _print_env(void);

/** BUILT IN FUNCTIONS **/

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** ERROR HANDLES AND PRINTER **/

void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void perror(char **argv, int c, char **cmd);

/**
 * struct map - a struct that maps a command name to a function
 * @command_name: name of the command
 * @func: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;
#endif
