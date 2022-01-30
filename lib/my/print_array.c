/*
** EPITECH PROJECT, 2019
** print_array
** File description:
** lib
*/

#include "../include/my.h"

void print_array(char **tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        write(1, "\n", 1);
        i++;
    }
}