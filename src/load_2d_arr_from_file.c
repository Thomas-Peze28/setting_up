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
    char buf = '\0';
    int y = 0;
    int f = 0;

    for (int x = 0; read(fd, &buf, 1) > 0;) {
        if (buf == '\n' && f == 1) {
            x++;
            y = 0;
        }
        if (buf == '\n' && f == 0)
            f = 1;
        if (buf != '\n' && x < map_info.nb_rows && y < map_info.nb_cols && f) {
            dest[x][y] = buf;
            y++;
        }
    }
    close(fd);
    return dest;
}
