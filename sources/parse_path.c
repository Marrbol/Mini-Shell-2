/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** parse_path
*/

#include "my.h"
#include "mysh.h"

char **parse_path(char **env)
{
    char ** path_parse = NULL;
    int i = 0;
    for (;env[i] && !my_strncmp(env[i], "PATH=", 5); i++);
    path_parse = my_str_to_array(env[i], ':');
    return path_parse;
}
