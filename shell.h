#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>



/* PROTOTYPES */
char *_strcpy(char *dest, char *src);
int main(int ac, char **av, char **env);
int _execve(char **s, list_t *env, int num);
void c_exit(char **str, list_t *env);
char *get_env(char *str, list_t *env);
char *c_strdup(char *str, int cs);
int __exit(char **str, list_t *env, int num, char **command);
int c_atoi(char *s);
int _unsetenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
int _setenv(list_t **env, char **str);





#endif
