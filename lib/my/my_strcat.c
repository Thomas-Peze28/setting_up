/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Return if string a string is printable
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int count;

    for (count = 0; src[count] != '\0'; count++) {
        dest[dest_len + count] = src[count];
    }
    dest[dest_len + count] = '\0';
    return dest;
}
