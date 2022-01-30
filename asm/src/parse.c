/*
** EPITECH PROJECT, 2019
** parse
** File description:
** corewar
*/

#include "../include/corewar.h"

int check_line(char **tab, int *line_size, int i)
{
    char **action = cut_line(tab[i]);
    static int test = 0;

    if (my_strlen(tab[i]) == 0) {
        destroy_array(action);
        return (SUCCESS);
    }
    if (tab[i][my_strlen(tab[i]) - 1] == SEPARATOR_CHAR) {
        destroy_array(action);
        return (PROBLEM);
    }
    if (check_name(action, &test) != 0 &&
    (check_first_cmd(action[0], line_size) != 0 ||
    check_args(action, tab, line_size) != 0) &&
    check_empty_label(action, line_size) != 0) {
        destroy_array(action);
        return (PROBLEM);
    }
    destroy_array(action);
    return (SUCCESS);
}

int verif_pattern(char **tab, int *size, int **tab_int)
{
    int count = 0;
    int line_size = 0;
    int z = 0;
    int ret;

    for (int i = 0; tab[i]; i++) {
        ret = SUCCESS;
        if (check_comment(tab[i]) != SUCCESS)
            ret = check_line(tab, &line_size, i);
        if (ret == PROBLEM)
            return (PROBLEM);
        count = 0;
        (*size) = (*size) + line_size;
        (*tab_int)[z] = line_size;
        line_size = 0;
        z = z + 1;
    }
    return (SUCCESS);
}

void function_set_all(t_st *src, char *sto)
{
    int i = 0;
    int nb = 0;
    char *str = remove_comment(src->args[src->i]);

    if (is_register(str, NULL) == SUCCESS) {
        set_nb_size(src->fd, my_getnbr(str + 1), 1);
        i = 1;
    } else if (is_direct_cmd(str) == SUCCESS) {
        encode_direct(src, str);
        i = 2;
    }
    nb = i;
    if (nb == 0 && is_indirect_cmd(str) == SUCCESS)
        encode_indirect(src, str);
    else if (nb == 0 && check_assemb_cmd(str) == SUCCESS) {
        other_assemb_cmd(src, sto);
    }
    free(str);
}

void choose_op(char **action, char *name, t_st *src)
{
    int len = check_assemb_tab(action[0]);
    int direct = 0;

    src->args = NULL;
    if (len != -1)
        set_nb_size(src->fd, op_tab[len].code, 1);
    if (action[1]) {
        src->args = cut_str(action[1], SEPARATOR_CHAR);
        if (action[0][my_strlen(action[0]) - 1] != LABEL_CHAR)
            args_byte(action[0], src->args, src->fd);
        src->direct = check_direct(action[0]);
        while (src->args[src->i] != NULL) {
            function_set_all(src, action[1]);
            (src->i)++;
        }
        src->i = 0;
        destroy_array(src->args);
    }
}

int parse_champ(char *line, header_t *he, char *fic_name)
{
    t_st *src = create_struct(line);
    char *name = my_strcatf(recover_name(fic_name), ".cor");

    if (!he || verif_pattern(src->tab, &he->prog_size, &(src->size)) != 0) {
        destroy(src);
        return (PROBLEM);
    }
    he->prog_size = be32toh(he->prog_size);
    print_fic(he, name, src);
    destroy(src);
    free(name);
    return (SUCCESS);
}