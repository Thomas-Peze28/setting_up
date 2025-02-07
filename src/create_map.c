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
