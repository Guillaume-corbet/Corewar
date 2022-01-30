/*
** EPITECH PROJECT, 2019
** fic
** File description:
** corewar
*/

#include "../include/corewar.h"

int print_fic(header_t *he, char *name, t_st *src)
{
    char **action;

    src->fd = open(name, O_WRONLY | O_TRUNC);
    if (src->fd == -1) {
        src->fd = open(name, O_CREAT | O_WRONLY, 0666);
        if (src->fd == -1)
            return (ERROR);
    }
    write(src->fd, he, sizeof(*he));
    for (int i = 0; src->tab[i]; i++) {
        if (check_comment(src->tab[i]) != 0 && my_strlen(src->tab[i]) > 0 &&
        is_name(src->tab[i]) != SUCCESS) {
            action = cut_line(src->tab[i]);
            src->cur_i = i;
            choose_op(action, name, src);
            destroy_array(action);
        }
    }
    return (SUCCESS);
}

char **cut_line(char *str)
{
    char **action = malloc(sizeof(char *) * 3);
    int count = 0;
    int size = 0;
    char *line = my_strdup(str);
    char *sto = line;

    while (line[count] && line[count] == ' ' || line[count] == '\t')
        line++;
    while (line[count] && line[count] != ' ' && line[count] != '\t')
        count++;
    if (line[count]) {
        while (line[count + size] && (line[count + size] == ' ' ||
        line[count + size] == '\t'))
            size++;
        action[1] = my_strdup((line) + count + size);
    } else
        action[1] = NULL;
    action[0] = my_strndup(line, count);
    action[2] = NULL;
    free(sto);
    return (action);
}