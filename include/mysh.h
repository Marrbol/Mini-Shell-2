/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_
    #include <stdbool.h>
    #include <stdio.h>

typedef struct list_node_s {
    char *command;
    char **array;
    bool is_separator;
    struct list_node_s *next;
    struct list_node_s *prev;
} list_node_t;

typedef struct list_s {
    list_node_t *head;
} list_t;

size_t my_getline(char **buffer);
char **dup_env(char **env);
char *remove_line_break(char *str);
char *getline_and_parse(void);
char **parse_path(char **env);
char **cat_command(char *command, char **path);
int verif_access(char **path);
void exec(char **env, char **buffer);
list_t *list_create(void);
void node_fill(list_t *list);
int execute_line(char *buffer, char ***env);
size_t get_nb_command(char *buffer);
void select_option(char ***env, char **buffer);
size_t my_cd(char **env, char **buffer);
char *remove_all_spaces(char *buffer);
char *remove_all_spaces2(char *buffer);
void double_redirection(char *comand, char **env);
bool check_rederection(char *comand);
void redirection(char *comand, char **env, bool simple);
bool check_double_redirection(char *buffer);
int choose_redirection(char *buffer, char **env, int index_separator);
void print_env(char **env);
void red(char **env, char **buffer, int fd);
bool check_pipe(char *current_comand);
void parsing_pipe(char *current_command, char **env);
bool check_double_pipe(char *current_line);
char **my_setenv(char **old_env, char *name, char *content);
char **my_unsetenv(char **env, char *line);
#endif /* !MYSH_H_ */
