/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** displays a number sent to the function in a string
*/

#include "../include/my.h"

int my_getnbr(char *str)
{
    int i = 0;
    long res = 0;
    int warning = 0;
    int neg = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            neg = (-1) * neg;
        i++;
    }
    while (str[i] != '\0' && warning == 0) {
        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + (str[i] - 48);
        if (str[i + 1] < 48 || str[i + 1] > 57)
            warning = 1;
        i++;
        if (res > 2147483647 || res < -2147483648)
            return (0);
    }
    return (neg * res);
}

long long my_getnbr_long(char *str)
{
    int i = 0;
    long long res = 0;
    int warning = 0;
    int neg = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            neg = (-1) * neg;
        i++;
    }
    while (str[i] != '\0' && warning == 0) {
        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + (str[i] - 48);
        if (str[i + 1] < 48 || str[i + 1] > 57)
            warning = 1;
        i++;
    }
    return (neg * res);
}