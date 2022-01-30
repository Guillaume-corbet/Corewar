/*
** EPITECH PROJECT, 2019
** destroy array
** File description:
** lib
*/

#include "../include/my.h"

void destroy_array(char **tab)
{
    int i = 0;

    while (tab[i]) {
        if (tab[i])
            free(tab[i]);
        i++;
    }
    if (tab)
        free(tab);
}