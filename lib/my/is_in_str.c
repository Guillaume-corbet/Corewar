/*
** EPITECH PROJECT, 2019
** in in str
** File description:
** lib
*/

#include "../include/my.h"

int is_in_str(char *str, char c)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}