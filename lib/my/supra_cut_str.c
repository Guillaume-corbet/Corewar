/*
** EPITECH PROJECT, 2019
** supra cut str
** File description:
** lib
*/

#include "../include/my.h"

int compare(char *str, char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strncmp(str, tab[i], my_strlen(tab[i])) == 0)
            return (0);
    }
    return (1);
}

int count_hidden_str(char *str, char **tab)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (compare(str + i, tab) == 0)
            count++;
        i++;
    }
    return (count);
}

int *search_all(char *str, char **tab, int sto)
{
    int *res = malloc(sizeof(int) * 2);

    for (int i = 0; tab[i]; i++) {
        if (my_strncmp(str, tab[i], my_strlen(tab[i])) == 0) {
            res[0] = sto;
            res[1] = my_strlen(tab[i]);
            return (res);
        }
    }
    free(res);
    return (NULL);
}

int *search_str(char *str, char **tab, int *size)
{
    int *res;

    while (str[size[0]]) {
        if ((res = search_all(str + size[0], tab, size[0])) != NULL) {
            free(size);
            return (res);
        }
        size[0]++;
    }
    res = malloc(sizeof(int) * 2);
    res[0] = size[0];
    res[1] = 0;
    free(size);
    return (res);
}

char **supra_cut_str(char *str, char **tab)
{
    char **res = malloc(sizeof(char *) * (count_hidden_str(str, tab) + 2));
    int i = 0;
    int *size = malloc(sizeof(int) * 2);
    size[0] = 0;
    size[1] = 0;
    if (res == NULL)
        return (NULL);
    while (str[size[0]]) {
        size = search_str(str, tab, size);
        res[i] = malloc(sizeof(char) * size[0] + 1);
        for (int k = 0; k < size[0]; k++)
            res[i][k] = str[k];
        res[i][size[0]] = 0;
        size[0] += size[1];
        str += size[0];
        size[0] = 0;
        i++;
    } res[i] = NULL;
    free(size);
    return (res);
}