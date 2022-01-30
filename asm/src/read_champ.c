/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** guillaume
*/

#include "../include/corewar.h"

char **stock_all_file(char *filepath)
{
    size_t bufs = 1000;
    char **tab = malloc(sizeof(char *) * bufs);
    char *str = malloc(sizeof(char) * bufs);
    FILE *fd = fopen(filepath, "r");
    int i = 0;

    if (str == NULL || tab == NULL || fd == NULL)
        return (NULL);
    while (getline(&str, &bufs, fd) != -1) {
        tab[i] = my_strdup(str);
        if (tab[i][my_strlen(tab[i]) - 1] == '\n')
            tab[i][my_strlen(tab[i]) - 1] = '\0';
        i = i + 1;
    }
    tab[i] = NULL;
    if (fclose(fd) != 0)
        return (NULL);
    free(str);
    return (tab);
}

void find_prog_name_sec(char *line_name, char **stock_all, int y, int *x)
{
    while (line_name[*x] != '\0') {
        if (line_name[*x] != stock_all[y][*x]) {
            (*x) = 0;
            break;
        }
        (*x) = (*x) + 1;
    }
}

int find_prog_name(char **stock_all, char *line_name)
{
    int x = 0;
    int y = 0;
    char *sto;

    if (stock_all == NULL)
        return (-84);
    while (stock_all[y] != NULL) {
        sto = my_strdup(stock_all[y]);
        free(stock_all[y]);
        stock_all[y] = remove_comment(sto);
        free(sto);
        find_prog_name_sec(line_name, stock_all, y, &x);
        if (x > 0)
            return (y);
        y = y + 1;
    }
    return (-84);
}

int is_direct_cmd(char *str)
{
    int i = 0;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i] == DIRECT_CHAR) {
        if (my_str_isnum(str + i + 1) == SUCCESS)
            return (SUCCESS);
        if (str[i + 1] == LABEL_CHAR)
            return (SUCCESS);
    }
    return (PROBLEM);
}

int is_indirect_cmd(char *str)
{
    int i = 0;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (my_str_isnum(str + i) == 0 || str[i] == LABEL_CHAR)
        return (SUCCESS);
    return (PROBLEM);
}