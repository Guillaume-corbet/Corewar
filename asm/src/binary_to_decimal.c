/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** binary_to_decimal
*/

#include "../include/corewar.h"

char *decimal_binary(int nb)
{
    char *str = malloc(sizeof(char) * 100);
    char *new;
    int i = 0;
    int tmp = 0;

    while (nb > 0) {
        tmp = nb % 2;
        nb = nb / 2;
        str[i] = tmp + 48;
        i = i + 1;
    }
    str[i] = '\0';
    new = my_revstr(str);
    free(str);
    return (new);
}

int binary(char *str)
{
    int decimal_val = 0;
    int base = 1;
    int rem = 0;
    long long num = my_getnbr_long(str);

    while (num > 0) {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10;
        base = base * 2;
    }
    return (decimal_val);
}