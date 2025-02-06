/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "my.h"
#include "setting_up.h"

int is_square_of_size(map_info_t map_info, int row, int col, int square_size)
{
    int x = 0;
    int y = 0;

    if (row + square_size > map_info.nb_rows ||
        col + square_size > map_info.nb_cols) {
        return 1;
    }
    for (int i = 0; i < square_size * square_size - 1; i++) {
        x = row + (i / square_size);
        y = col + (i % square_size);
        if (map_info.map[x][y] == 'o') {
            return 1;
        }
    }
    return 0;
}

int find_biggest_square(map_info_t map_info, int row, int col)
{
    int square_size = 0;

    if (row >= map_info.nb_rows || col >= map_info.nb_cols
        || map_info.map[row][col] == 'o') {
        return 0;
    }
    while (is_square_of_size(map_info, row, col, square_size) == 0) {
        square_size++;
    }
    return square_size - 1;
}

int find_biggest_square_of_map(map_info_t *map_info, int row, int col)
{
    int size = 0;
    int biggest = 0;
    int x;
    int y;

    for (int i = 0; i < map_info->nb_rows * map_info->nb_cols; i++) {
        x = i / map_info->nb_cols;
        y = i % map_info->nb_cols;
        size = find_biggest_square(*map_info, x, y);
        if (size > biggest) {
            biggest = size;
            row = x;
            col = y;
        }
    }
    map_info->square_size = biggest;
    map_info->square_pos_x = row;
    map_info->square_pos_y = col;
    return 0;
}

char **replace_square(map_info_t map_info)
{
    char **replace_map = mem_dup_2d_array(map_info.map, map_info.nb_rows,
        map_info.nb_cols);
    int max_square_size = map_info.square_size;
    int pos_x = map_info.square_pos_x;
    int pos_y = map_info.square_pos_y;

    if (!replace_map) {
        return NULL;
    }
    for (int x = pos_x; x < pos_x + max_square_size
        && x < map_info.nb_rows; x++) {
        for (int y = pos_y; y < pos_y + max_square_size
            && y < map_info.nb_cols; y++) {
            replace_map[x][y] = 'x';
        }
    }
    return replace_map;
}
