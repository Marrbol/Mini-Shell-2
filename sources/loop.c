/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "mysh.h"
#include <wait.h>

static size_t get_separator_index(char *buffer)
{
    for (size_t i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == ';')
            return i;
    return my_strlen(buffer) + 1;
}

static char *get_current_command(char *buffer)
{
    char *first_command = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    size_t counter_first_command = 0;

    for (size_t i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ';') {
            first_command[counter_first_command] = buffer[i];
            first_command[counter_first_command + 1] = '\0';
            counter_first_command++;
        } else
            return first_command;
    }
    return first_command;
}

size_t get_nb_command(char *buffer)
{
    size_t nb_command = 1;

    for (size_t i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '|' || buffer[i] == ';')
            nb_command++;
    return nb_command;
}

static int execute_other_line(char ***env, char *current_comand, int index_separator)
{
    if (current_comand)
        select_option(env, my_str_to_array(current_comand, ' '));
    return index_separator;
}

int execute_line(char *buffer, char ***env)
{
    int index_separator = get_separator_index(buffer);
    char *current_comand = get_current_command(buffer);
    if (my_strlen(current_comand) == 0)
        return index_separator;
    if (my_strcmp(current_comand, "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (check_double_pipe(current_comand))
        return index_separator;
    if (check_pipe(current_comand))
        parsing_pipe(current_comand, *(env));
    else if (check_rederection(current_comand))
        return choose_redirection(current_comand, *(env), index_separator);
    else
        return execute_other_line(env, current_comand, index_separator);
    return index_separator;
}
