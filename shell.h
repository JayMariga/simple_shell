#ifndef SHELL_H
#define SHELL_H

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
int __exit(char **str, list_t *env, int num, char **command);
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
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char **_str_tok(char *str, char *delm);
char *ignore_delm(char *str, char delm);
int t_size(char *str, char delm);
int t_strlen(char *str, int pos, char delm);
char *_which(char *str, list_t *env);
int c_t_size(char *str, char delm);
char **c_str_tok(char *str, char *delm);
int _env(char **str, list_t *env);
char *int_to_string(int number);
int numlen(int n);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
char *c_ignore(char *str);
char *_strdup(char *str);
int _cd(char **str, list_t *env, int num);
char *c_strcat(char *dest, char *src);
int c_setenv(list_t **env, char *name, char *dir);
void cd_only(list_t *env, char *current);
int cd_execute(list_t *env, char *current, char *dir, char *str, int num);
int _cd(char **str, list_t *env, int num);


#endif
