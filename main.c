/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "my.h"

int main(int ac, char **av)
{
    int w = 1;
    map_info_t map_info;

    map_info.nb_rows = return_raws(av[1]);
    map_info.nb_cols = return_cols(av[1]);
    if (ac == 1) {
        return 84;
    } else {
        map_info.map = load_2d_arr_from_file(av[1], map_info);
    }
    map_info.square_size = find_biggest_square_of_map(map_info, 0, 0)[0];
    map_info.square_pos_x = find_biggest_square_of_map(map_info, 0, 0)[1];
    map_info.square_pos_y = find_biggest_square_of_map(map_info, 0, 0)[2];
    map_info.map_replace = replace_square(map_info);
    while (map_info.map_replace[w] != NULL) {
        my_printf("%s\n", map_info.map_replace[w]);
        w++;
    }
    return 0;
}
