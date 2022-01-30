/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** cpoy a string to another
*/

#include "../include/my.h"

char *my_strcpy(char *src)
{
    int a = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    if (dest == NULL)
        return (NULL);
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
