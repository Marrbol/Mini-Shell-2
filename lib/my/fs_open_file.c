/*
** EPITECH PROJECT, 2021
** bsbsq step 1
** File description:
** bootsrtap BSQ step 1 open a file
*/
#include <fcntl.h>
#include <unistd.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(1, "FAILURE\n", 9);
        return 84;
    }
    return fd;
}
