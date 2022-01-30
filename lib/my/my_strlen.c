/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** displays the lenght of its parameter
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int count = 0;

    if (str == NULL || str == "")
        return (0);
    while (str[count] != '\0')
        count++;
    return (count);
}
