/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** getline_and_parse
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

// list_t *list_create(void)
// {
//     list_t *list = malloc(sizeof(list_t));

//     if (list == NULL)
//         return NULL;
//     list->head = NULL;
//     return list;
// }

// void list_add(list_t *list, char *data, bool is_separator)
// {
//     list_node_t *newnode = malloc(sizeof(list_node_t));
//     list_node_t *node = list->head;

//     newnode->command = my_strdup(data);
//     newnode->is_separator = is_separator;
//     if (!newnode->is_separator)
//         newnode->array = my_str_to_array(data, ' ');
//     newnode->next = NULL;
//     newnode->prev = NULL;
//     if (list->head == NULL) {
//         list->head = newnode;
//         return;
//     }
//     while (node->next != NULL)
//         node = node->next;
//     node->next = newnode;
//     newnode->prev = node;
// }

// void list_fill(list_t *list, char *command)
// {
//     size_t counter = 0;
//     char *current_command = malloc(sizeof(char) * (my_strlen(command)) + 2);
//     char *separator = malloc(sizeof(char) * 3);

//     for (size_t i = 0; command[i] != '\0'; i++) {
//         if (command[i] != ';' && command[i] != '|') {
//             current_command[counter] = command[i];
//             current_command[counter + 1] = '\0';
//             counter++;
//         } else {
//             separator[0] = command[i];
//             separator[1] = '\0';
//             my_pritf("current command 1 = %s\n", current_command);
//             list_add(list, current_command, false);
//             list_add(list, separator, true);
//             counter = 0;
//         }
//     }
// }

// size_t count_separator(char *buffer)
// {
//     size_t counter = 0;
//     for (size_t i = 0; buffer[i] != '\0'; i++) {
//         if (buffer[i] == '|' || buffer[i] == ';')
//             counter++;
//     }
//     my_pritf("counter separatoor = %ld\n", counter);
//     return counter;
// }

char *remove_all_spaces2(char *buffer)
{
    char *final_string = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    size_t counter = 0;

    for (size_t i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ' && buffer[i + 1] != ' ')
            i++;
        if (buffer[i] == ';' && buffer[i + 1] == ' ') {
            final_string[counter] = buffer[i];
            final_string[counter + 1] = '\0';
            i++;
        } else {
            final_string[counter] = buffer[i];
            final_string[counter + 1] = '\0';
        }
        counter++;
    }
    return final_string;
}

char *remove_all_spaces(char *buffer)
{
    char *final_string = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    size_t counter = 0;

    for (size_t i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ' && buffer[i + 1] == ';')
            i++;
        if (buffer[i] == ';' && buffer[i + 1] == ' ') {
            final_string[counter] = buffer[i];
            final_string[counter + 1] = '\0';
            i++;
        } else {
            final_string[counter] = buffer[i];
            final_string[counter + 1] = '\0';
        }
        counter++;
    }
    return final_string;
}

char *getline_and_parse(void)
{
    char *buffer = NULL;
    size_t len = 0;

    if ((len = my_getline(&buffer)) == 0)
        return NULL;
    buffer = remove_line_break(buffer);
    buffer = my_cleanstr(buffer);
    buffer = remove_all_spaces(buffer);
    return buffer;
}
