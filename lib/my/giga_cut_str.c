/*
** EPITECH PROJECT, 2019
** giga cut str
** File description:
** lib
*/

#include "../include/my.h"

int count_str(char *line, char *find)
{
    int count = 0;
    int i = 0;

    while (line[i]) {
        if (my_strncmp(line + i, find, my_strlen(find)) == 0)
            count++;
        i++;
    }
    return (count);
}

char **giga_cut_str(char *line, char *cut)
{
    char **res = malloc(sizeof(char *) * (count_str(line, cut) + 1));
    int i = 0;
    int size = 0;

    if (res == NULL)
        return (NULL);
    while (line[size]) {
        while (my_strncmp(line + size, cut, my_strlen(cut)) != 0 && line[size])
            size++;
        if ((res[i] = malloc(sizeof(char) * size + 1)) == NULL)
            return (NULL);
        for (int k = 0; k < size; k++)
            res[i][k] = line[k];
        res[i][size] = 0;
        size += my_strlen(cut);
        line += size;
        size = 0;
        i++;
    }
    res[i] = NULL;
    return (res);
}