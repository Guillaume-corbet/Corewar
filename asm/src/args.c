/*
** EPITECH PROJECT, 2019
** args
** File description:
** corewar
*/

#include "../include/corewar.h"

int is_in_str(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (SUCCESS);
    }
    return (PROBLEM);
}

int check_args(char **action, char **tab, int *size)
{
    char **args;
    int i = 0;
    char *str;

    if (!action[1])
        return (PROBLEM);
    args = cut_str(action[1], SEPARATOR_CHAR);
    if (get_size_array(args) >= MAX_ARGS_NUMBER)
        return (PROBLEM);
    while (args[i]) {
        str = remove_comment(args[i]);
        if (is_register(str, size) != 0 &&
        is_direct(action[0], str, tab, size) != 0 &&
        is_indirect(str, tab, size) != 0 &&
        is_rule(str, tab, size) != 0) {
            destroy_array(args);
            return (PROBLEM);
        } i++;
        free(str);
    } destroy_array(args);
    return (SUCCESS);
}

int is_direct_byte(char *cmd, char *str)
{
    int i = 0;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i] == DIRECT_CHAR) {
        if (my_str_isnum(str + i + 1) == SUCCESS) {
            return (SUCCESS);
        }
        if (str[i + 1] == LABEL_CHAR) {
            return (SUCCESS);
        }
    }
    return (PROBLEM);
}

void args_byte(char *act, char **args, int fd)
{
    char *str = "";
    char *sto;
    char *wospaces;

    if (my_strncmp(act, "live", 4) == 0 || my_strncmp(act, "zjmp", 4) == 0
    || my_strncmp(act, "fork", 4) == 0 || my_strncmp(act, "lfork", 5) == 0)
        return;
    for (int i = 0; args[i]; i++) {
        wospaces = remove_comment(args[i]);
        if (is_register(wospaces, NULL) == SUCCESS)
            str = my_strcatf(str, "01");
        else if (is_direct_byte(act, wospaces) == SUCCESS)
            str = my_strcatf(str, "10");
        else
            str = my_strcatf(str, "11");
        free(wospaces);
    } while (my_strlen(str) % 8 != 0)
        str = my_strcatf(str, "0");
    set_nb_size(fd, binary(str), 1);
    free(str);
}

void other_assemb_cmd(t_st *src, char *sto)
{
    char **action = cut_line(sto);
    t_st *new = malloc(sizeof(t_st));

    new->fd = src->fd;
    new->tab = malloc(sizeof(char *) * (get_size_array(src->tab) + 1));
    for (int i = 0; src->tab[i]; i++)
        new->tab[i] = my_strdup(src->tab[i]);
    new->tab[get_size_array(src->tab)] = NULL;
    new->cur_i = src->cur_i;
    new->direct = check_direct(action[0]);
    new->size = malloc(sizeof(int) * get_size_array(src->tab));
    for (int i = 0; i < get_size_array(src->tab); i++)
        new->size[i] = src->size[i];
    new->i = 0;
    choose_op(action, NULL, new);
    destroy_array(action);
    destroy_array(new->tab);
    free(new->size);
    free(new);
}