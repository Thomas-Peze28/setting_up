/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **dest = mem_alloc_2d_array(nb_rows, nb_cols);

    for (int x = 0; x < nb_rows; x++) {
        for (int y = 0; y < nb_cols; y++) {
            dest[x][y] = arr[x][y];
        }
    }
    return dest;
}
