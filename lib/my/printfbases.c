/*
** EPITECH PROJECT, 2019
** bases
** File description:
** for printf
*/

#include "../include/printf.h"

char *my_put_base(va_list ap, struct input_flags flags)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *base = "0123456789abcdef";
    char *res = malloc(sizeof(char) * 9);
    int i = 0;
    char *str;

    while (nb >= 16) {
        res[i] = base[nb % 16];
        nb = nb / 16;
        i++;
    }
    res[i] = base[nb];
    res[i + 1] = 0;
    str = my_revstr(res);
    free(res);
    return (str);
}

char *my_put_basem(va_list ap, struct input_flags flags)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *base = "0123456789ABCDEF";
    char *res = malloc(sizeof(char) * 9);
    int i = 0;
    char *str;

    while (nb >= 16) {
        res[i] = base[nb % 16];
        nb = nb / 16;
        i++;
    }
    res[i] = base[nb];
    res[i + 1] = 0;
    str = my_revstr(res);
    free(res);
    return (str);
}

char *my_print_oct(va_list ap, struct input_flags flags)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int i = 0;
    char *res = malloc(sizeof(char) * 12);
    char *sto;

    while (nb >= 8) {
        res[i] = nb % 8 + 48;
        nb = nb / 8;
        i++;
    }
    res[i] = nb + 48;
    res[i + 1] = 0;
    sto = my_revstr(res);
    free(res);
    return (sto);
}

char *my_put_bin(va_list ap, struct input_flags flags)
{
    int nb = va_arg(ap, int);
    char *res = malloc(sizeof(char) * 33);
    int i = 0;
    char *str;

    while (nb >= 2) {
        res[i] = (nb % 2) + 48;
        nb = nb / 2;
        i++;
    }
    res[i] = nb + 48;
    res[i + 1] = 0;
    str = my_revstr(res);
    free(res);
    return (str);
}

char *my_print_nonp(va_list ap, struct input_flags flags)
{
    char *str = va_arg(ap, char *);
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[j]) {
        if (str[j] < 32 || str[j] == 127) {
            res = my_oct(str[i], res, i);
            i = i + 3;
        }
        else {
            res[i] = str[j];
        }
        i++;
        j++;
    }
    res[i] = 0;
    return (res);
}