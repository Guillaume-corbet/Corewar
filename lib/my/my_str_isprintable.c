/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** return 1 if the string contain only printables characters
*/

#include "../include/my.h"

int my_str_isprintable(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32)
            return (1);
        i++;
    }
    return (0);
}
