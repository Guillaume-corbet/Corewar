/*
** EPITECH PROJECT, 2019
** is letter
** File description:
** lib
*/

#include "../include/my.h"

int is_letter(char c)
{
    if (c <= 90 && c >= 65)
        return (0);
    if (c <= 122 && c >= 97)
        return (0);
    return (1);
}