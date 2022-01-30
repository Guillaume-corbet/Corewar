/*
** EPITECH PROJECT, 2019
** inttochar
** File description:
** lib
*/

#include "../include/my.h"

char *inttochar(int nb)
{
    char *str;
    int divi = 1;
    int i = 2;

    if (nb == 0)
        return (my_strdup("0"));
    while (divi * 10 < nb) {
        divi *= 10;
        i++;
    }
    if ((str = malloc(sizeof(char) * i)) == NULL)
        return (NULL);
    i = 0;
    while (nb != 0) {
        str[i] = (nb - (nb % divi)) / divi + 48;
        nb -= (str[i] - 48) * divi;
        i++;
        divi /= 10;
    }
    str[i] = 0;
    return (str);
}