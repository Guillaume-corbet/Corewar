/*
** EPITECH PROJECT, 2019
** printf
** File description:
** newprintf
*/

#include "../include/printf.h"

struct def_arg arg_type[] =
{
    {'d', &my_put_nbr2},
    {'i', &my_put_nbr2},
    {'o', &my_print_oct},
    {'u', &my_put_unsigned},
    {'x', &my_put_base},
    {'f', &my_put_float},
    {'X', &my_put_basem},
    {'c', &my_putchar2},
    {'s', &my_putstr2},
    {'p', &my_put_point},
    {'S', &my_print_nonp},
    {'b', &my_put_bin},
    {'%', &my_printper},
    {'\0', &my_putback}
};

char *my_put_float(va_list ap, struct input_flags flags)
{
    double nb = va_arg(ap, double);
    int i = 0;
    char *str = NULL;

    if (nb < 0)
        str = "0\0";
    while (nb > 1) {
        nb *= 0.1;
        i++;
    } while (i > 0) {
        nb *= 10;
        str = my_strcatf(str, chartostr(nb + '0'));
        nb -= (int)nb;
        i--;
    } if (flags.nb2 != 0)
        str = my_strcatf(str, chartostr('.'));
    for (int j = 0; j < flags.nb2; j++) {
        nb *= 10;
        str = my_strcatf(str, chartostr(nb + '0'));
        nb -= (int)nb;
    } return (str);
}

char *print_arg(char arg, va_list ap, struct input_flags flags)
{
    int i = 0;
    char *str;

    while (arg_type[i].type != arg && i < 13)
        i++;
    if (i == 14) {
        str = malloc(sizeof(char) * 3);
        str[0] = '%';
        str[1] = arg;
        str[2] = 0;
    }
    else
        str = arg_type[i].func(ap, flags);
    return (str);
}

struct input_flags test_flag(char *type, struct input_flags flags, int *i)
{
    if (type[*i] == '.') {
        (*i)++;
        flags.nb2 = type[*i] - 48;
        (*i)++;
    } else
        flags.nb2 = 0;
    return (flags);
}

char *check_type(char *type, int *i, va_list ap)
{
    char arg;
    struct input_flags flags;
    char *str;

    (*i)++;
    flags = test_flag(type, flags, i);
    arg = type[*i];
    str = print_arg(arg, ap, flags);
    return (str);
}

int my_printf(char *type, ...)
{
    va_list ap;
    int i = 0;
    char *str;
    int count = 0;

    va_start(ap, type);
    while (type[i] != '\0') {
        if (type[i] == '%') {
            str = check_type(type, &i, ap);
            count = count + my_strlen(str);
            my_putstr(str);
            free(str);
        }
        else {
            my_putchar(type[i]);
            count++;
        }
        i++;
    }
    va_end(ap);
    return (count);
}