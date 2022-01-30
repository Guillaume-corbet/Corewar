/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** displays 1 if the whole string is composed by lower case letters
*/

#include "../include/my.h"

int my_str_islower(char *str)
{
    int i = 0;
    int st = 1;

    while (str[i] != '\0') {
        if (str[i] < 97 || str[i] > 122)
            st = 0;
        i++;
    }
    return (st);
}
