/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** my_pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wait.h>
#include "my.h"
#include "mysh.h"

static int execute_first_command(char **env, char **first_command, int fd[2])
{
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    close(fd[0]);
    char **path = parse_path(env);
    path = cat_command(first_command[0], path);
    int tmp = verif_access(path);
    if (tmp != -1)
        execve(path[tmp], first_command, env);
    else {
        my_printf("%s: Command not found.\n", first_command[0]);
        return -1;
    }
    return 0;
}

static int execute_second_command(char **env, char **second_command, int fd[2])
{
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    close(fd[0]);
    char **path = parse_path(env);
    path = cat_command(second_command[0], path);
    int tmp = verif_access(path);
    if (tmp != -1)
        execve(path[tmp], second_command, env);
    else
        my_printf("%s: Command not found.\n", second_command[0]);
    return 0;
}

static void close_pipe(int fd[2], int pid1, int pid2)
{
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

static void execute_pipe(char **env, char **first_command,
            char **second_command)
{
    int fd[2];
    int pid1 = 0;
    int pid2 = 0;

    if (pipe(fd) == -1)
        return;
    pid1 = fork();
    if (pid1 < 0)
        return;
    if (pid1 == 0)
        execute_first_command(env, first_command, fd);
    pid2 = fork();
    if (pid2 < 0)
        return;
    if (pid2 == 0)
        execute_second_command(env, second_command, fd);
    return close_pipe(fd, pid1, pid2);
}

void parsing_pipe(char *current_command, char **env)
{
    current_command = my_cleanstr(current_command);
    size_t index_pipe = my_index_of(current_command, '|');
    char *first_command = my_strcpy_m(current_command, index_pipe - 1);

    current_command += index_pipe + 1;
    my_cleanstr(first_command);
    current_command = my_cleanstr(current_command);
    execute_pipe(env, my_str_to_array(first_command, ' '),
                my_str_to_array(current_command, ' '));
}
