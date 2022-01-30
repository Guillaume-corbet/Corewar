/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** verif_header
*/

#include "../include/corewar.h"

int verif_all_second(char **stock_all)
{
    int i = 0;
    int count = 0;

    while (stock_all[i] != NULL) {
        if (my_strncmp(COMMENT_CMD_STRING, stock_all[i],
        my_strlen(COMMENT_CMD_STRING)) == 0 && my_strlen(stock_all[i]) > 0)
            count = count + 1;
        i = i + 1;
    }
    if (count > 1)
        return (84);
    return (0);
}

int verif_all(char **stock_all, int find)
{
    int i = 0;
    char *str;

    while (stock_all[i] != NULL) {
        str = my_strdup(stock_all[i]);
        free(stock_all[i]);
        stock_all[i] = remove_comment(str);
        free(str);
        if (i < find && stock_all[i][0] != COMMENT_CHAR &&
        my_strlen(stock_all[i]) > 0)
            return (84);
        i = i + 1;
    }
    if (verif_all_second(stock_all) == 84)
        return (84);
    return (0);
}