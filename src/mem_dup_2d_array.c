/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"
#include "setting_up.h"

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **dest = mem_alloc_2d_array(nb_rows, nb_cols);

    if (!dest)
        return NULL;
    for (int x = 0; x < nb_rows; x++) {
        for (int y = 0; y < nb_cols; y++) {
            dest[x][y] = arr[x][y];
        }
        dest[x][nb_cols] = '\0';
    }
    return dest;
}
