/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** load_file_in_a_2d_array
*/
#include "my.h"
#include "setting_up.h"

char **load_2d_arr_from_file(char const *filepath, map_info_t map_info)
{
    int fd = open(filepath, O_RDONLY);
    char **dest = mem_alloc_2d_array(map_info.nb_rows, map_info.nb_cols);
    char buffer = '\0';
    int x = 0;
    int y = 0;
    int is_first = 0;

    while (read(fd, &buffer, 1) > 0) {
        if (buffer == '\n' && is_first == 0) {
            is_first = 1;
            continue;
        }
        if (buffer == '\n' && is_first == 1) {
            x++;
            y = 0;
            continue;
        }
        if (x < map_info.nb_rows && y < map_info.nb_cols && is_first == 1) {
            dest[x][y] = buffer;
            y++;
        }
    }
    close(fd);
    return dest;
}
