/*
** EPITECH PROJECT, 2019
** encode
** File description:
** corewar
*/

#include "../include/corewar.h"

int calc_len(int i, int *size, int count, t_st *src)
{
    int nb = 0;

    if (i > count) {
        while (i != count && i > 0 && size[i]) {
            i--;
            nb += size[i];
        }
        set_nb_neg(src->fd, nb + 1, src->direct);
    } else if (i != -1) {
        while (i != count && size[i]) {
            nb += size[i];
            i++;
        }
        set_nb_size(src->fd, nb, src->direct);
    }
}

void encode_direct(t_st *src, char *str)
{
    int count = 0;
    int i = -1;

    if (my_str_isnum(str + 1) == SUCCESS)
        set_nb_size(src->fd, my_getnbr(str + 1), src->direct);
    else {
        while (src->tab[count] != NULL && (my_strncmp(src->tab[count],
        (str) + 2, my_strlen((str)) - 2) != 0
        || my_strlen(src->tab[count]) == 0))
            count++;
        if (src->tab[count]) {
            i = src->cur_i;
            calc_len(i, src->size, count, src);
        }
    }
}

int calc_ind(int i, int *size, int count, t_st *src)
{
    int nb = 0;

    if (i > count) {
        while (i != count) {
            i--;
            nb += size[i];
        }
        set_nb_neg(src->fd, nb + 1, IND_SIZE);
    } else {
        while (i != count) {
            nb += size[i];
            i++;
        }
        set_nb_size(src->fd, nb, IND_SIZE);
    }
}

void encode_indirect(t_st *src, char *str)
{
    int count = 0;
    int i = -1;

    if (my_str_isnum(str) == SUCCESS)
        set_nb_size(src->fd, my_getnbr(str), IND_SIZE);
    else {
        while (src->tab[count] && my_strncmp(src->tab[count],
        str + 1, my_strlen(str) - 1) != 0)
            count++;
        if (src->tab[count])
            i = src->cur_i;
        calc_ind(i, src->size, count, src);
    }
}