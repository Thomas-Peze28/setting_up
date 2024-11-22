/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** return file lenght
*/
#include "my.h"

int return_file_lenght(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int count = 0;

    while (read(fd, buffer, 1) > 0) {
        count++;
    }
    close(fd);
    return count;
}
