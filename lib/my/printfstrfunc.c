/*
** EPITECH PROJECT, 2019
** strfunc
** File description:
** for printf
*/

#include "../include/printf.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char *res = malloc(sizeof(char) * j + 2);

    while (j >= 0) {
        res[i] = str[j];
        j--;
        i++;
    }
    res[i] = 0;
    return (res);
}

char *my_putstr2(va_list ap, struct input_flags flags)
{
    int i = 0;
    char *str = va_arg(ap, char *);

    return (my_strdup(str));
}

char *my_printper(va_list ap, struct input_flags flags)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = '%';
    str[1] = '\0';
    return (str);
}

char *my_putback(va_list ap, struct input_flags flags)
{
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    return (str);
}

char *my_putchar2(va_list ap, struct input_flags flags)
{
    char c = va_arg(ap, int);
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = '\0';
    return (str);
}