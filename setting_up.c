/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "../include/my.h"

int is_square_of_size(map_info_t map_info, int row, int col, int square_size)
{
    int x;
    int y;

    if (row + square_size > map_info.nb_rows ||
        col + square_size > map_info.nb_cols) {
        return 1;
    }
    for (int i = 0; i < square_size * square_size; i++) {
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

    if (map_info.map[row][col] == 'o') {
        return 0;
    }
    while (is_square_of_size(map_info, row, col, square_size) == 0) {
        square_size++;
    }
    return square_size - 1;
}

int *find_biggest_square_of_map(map_info_t map_info, int row, int col)
{
    int size = 0;
    int biggest = 0;
    int *result = malloc(3);
    int x;
    int y;

    for (int i = 0; i < map_info.nb_rows * map_info.nb_cols; i++) {
        x = i / map_info.nb_cols;
        y = i % map_info.nb_cols;
        size = find_biggest_square(map_info, x, y);
        if (size > biggest) {
            biggest = size;
            row = x;
            col = y;
        }
    }
    result[0] += biggest;
    result[1] += row;
    result[2] += col;
    return result;
}

char **replace_square(map_info_t map_info)
{
    char **replace_map = mem_dup_2d_array(map_info.map, map_info.nb_rows
        , map_info.nb_cols);
    int max_square_size = map_info.square_size;
    int pos_x = map_info.square_pos_x;
    int pos_y = map_info.square_pos_y;

    for (int x = pos_x; x < pos_x + max_square_size; x++) {
        for (int y = pos_y; y < pos_y + max_square_size; y++) {
            replace_map[x][y] = 'x';
        }
    }
    return replace_map;
}
