/*
** EPITECH PROJECT, 2019
** puterror
** File description:
** write on 2
*/

#include "../include/my.h"

void my_puterror(char *str)
{
    int i = 0;

    while (str[i]) {
        write(2, &str[i], 1);
        i++;
    }
}