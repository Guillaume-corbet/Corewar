/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** src
*/

#include "../include/my.h"
#include "../include/get_next_line.h"
#include <fcntl.h>

char *line(char *str, int *i, int fd)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 1 - (*i));
    int j = 0;

    while (str[*i] && str[*i] != '\n') {
        res[j] = str[*i];
        (*i)++;
        j++;
    }
    (*i)++;
    res[j] = 0;
    return (res);
}

void reading(int fd, char **str)
{
    int test;
    char *buff = malloc(sizeof(char) * READ_SIZE + 1);

    if (buff == NULL)
        return;
    while ((test = read(fd, buff, READ_SIZE)) == READ_SIZE) {
        buff[READ_SIZE] = 0;
        *str = my_strcatff(*str, buff);
        buff = malloc(sizeof(char) * READ_SIZE + 1);
    }
    if (test <= 0) {
        free(buff);
        return;
    }
    buff[test] = 0;
    *str = my_strcatff(*str, buff);
}

char *get_next_line(int fd)
{
    static char *str = "";
    static int i = 0;

    if (fd == -1 || (my_strlen(str) != 0 && i >= my_strlen(str))) {
        free(str);
        return (NULL);
    }
    if (i == 0)
        reading(fd, &str);
    return (line(str, &i, fd));
}
