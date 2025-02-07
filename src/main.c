/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "my.h"
#include "setting_up.h"

void print_map(char **map)
{
    int w = 0;

    while (map[w] != NULL) {
        my_printf("%s\n", map[w]);
        w++;
    }
}

char **create_map(int size, char *patern)
{
    char **map = mem_alloc_2d_array(size, size);
    int patern_len = my_strlen(patern);
    int word_index = 0;
    int x = 0;
    int y = 0;

    if (!map)
        return NULL;
    for (int i = 0; i < size * size; i++) {
        x = i / size;
        y = i % size;
        if (word_index < patern_len) {
            map[x][y] = patern[word_index];
        } else {
            word_index = 0;
            map[x][y] = patern[word_index];
        }
        word_index++;
    }
    return map;
}

int error_handling(int ac, char **av)
{
    if (ac == 3) {
        if (my_str_have_alpha(av[1]) == 0)
            return 84;
        if (my_strlen(av[2]) == 0)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    map_info_t map_info;

    if (ac == 1)
        return 84;
    if (error_handling(ac, av) == 84)
        return 84;
    if (ac == 2) {
        map_info.nb_rows = return_raws(av[1]);
        map_info.nb_cols = return_cols(av[1]);
        map_info.map = load_2d_arr_from_file(av[1], map_info);
    } else if (ac == 3) {
        map_info.nb_rows = my_atoi(av[1]);
        map_info.nb_cols = my_atoi(av[1]);
        map_info.map = create_map(my_atoi(av[1]), av[2]);
    }
    find_biggest_square_of_map(&map_info, 0, 0);
    map_info.map_replace = replace_square(map_info);
    print_map(map_info.map_replace);
    return 0;
}
