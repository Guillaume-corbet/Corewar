/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** allocates memory and copy a string passed as parameter
*/

#include "../include/my.h"

char *my_strdup(char *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *res;

    if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (i < len) {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char *my_strndup(char *src, int nb)
{
    int len = my_strlen(src);
    int i = 0;
    char *res;

    if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (i < len && i < nb) {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char *my_strfdup(char *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *res;

    if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (i < len) {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    free(src);
    return (res);
}

char *my_strfndup(char *src, int nb)
{
    int len = my_strlen(src);
    int i = 0;
    char *res;

    if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (i < len && i < nb) {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    free(src);
    return (res);
}