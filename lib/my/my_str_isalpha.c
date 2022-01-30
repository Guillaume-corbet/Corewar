/*
** EPITECH PROJECT, 2018
** my_str_isaplha
** File description:
** return 1 if the whole string is composed by letters
*/

#include "../include/my.h"

int my_str_isalpha(char *str)
{
    int i = 0;
    int st = 1;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
        }
        else if (str[i] >= 65 && str[i] <= 90) {
        }
        else {
            st = 0;
        }
        i++;
    }
    return (st);
}
