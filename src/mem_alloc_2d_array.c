/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"
#include "setting_up.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **mem = malloc((nb_rows + 1) * sizeof(char *));

    if (!mem)
        return NULL;
    for (int i = 0; i < nb_rows; i++) {
        mem[i] = malloc((nb_cols + 1) * sizeof(char));
        if (!mem[i])
            return NULL;
        mem[i][nb_cols] = '\0';
    }
    mem[nb_rows] = NULL;
    return mem;
}
