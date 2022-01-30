/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** turn into upcase letters a string
*/

#include "../include/my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 122 && str[i] >= 97)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
