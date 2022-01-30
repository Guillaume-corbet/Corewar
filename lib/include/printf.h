/*
** EPITECH PROJECT, 2019
** complement
** File description:
** for printf
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MACRO_H_
#define MACRO_H_

#define IF_MINUS (type[*i] == '-') ? (flags.add = 1) : (*i = *i)
#define IF_PLUS (type[*i] == '+') ? (flags.sign = 1) : (*i = *i)

#endif /* MACRO_H_ */

#ifndef STRUCT
#define STRUCT

struct input_flags
{
    int add;
    int space;
    int nb1;
    int sign;
    int nb2;
};

struct def_arg
{
    char type;
    char *(*func)(va_list ap, struct input_flags flags);
};

#endif /* !STRUCT */

#ifndef INC
#define INC

/* lib */
char *my_itoa(int);
char *chartostr(char c);
void my_putchar(char);
int my_putstr(char *);
char *my_strcat(char *, char *);
char *my_strcatf(char *, char *);
char *my_strdup(char *);
int my_strlen(char *);

/* bases.c */
char *my_put_base(va_list ap, struct input_flags flags);
char *my_put_basem(va_list ap, struct input_flags flags);
char *my_print_oct(va_list ap, struct input_flags flags);
char *my_put_bin(va_list ap, struct input_flags flags);
char *my_print_nonp(va_list ap, struct input_flags flags);

/* nb_func.c */
char *test_int(char *str, int i, int nb);
char *my_put_nbr2(va_list ap, struct input_flags flags);
char *my_put_unsigned(va_list ap, struct input_flags flags);
char *my_put_point(va_list ap, struct input_flags flags);
char *my_oct(char c, char *res, int i);

/* printf.c */
char *my_put_float(va_list ap, struct input_flags flags);
char *print_arg(char arg, va_list ap, struct input_flags flags);
struct input_flags test_flag(char *type, struct input_flags flags, int *i);
char *check_type(char *type, int *i, va_list ap);
int my_printf(char *type, ...);

/* strfunc.c */
char *my_revstr(char *str);
char *my_putstr2(va_list ap, struct input_flags flags);
char *my_printper(va_list ap, struct input_flags flags);
char *my_putback(va_list ap, struct input_flags flags);
char *my_putchar2(va_list ap, struct input_flags flags);

#endif /* !INC */

#endif /* !PRINTF_H_ */