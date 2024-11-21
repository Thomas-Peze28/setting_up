/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "my.h"

int main(int ac, char **av)
{
    char **map;
    char **map_replace;
    int *map_size = return_raws_cols(av[1]);
    int *info_map;
    int w = 1;

    if (ac == 1) {
        return 84;
    } else {
        map = load_2d_arr_from_file(av[1], map_size[0], map_size[1]);
    }
    info_map = find_biggest_square_of_map(map, map_size[0], map_size[1], 0, 0);
    map_replace = replace_square(map, info_map, map_size);
    while (map_replace[w] != NULL) {
        my_printf("%s\n", map_replace[w]); 
        w++;
    }
    return 0;
}
