/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"
#include "setting_up.h"

int return_raws(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer = '\0';
    int raws = 0;

    while (read(fd, &buffer, 1) > 0) {
        if (buffer == '\n') {
            raws++;
        }
    }
    close(fd);
    return raws - 1;
}

int return_cols(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer = '\0';
    int cols = 0;
    int raw = 1;

    while (read(fd, &buffer, 1) > 0) {
        if (buffer == '\n') {
            raw++;
        }
        if (raw == 2 && buffer != '\n') {
            cols++;
        }
    }
    close(fd);
    return cols;
}
