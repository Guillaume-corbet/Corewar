/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "../include/corewar.h"

int main(int ac, char **av)
{
    header_t *he;
    char **stock_all;
    int ret = SUCCESS;
    char *str;

    if (ac < 2)
        return (ERROR);
    for (int i = 1; i < ac; i++) {
        str = read_fic(av[i]);
        if ((stock_all = cut_str(str, '\n')) == NULL)
            return (ERROR);
        if ((he = init_struct_header(stock_all)) == NULL)
            return (ERROR);
        if (parse_champ(str, he, av[i]) != SUCCESS)
            return (ERROR);
        destroy_array(stock_all);
        free(he);
        free(str);
    }
    return (ret);
}