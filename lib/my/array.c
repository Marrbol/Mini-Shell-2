/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** array
*/

#include <stdio.h>
#include <stdlib.h>

size_t array_size(char **array)
{
    size_t size = 1;

    for (;array[size] != NULL; size++);
    return size;
}

void free_array(char **array)
{
    for (size_t size;array[size] != NULL; size++)
        free(array[size]);
    free(array);
}
