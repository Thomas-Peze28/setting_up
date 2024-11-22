/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **mem = malloc(nb_rows * sizeof(char *));

    for (int i = 0; i < nb_rows; i++) {
        mem[i] = malloc(nb_cols * sizeof(char));
    }
    return mem;
}
