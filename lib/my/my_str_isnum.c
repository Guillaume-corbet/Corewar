/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** displays 1 if the whole string is composed by digits
*/

#include "../include/my.h"

int my_str_isnum(char *str)
{
    int i = 0;
    int st = 0;

    while (str[i] != '\0') {
        if ((str[i] > 57 || str[i] < 48) && str[i] != '-')
            st = 1;
        i++;
    }
    return (st);
}
