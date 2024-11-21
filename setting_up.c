/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** bootstrap setting_up
*/
#include "../include/my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **mem = malloc(nb_rows * sizeof(char *));

    for (int i = 0; i < nb_rows; i++) {
        mem[i] = malloc(nb_cols * sizeof(char));
    }
    return mem;
}

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

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int fd = open(filepath, O_RDONLY);
    char **dest = mem_alloc_2d_array(nb_rows, nb_cols);
    char buffer[1];
    int x = 0;
    int y = 0;

    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] == '\n') {
            x++;
            y = 0;
        } else if (x < nb_rows && y < nb_cols) {
            dest[x][y] = buffer[0];
            y++;
        }
    }
    close(fd);
    return dest;
}

int return_file_lenght(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int count = 0;

    while(read(fd, buffer, 1) > 0) {
        count++;
    }
    close(fd);
    return count;
}

int is_square_of_size(char **map, int row, int col, int square_size, int nb_rows, int nb_cols)
{
    if (row + square_size > nb_rows || col + square_size > nb_cols) {
        return 1;
    }
    for(int x = row; x < row + square_size; x++) {
        for (int y = col; y < col + square_size; y++) {
            if (map[x][y] == 'o') {
                return 1;
            }
        }
    }
    return 0;
}

int find_biggest_square(char **map, int row, int col, int nb_rows, int nb_cols)
{   
    int square_size = 1;

    if (map[row][col] == 'o') {
        return 0;
    }
    while (is_square_of_size(map, row, col, square_size, nb_rows, nb_cols) == 0) {
        square_size++;
    }
    return square_size - 1;
}

int *find_biggest_square_of_map(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int size = 0;
    int biggest = 0;
    int *result = malloc(3);

    for (int x = 0; x < nb_rows; x++) {
        for (int y = 0; y < nb_cols; y++){
            size = find_biggest_square(map, x, y, nb_rows, nb_cols);
            if (size > biggest) {
                biggest = size;
                row = x;
                col = y;
            }
        }
    }
    result[0] += biggest;
    result[1] += row;
    result[2] += col;
    return result;
}

char **replace_square(char **map, int *info_map, int *map_size)
{
    char **replace_map = mem_dup_2d_array(map, map_size[0], map_size[1]);
    int max_square_size = info_map[0];
    int pos_x = info_map[1];
    int pos_y = info_map[2];

    for (int x = pos_x; x < pos_x + max_square_size; x++) {
        for (int y = pos_y; y < pos_y + max_square_size; y++) {
            replace_map[x][y] = 'x';
        }
    }
    return replace_map;
}

int *return_raws_cols(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int raws = 1;
    int cols = 0;
    int current_cols = 0;
    int *info_file = malloc(2 * sizeof(int));

    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] == '\n') {
            raws++;
            if (raws == 3) {
                cols = current_cols;
            }
            current_cols = 0;
        } else {
            current_cols++;
        }
    }
    close(fd);
    info_file[0] = raws - 1;
    info_file[1] = cols;
    return info_file;
}
