/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** displays 1 if the whole string is composed bu upper case letters
*/

#include "../include/my.h"

int my_str_isupper(char *str)
{
    int i = 0;
    int st = 1;

    while (str[i] != '\0') {
        if (str[i] < 65 || str[i] > 90)
            st = 0;
        i++;
    }
    return (st);
}
