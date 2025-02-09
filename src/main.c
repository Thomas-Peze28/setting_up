/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "my.h"
#include "setting_up.h"

int check_patern(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != 'o')
            return 84;
    }
    return 0;
}

int error_handling(int ac, char **av)
{
    if (ac == 1 || ac > 3)
        return 84;
    if (ac == 3) {
        if (my_str_have_alpha(av[1]) == 0)
            return 84;
        if (my_strlen(av[2]) == 0)
            return 84;
        if (check_patern(av[2]) == 84)
            return 84;
    }
    return 0;
}

int error_handling_map(int ac, char **av)
{
    if (ac == 2) {
        if (open(av[1], O_RDONLY) == -1)
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    map_info_t map_info;

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
    if (error_handling_map(ac, av) == 84)
        return 84;
    find_biggest_square_of_map(&map_info, 0, 0);
    map_info.map_replace = replace_square(map_info);
    print_map(map_info.map_replace);
    return 0;
}
