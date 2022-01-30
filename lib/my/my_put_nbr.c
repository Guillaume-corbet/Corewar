/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** displays all type of INT value given as parameter
*/

#include "../include/my.h"

void test_integ(int n, int res, int aff, int nb)
{
    while (n != 0) {
        res = nb / n;
        if (res != 0 || aff != 0) {
            my_putchar(res + 48);
            nb = nb - n * res;
            aff = 1;
        }
        n = n / 10;
    }
}

int my_put_nbr(int nb)
{
    int n = 1000000000;
    int res = 0;
    int aff = 0;

    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb == 0)
        my_putchar(48);
    test_integ(n, res, aff, nb);
    return (0);
}
