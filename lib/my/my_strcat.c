/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenates 2 strings
*/

#include "../include/my.h"

char *my_strcat(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2) + 1);
    int i = 0;
    int j = 0;

    while (str1[i]) {
        res[i] = str1[i];
        i++;
    }
    while (str2[j]) {
        res[i] = str2[j];
        i++;
        j++;
    }
    res[i] = 0;
    return (res);
}

char *my_strcatf(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2) + 1);
    int i = 0;
    int j = 0;

    while (str1[i]) {
        res[i] = str1[i];
        i++;
    }
    while (str2[j]) {
        res[i] = str2[j];
        i++;
        j++;
    }
    res[i] = 0;
    if (my_strlen(str1) > 0)
        free(str1);
    return (res);
}

char *my_strcatff(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2) + 1);
    int i = 0;
    int j = 0;

    while (str1[i]) {
        res[i] = str1[i];
        i++;
    }
    while (str2[j]) {
        res[i] = str2[j];
        i++;
        j++;
    }
    res[i] = 0;
    if (my_strlen(str1) > 0)
        free(str1);
    if (my_strlen(str2) > 0)
        free(str2);
    return (res);
}

char *my_strcat_f(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2) + 1);
    int i = 0;
    int j = 0;

    while (str1[i]) {
        res[i] = str1[i];
        i++;
    }
    while (str2[j]) {
        res[i] = str2[j];
        i++;
        j++;
    }
    res[i] = 0;
    if (my_strlen(str2) > 0)
        free(str2);
    return (res);
}