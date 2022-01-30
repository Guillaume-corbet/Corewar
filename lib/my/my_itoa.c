/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** lib
*/

#include "../include/my.h"

char *chartostr(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = 0;
    return (str);
}

char *test_integer(int n, int nb, char *str)
{
    int res = 0;
    int aff = 0;
    char c;

    while (n != 0) {
        res = nb / n;
        if (res != 0 || aff != 0) {
            c = res + 48;
            str = my_strcatff(str, chartostr(c));
            nb = nb - n * res;
            aff = 1;
        }
        n = n / 10;
    }
    return (str);
}

char *my_itoa(int nb)
{
    int n = 1000000000;
    char *str = malloc(sizeof(char) * 14);

    if (nb < 0) {
        str[0] = '-';
        str[1] = 0;
        nb = -1 * nb;
    }
    if (nb == 0)
        return (my_strdup("0\0"));
    str = test_integer(n, nb, str);
    return (str);
}