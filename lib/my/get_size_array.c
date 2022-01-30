/*
** EPITECH PROJECT, 2019
** get_size_array
** File description:
** get_size_array
*/

#include "../include/my.h"

int get_size_array(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return (i);
}