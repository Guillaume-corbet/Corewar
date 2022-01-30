/*
** EPITECH PROJECT, 2019
** read_fic
** File description:
** lib
*/

#include "../include/my.h"

char *read_fic(char *name)
{
    int fic = open(name, O_RDONLY);
    int len = 2;
    char *buff = malloc(sizeof(char) * len + 1);
    char *res = "";

    if (fic == -1)
        return (NULL);
    while ((len = read(fic, buff, 2)) > 0) {
        buff[len] = 0;
        res = my_strcatff(res, buff);
        buff = malloc(sizeof(char) * 3);
    }
    free(buff);
    close(fic);
    return (res);
}
