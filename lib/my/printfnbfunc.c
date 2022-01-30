/*
** EPITECH PROJECT, 2019
** nbfunc
** File description:
** for printf
*/

#include "../include/printf.h"

char *test_int(char *str, int i, int nb)
{
    int aff = 0;
    int n = 1000000000;
    int re = 0;

    while (n != 0) {
        re = nb / n;
        if (re != 0 || aff != 0) {
            str[i] = (re + 48);
            nb = nb - n * re;
            aff = 1;
            i++;
        }
        n = n / 10;
    }
    str[i] = 0;
    return (str);
}

char *my_put_nbr2(va_list ap, struct input_flags flags)
{
    int count = 0;
    int nb = va_arg(ap, int);
    int i = 0;
    char *str = malloc(sizeof(char) * 12);

    if (nb == -2147483648) {
        str[0] = '-';
        str[1] = '2';
        i = 2;
        nb = 147483648;
    }
    if (nb < 0) {
        str[0] = '-';
        i++;
        nb = -1 * nb;
    }
    if (nb == 0) {
        free(str);
        return (my_strdup("0\0"));
    }
    return (test_int(str, i, nb));
}

char *my_put_unsigned(va_list ap, struct input_flags flags)
{
    unsigned int re = 0;
    unsigned int nb = va_arg(ap, unsigned int);
    unsigned int n = 1000000000;
    int aff = 0;
    char *str = malloc(sizeof(char) * 11);
    int i = 0;

    while (n != 0) {
        re = nb / n;
        if (re != 0 || aff != 0) {
            str[i] = (re + 48);
            nb = nb - n * re;
            aff = 1;
            i++;
        }
        n = n / 10;
    }
    str[i] = 0;
    return (str);
}

char *my_put_point(va_list ap, struct input_flags flags)
{
    long nb = va_arg(ap, long);
    char *base = "0123456789abcdef";
    char *res;
    int j = 0;
    char *str = malloc(sizeof(char) * 13);
    char *sto;

    res[0] = '0';
    res[1] = 'x';
    while (nb >= 16) {
        str[j] = base[nb % 16];
        nb = nb / 16;
        j++;
    }
    str[j] = base[nb];
    str[j + 1] = 0;
    sto = my_revstr(str);
    res = my_strcat(res, sto);
    free(str);
    free(sto);
    return (res);
}

char *my_oct(char c, char *res, int i)
{
    int nb = c;
    int j = 0;
    int m = my_strlen(res);
    char *sto = malloc(sizeof(char) * 4);
    char *rev;
    char *str = malloc(sizeof(char) * 4 + my_strlen(res));

    while (nb >= 8 || j <= 2) {
        sto[j] = (nb % 8) + 48;
        nb = nb / 8;
        j++;
    }
    sto[3] = '\\';
    rev = my_revstr(sto);
    free(sto);
    for (int k = 0; k < 4; k++) {
        str[m] = rev[k];
        m++;
    }
    free(rev);
    return (str);
}