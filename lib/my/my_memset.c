/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** lib
*/

#include "../include/my.h"

void my_memset(void *s, int c, size_t n)
{
    char *ptr = (char *)s;

    for (int i = 0; i < n; i++)
        ptr[i] = c;
}