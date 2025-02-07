/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef SETTING_
    #define SETTING_

typedef struct map_info_s {
    int nb_rows;
    int nb_cols;
    char **map;
    char **map_replace;
    int square_size;
    int square_pos_x;
    int square_pos_y;
} map_info_t;

char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char const *filepath, map_info_t map_info);
int is_square_of_size(map_info_t map_info, int row, int col, int square_size);
int find_biggest_square(map_info_t map_info, int row, int col);
int find_biggest_square_of_map(map_info_t *map_info, int row, int col);
char **replace_square(map_info_t map_info);
int *return_raws_cols(char const *filepath);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
int return_raws(char const *filepath);
int return_cols(char const *filepath);
char **create_map(int size, char *patern);
void print_map(char **map);

#endif /* SETTING_ */
