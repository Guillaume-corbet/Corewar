/*
** EPITECH PROJECT, 2019
** get word
** File description:
** lib
*/

#include "../include/my.h"

char *get_word(char *str, char c)
{
    int i = 0;
    char *sto = malloc(sizeof(char) * my_strlen(str) + 1);

    if (sto == NULL)
        return (NULL);
    while (str[i] && str[i] != c) {
        sto[i] = str[i];
        i++;
    }
    sto[i] = 0;
    return (sto);
}