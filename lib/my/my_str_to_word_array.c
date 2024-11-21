/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Split a string into words in array
*/

#include <stdlib.h>
#include "my.h"

int count_word(char const *str)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}

int is_alpha(char letter)
{
    if (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

char *get_word(char const *str, int *i)
{
    int start = *i;
    int length = 0;
    char *word = malloc(length + 1);

    while (is_alpha(str[*i])) {
        (*i)++;
        length++;
    }
    for (int j = 0; j < length; j++) {
        word[j] = str[start + j];
    }
    word[length] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str)
{
    int word_nbr = count_word(str);
    char **tab = malloc((word_nbr + 1) * sizeof(char *));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i])) {
            tab[j] = get_word(str, &i);
            j++;
        }
    }
    tab[j] = NULL;
    return tab;
}
