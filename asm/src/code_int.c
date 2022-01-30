/*
** EPITECH PROJECT, 2019
** code int
** File description:
** corewar
*/

#include "../include/corewar.h"

char *invert_all(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '1')
            str[i] = '0';
        else if (str[i] == '0')
            str[i] = '1';
        i = i + 1;
    }
    return (str);
}

char *add_one_binary(char *str)
{
    int i = my_strlen(str);

    while (i >= 0) {
        if (str[i] == '1')
            str[i] = '0';
        else if (str[i] == '0') {
            str[i] = '1';
            return (str);
        }
        i = i - 1;
    }
    return (str);
}

void set_nb_neg(int fd, int n, int size)
{
    char *str;

    str = decimal_binary(n);
    while (my_strlen(str) < (8 * size)) {
        str = my_strcat_f("0", str);
    }
    str = invert_all(str);
    str = add_one_binary(str);
    n = binary(str);
    free(str);
    set_nb_size(fd, n, size);
}

void set_nb(int fd, int n)
{
    unsigned char bytes[4];

    my_memset(&bytes, 0, 4);
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    write(fd, bytes, sizeof(bytes));
}

void set_nb_size(int fd, int n, int size)
{
    unsigned char bytes[size];
    int i = 0;

    my_memset(&bytes, 0, size);
    while (i < size - 1) {
        bytes[i] = (n >> (8 * (size - i - 1))) & 0xFF;
        i = i + 1;
    }
    bytes[i] = n & 0xFF;
    write(fd, bytes, sizeof(bytes));
}