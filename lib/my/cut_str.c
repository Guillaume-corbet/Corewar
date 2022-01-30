/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** str
*/

#include "../include/my.h"

int count_space(char *str, char c)
{
    int count = 1;
    int i = 0;

    if (my_strlen(str) == 0)
        return (1);
    while (str[i]) {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

char **cut_str(char *str, char c)
{
    int size = 0;
    char **res;
    int nb = 0;

    if ((res = malloc(sizeof(char *) * (count_space(str, c) + 1))) == NULL)
        return (NULL);
    while (str[size]) {
        while (str[size] != c && str[size])
            size++;
        if ((res[nb] = malloc(sizeof(char) * size + 1)) == NULL)
            return (NULL);
        for (int k = 0; k < size; k++)
            res[nb][k] = str[k];
        res[nb][size] = 0;
        while ((str[size] == c) && str[size])
            size++;
        str += size;
        size = 0;
        nb++;
    } res[nb] = NULL;
    return (res);
}