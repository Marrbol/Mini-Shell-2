/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** my_cd
*/

#include "mysh.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static char *my_get_env_line(char **env, char *line)
{
    char *ligne = NULL;

    for (size_t i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], line, my_strlen(line)))
            return my_strdup(env[i]);
    return ligne;
}

static size_t check_arguments(char **buffer, char **env, char **old_path)
{
    size_t size_buffer = 0;
    char *home = my_get_env_line(env, "HOME=");

    home += my_strlen("HOME=");
    for (; buffer[size_buffer]; size_buffer++);
    if (size_buffer == 1) {
        *(old_path) = getcwd(NULL, 0);
        chdir(home);
        return 1;
    }
    if (my_strcmp(buffer[1], "-") == 0) {
        chdir(*(old_path));
        return 1;
    }
    if (size_buffer > 2) {
        my_printf("cd: Too many arguments\n");
        return 1;
    }
    return 0;
}

static void check_directory(char **buffer, struct stat buf, char **old_path)
{
    *(old_path) = getcwd(NULL, 0);
    if (stat(buffer[1], &buf) == -1)
        my_printf("%s: No such file or directory.\n", buffer[1]);
    else if (chdir(buffer[1]) == -1)
        my_printf("%s: Not a directory.\n", buffer[1]);
}

size_t my_cd(char **env, char **buffer)
{
    struct stat buf;
    static char *old_path = NULL;

    if (check_arguments(buffer, env, &old_path) == 1)
        return 0;
    else
        check_directory(buffer, buf, &old_path);
    return 0;
}
