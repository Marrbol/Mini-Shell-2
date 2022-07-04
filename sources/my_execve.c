/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** my_execve
*/

#include "mysh.h"
#include "my.h"
#include <sys/wait.h>
#include <unistd.h>

static void fork_and_execve(char *path, char **buffer, char **env)
{
    __pid_t child;
    int cpid = 0;

    child = fork();
    if (child == 0) {
        cpid = getpid();
        execve(path, buffer, env);
    } else
        wait(&cpid);
}

void exec(char **env, char **buffer)
{
    char **path = parse_path(env);
    int tmp = 0;

    if (my_strncmp(buffer[0], "/bin/", 5))
        buffer[0] += 4;
    path = cat_command(buffer[0], path);
    tmp = verif_access(path);
    if (tmp != -1)
        fork_and_execve(path[tmp], buffer, env);
    else
        my_printf("%s: Command not found.\n", buffer[0]);
}
