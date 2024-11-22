/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"

int return_raws(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int raws = 1;

    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] == '\n') {
            raws++;
        }
    }
    close(fd);
    return raws - 1;
}

int return_cols(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int cols = 0;
    int raw = 1;

    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] == '\n') {
            raw++;
        }
        if (raw == 2 && buffer[0] != '\n') {
            cols++;
        }
    }
    close(fd);
    return cols;
}
