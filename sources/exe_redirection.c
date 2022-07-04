/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** exe_redirection
*/

#include "my.h"
#include "mysh.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

static void fork_and_execve_red(char *path, char **buffer, char **env, int fd)
{
    __pid_t child;
    int cpid = 0;

    child = fork();
    if (child == 0) {
        dup2(fd, 1);
        cpid = getpid();
        execve(path, buffer, env);
    } else
        wait(&cpid);
}
// cat: /tmp/fic: input file is output file
void red(char **env, char **buffer, int fd)
{
    char **path = parse_path(env);
    int tmp = 0;

    path = cat_command(buffer[0], path);
    tmp = verif_access(path);
    if (tmp != -1)
        fork_and_execve_red(path[tmp], buffer, env, fd);
    else
        my_printf("%s: Command not found.\n", buffer[0]);
}

static void execute_redirection(char *filename, char **comand, char **env,
                                bool simple)
{
    if (comand[1])
        if (my_strcmp(comand[1], filename))
            my_printf("cat: /tmp/fic: input file is output file\n");
    if (simple) {
        int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        if (!fd)
            return;
        red(env, comand, fd);
        close(fd);
    } else {
        int fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
        if (!fd)
            return;
        red(env, comand, fd);
        close(fd);
    }
}

void redirection(char *comand, char **env, bool simple)
{
    comand = my_cleanstr(comand);
    size_t index_of_redirection = my_index_of(comand, '>');
    char *first_comand = my_strcpy_m(comand, index_of_redirection);
    comand += index_of_redirection + 1;
    if (!simple)
        comand += 1;
    comand = remove_all_spaces2(comand);
    execute_redirection(comand, my_str_to_array(first_comand, ' '),
                        env, simple);
}

bool check_rederection(char *comand)
{
    for (size_t i = 0; comand[i]; i++)
        if (comand[i] == '>')
            return true;
    return false;
}
