/*
** EPITECH PROJECT, 2019
** header
** File description:
** corewar
*/

#include "../include/corewar.h"

char *recover_name(char *name)
{
    int i = my_strlen(name) - 1;
    int sto;
    char *str;

    while (i > 0 && name[i] != '.')
        i--;
    sto = i;
    while (i > 0 && name[i] != '/')
        i--;
    if (i != 0)
        i++;
    str = my_strndup(name + i, sto - i);
    return (str);
}

int stock_prog_name(header_t *he, char **stock_all, char *line_name, int find)
{
    int i = my_strlen(line_name);
    int a = 0;
    int max = 0;
    
    while (stock_all[find][i] != '\0' && stock_all[find][i] != '"')
        i = i + 1;
    i = i + 1;
    max = my_strlen(stock_all[find]) - i - 1;
    if (max > PROG_NAME_LENGTH)
        return (84);
    while (stock_all[find][i + 1] != '\0') {
        he->prog_name[a] = stock_all[find][i];
        i = i + 1;
        a = a + 1;
    }
    he->prog_name[a] = '\0';
    return (0);
}

int stock_prog_com(header_t *he, char **stock_all, char *comment, int find)
{
    int i = my_strlen(comment);
    int a = 0;
    int max = 0;
    
    while (stock_all[find][i] != '\0' && stock_all[find][i] != '"')
        i = i + 1;
    i = i + 1;
    max = my_strlen(stock_all[find]) - i - 1;
    if (max > COMMENT_LENGTH) {
        return (84);
    }
    while (stock_all[find][i + 1] != '\0') {
        he->comment[a] = stock_all[find][i];
        i = i + 1;
        a = a + 1;
    }
    he->comment[a] = '\0';
    return (0);
}

int init_struct_header_sec(char **stock_all, int find, header_t *he, int found)
{
    if ((find != -84 && found != find -1) ||
    verif_all(stock_all, found) == 84)
        return (84);
    if (find != -84) {
        if (stock_prog_com(he, stock_all, COMMENT_CMD_STRING, find) == 84)
            return (84);
    } else
        he->comment[0] = '\0';
    he->prog_size = 0;
    he->magic = be32toh(COREWAR_EXEC_MAGIC);
    return (0);
}

header_t *init_struct_header(char **stock_all)
{
    header_t *he = malloc(sizeof(header_t) + (4 - sizeof(header_t) % 4));
    int find = 0;
    int found = 0;

    if (he == NULL)
        return (NULL);
    my_memset(he, 0, sizeof(*he) + (4 - sizeof(*he) % 4));
    he->prog_size = 0;
    found = find_prog_name(stock_all, NAME_CMD_STRING);
    if (found == -84)
        return (NULL);
    if (stock_prog_name(he, stock_all, NAME_CMD_STRING, find) == 84)
        return (NULL);
    find = find_prog_name(stock_all, COMMENT_CMD_STRING);
    if (init_struct_header_sec(stock_all, find, he, found) == 84)
        return (NULL);
    return (he);
}