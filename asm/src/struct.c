/*
** EPITECH PROJECT, 2019
** struct
** File description:
** corewar
*/

#include "../include/corewar.h"

char *remove_comment(char *str)
{
    char *sto = my_strdup(str);
    char *addr = sto;
    char *res;
    int i = 0;

    while (sto[0] && (sto[0] == ' ' || sto[0] == '\t'))
        sto++;
    while (sto[i] && sto[i] != '#')
        i++;
    while (i > 0 && (sto[i - 1] == ' ' || sto[i - 1] == '\t'))
        i--;
    res = my_strndup(sto, i);
    free(addr);
    return (res);
}

t_st *create_struct(char *line)
{
    t_st *src = malloc(sizeof(t_st));
    char **tab = cut_str(line, '\n');

    src->tab = malloc(sizeof(char *) * (get_size_array(tab) + 1));
    for (int i = 0; tab[i]; i++)
        src->tab[i] = remove_comment(tab[i]);
    src->tab[get_size_array(tab)] = NULL;
    destroy_array(tab);
    src->size = malloc(sizeof(int) * get_size_array(src->tab));
    src->i = 0;
    return (src);
}

void destroy(t_st *src)
{
    free(src->size);
    destroy_array(src->tab);
    free(src);
}