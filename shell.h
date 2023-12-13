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

/**
 * struct list - Linked list structure for env variables.
 * @var: Holds the env variable string.
 * @next: Should point to next node in linked list.
 */

typedef struct list
{
        char *var;
        struct list *next;

} list_t;


/* PROTOTYPES */
char *_strcpy(char *dest, char *src);
int main(int ac, char **av, char **env);
int _execve(char **s, list_t *env, int num);
void c_exit(char **str, list_t *env);
char *get_env(char *str, list_t *env);
char *c_strdup(char *str, int cs);
int _exit(char **str, list_t *env, int num, char **command);
int c_atoi(char *s);
int _unsetenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
int _setenv(list_t **env, char **str);
size_t get_line(char **str);
list_t *env_linked_list(char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void non_interactive(list_t *env);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
void not_found(char *str, int num, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
list_t *add_end_node(list_t **head, char *str);
int prompt(char **env);
void ctrl_c(int n);
int built_in(char **token, list_t *env, int num, char **command);
char *ignore_space(char *str);
void ctrl_D(int i, char *command, list_t *env);
int prompt(char **en);
char *_strcat(char *dest, char *src);



#endif
