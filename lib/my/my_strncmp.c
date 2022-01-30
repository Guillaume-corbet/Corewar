/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare 2 strings
*/

#include "../include/my.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    int test = 0;
    int max = 0;

    if (my_strlen(s1) < my_strlen(s2))
        max = my_strlen(s1);
    else
        max = my_strlen(s2);
    while (i < n && i < max) {
        test = s1[i] - s2[i];
        if (test != 0)
            return (test);
        i++;
    }
    return (0);
}
